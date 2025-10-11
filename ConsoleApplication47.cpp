#include <iostream>
#include <cpr/cpr.h>

using namespace std;

class HttpClient {
	public:
		virtual cpr::Response get(const string& url) = 0;
		virtual cpr::Response post(const string& url, const string& body, const cpr::Header& headers) = 0;
};

class UserClient : public HttpClient {
	private:
		string BASE_URL;

	public:
		UserClient(const string& url) : BASE_URL(url) {}

		cpr::Response get(const string& url) override {
			return cpr::Get(cpr::Url{ url });
		}

		cpr::Response post(const string& url, const string& body, const cpr::Header& headers) override {
			return cpr::Post(cpr::Url{ url }, cpr::Body{ body }, headers);
		}

		cpr::Response getUsers() {
			return get(BASE_URL + "/users");
		}
};

int main()
{
	UserClient client("https://6764432352b2a7619f5bfef7.mockapi.io");

	cpr::Response response = client.getUsers();
	std::cout << "GET status: " << response.status_code << std::endl;
	std::cout << "GET body: " << response.text << std::endl;
}