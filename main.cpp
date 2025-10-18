#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <typeinfo>

using json = nlohmann::json;

int main()
{
	std::string firstCurrency;
	std::string secondCurrency;

	std::cout << "Enter first currency: ";
	std::cin >> firstCurrency;

	std::cout << "Enter second currency: ";
	std::cin >> secondCurrency;

	std::string apiKey = "8a991d8624046f4421474b3c55539013";
	std::string url = "https://currate.ru/api/?get=rates&pairs=" + firstCurrency + secondCurrency + "&key=" + apiKey;

	cpr::Response response = cpr::Get(cpr::Url{ url });

	if (response.status_code == 200) {
		json j = json::parse(response.text);
		std::cout << j["data"].value(firstCurrency + secondCurrency, "0") << std::endl;
	}
	else {
		std::cout << "Error: " << response.status_code;
	}
}