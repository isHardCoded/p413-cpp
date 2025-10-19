#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <typeinfo>

using json = nlohmann::json;

class NewsItem {
private:
	std::string title;
	std::string description;
	std::string author;
	std::string published;

public:
	NewsItem(
		const std::string& t, 
		const std::string& desc, 
		const std::string& a,
		const std::string& p
	) : title(t), description(desc), author(a), published(p)  {}

	void PrintNewsItem() {
		std::cout << "Title: " << title << std::endl;
		std::cout << "Description: " << description << std::endl;
		std::cout << "Author: " << author << std::endl;
		std::cout << "Published: " << published << std::endl;
	}
};

void PrintMenu() {
	std::cout << "1. Get news list" << "\n";
	std::cout << "2. Search news by keyword" << "\n";
	std::cout << "3. Exit" << "\n";
}

int main()
{

	int choose;
	do {
		PrintMenu();
		std::cout << "Enter choose: ";
		std::cin >> choose;

		if (choose == 1) {
			std::string apiKey = "nZHQT0Wknk12H1OJemjk-4F7-d3AX9Zpljd7zx9EFf14dsGf";
			std::string url = "https://api.currentsapi.services/v1/latest-news?apiKey=" + apiKey;

			cpr::Response response = cpr::Get(cpr::Url{ url });

			if (response.status_code == 200) {
				json j = json::parse(response.text);

				std::cout << "News" << std::endl;

				for (auto post : j["news"]) {
					std::cout << "Title: " << post["title"] << std::endl;
					std::cout << "Description: " << post["description"] << std::endl;
					std::cout << "Author: " << post["author"] << std::endl;
					std::cout << "Published: " << post["published"] << std::endl;

					std::cout << "Category: ";
					for (auto category : post["category"]) {
						std::cout << category << " ";
					}

					std::cout << std::endl;
				}
			}
			else {
				std::cout << "Error: " << response.status_code << std::endl;
			}
		}
		else if(choose == 2) {

		}
		else {
			std::cout << "Incorrect choose";
		}
	} while (choose != 3);

	
}