#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
	std::string apiKey = "c78f11918a7b4ce3b95192241252808";
	std::string city;
	std::cout << "Enter city: ";
	std::cin >> city;
	std::string url = "http://api.weatherapi.com/v1/current.json?key=" + apiKey + "&q=" + city;

	cpr::Response response = cpr::Get(cpr::Url{ url });

	if (response.status_code == 200) {
		json j = json::parse(response.text);
		std::cout << "Weather in " << city << std::endl;
		std::cout << "Temp: " << j["current"]["temp_c"] << "°C" << std::endl;
		std::cout << "Condition: " << j["current"]["condition"]["text"] << std::endl;
		std::cout << "Humidity: " << j["current"]["humidity"] << " %" << std::endl;
		std::cout << "Wind speed: " << j["current"]["wind_kph"] << " km/h" << std::endl;
	}
	else {
		std::cout << response.status_code;
		std::cout << response.text;
	}
}