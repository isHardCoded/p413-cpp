#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Auth {
	private:
		std::string username;
		std::string email;
		std::string password;

		std::string message;
		std::string error;
		std::string token;

	public:
		Auth() : message(""), error(""), token("") {}
		Auth(
			const std::string& username, 
			const std::string& email, 
			const std::string& password
		) {
			this->username = username;
			this->email = email;
			this->password = password;
		}

		json RegisterSerialize() const {
			json j;
			j["username"] = username;
			j["email"] = email;
			j["password"] = password;
			return j;
		}

		json LoginSerialize() const {
			json j;
			j["email"] = email;
			j["password"] = password;
			return j;
		}

		Auth RegisterDeserialize(const json& j) {
			Auth auth;
			auth.message = j.value("message", "");
			auth.error = j.value("error", "");
			return auth;
		}
		
		Auth LoginDeserialize(const json& j) {
			Auth auth;
			auth.message = j.value("message", "");
			auth.token = j.value("token", "");
			auth.error = j.value("error", "");
			return auth;
		}

		std::string getMessage() const {
			return message;
		}

		std::string getToken() const {
			return token;
		}
};

int main()
{
	std::string username;
	std::string email;
	std::string password;

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Enter password: ";
	std::cin >> password;

	Auth auth(username, email, password);

	cpr::Response response = cpr::Post
	(
		cpr::Url{ "http://localhost:8080/register" },
		cpr::Header{ { "Content-Type", "application/json"} },
		cpr::Body{ auth.RegisterSerialize().dump()}
	); 

	std::cout << auth.RegisterDeserialize(json::parse(response.text)).getMessage() << std::endl;

	cpr::Response response1 = cpr::Post
	(
		cpr::Url{ "http://localhost:8080/login" },
		cpr::Header{ { "Content-Type", "application/json"} },
		cpr::Body{ auth.LoginSerialize().dump() }
	);

	std::cout << auth.LoginDeserialize(json::parse(response1.text)).getToken() << std::endl;

	cpr::Response response2 = cpr::Get
	(
		cpr::Url {"http://localhost:8080/profile"},
		cpr::Header{ { "Authorization", "Bearer " + auth.LoginDeserialize(json::parse(response1.text)).getToken() } }
	);

	std::cout << "Status code: " << response2.status_code << std::endl;
	std::cout << "Body: " << response2.text << std::endl;
}