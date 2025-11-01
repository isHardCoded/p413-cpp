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

		static Auth RegisterDeserialize(const json& j) {
			Auth auth;
			auth.message = j.value("message", "");
			auth.error = j.value("error", "");
			return auth;
		}
		
		static Auth LoginDeserialize(const json& j) {
			Auth auth;
			auth.message = j.value("message", "");
			auth.token = j.value("token", "");
			auth.error = j.value("error", "");
			return auth;
		}

		std::string getMessage() const {
			return message;
		}

		std::string getError() const {
			return error;
		}

		std::string getToken() const {
			return token;
		}
};

class User {
	private:
		int id;
		std::string username;
		std::string email;

	public:
		User() : id(0), username(""), email("") {}

		User(
			int id, 
			const std::string& username,
			const std::string& email
		) {
			this->id = id;
			this->username = username;
			this->email = email;
		}

		static User fromJson(const json& j) {
			User user;
			user.id = j.value("id", 0);
			user.username = j.value("username", "");
			user.email = j.value("email", "");
			return user;
		}

		void print() {
			std::cout << "User: " << id << " " << username << " " << email << std::endl;;
		}
};

class AuthService {
	private:
		std::string BASE_URL = "http://localhost:8080/api/auth";

	public:
		std::string create(const Auth& auth) {
			cpr::Response response = cpr::Post(
				cpr::Url{ BASE_URL + "/register" },
				cpr::Header{ { "Content-Type", "application/json" } },
				cpr::Body{ auth.RegisterSerialize().dump() }
			);

			if (response.status_code == 201) {
				return Auth::RegisterDeserialize(json::parse(response.text)).getMessage();
			}
			else {
				return Auth::RegisterDeserialize(json::parse(response.text)).getError();
			}
		}

		std::string login(const Auth& auth) {
			cpr::Response response = cpr::Post(
				cpr::Url{ BASE_URL + "/login" },
				cpr::Header{ { "Content-Type", "application/json" } },
				cpr::Body{ auth.LoginSerialize().dump() }
			);

			if (response.status_code == 200) {
				return Auth::LoginDeserialize(json::parse(response.text)).getMessage();
			}
			else {
				return Auth::LoginDeserialize(json::parse(response.text)).getError();
			}
		}
};

class UserService {
	private:
		std::string BASE_URL = "http://localhost:8080/api/users";

	public:
		std::vector<User> getUsers() {
			std::vector<User> users;
			cpr::Response response = cpr::Get(
				cpr::Url{ BASE_URL }
			);

			for (const auto& item : json::parse(response.text)) {
				users.push_back(User::fromJson(item));
			}

			return users;
		}
};

int main()
{
	AuthService authService;
	UserService userService;
	
	int choice;

	do {
		std::cout << "1. Register Account" << std::endl;
		std::cout << "2. Login in Account" << std::endl;
		std::cout << "3. Show all users" << std::endl;

		std::cin >> choice;

		if (choice == 1) {
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
			std::cout << authService.create(auth) << std::endl;
		}

		else if (choice == 2) {
			std::string username;
			std::string email;
			std::string password;

			std::cout << "Enter email: ";
			std::cin >> email;
			std::cout << "Enter password: ";
			std::cin >> password;

			Auth auth(username, email, password);

			std::cout << authService.login(auth) << std::endl;
		}
		
		else if (choice == 3) {
			for (User user : userService.getUsers()) {
				user.print();
			}
		}
	} while (choice != 5);
}