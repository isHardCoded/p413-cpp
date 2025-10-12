#include <string>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <iostream>
#include "PostService.h"

using json = nlohmann::json;

class PostService {
private:
	std::string base_url = "https://6764432352b2a7619f5bfef7.mockapi.io/posts";
public:
	Post create_post(const Post& post) {
		std::cout << "Loading..." << std::endl;
		cpr::Response response = cpr::Post(
			cpr::Url{ base_url },
			cpr::Body{ post.to_json().dump() },
			cpr::Header{ {"Content-Type", "application/json"} }
		);
		json j = json::parse(response.text);
		return Post::from_json(j);
	}

	Post get_post(int id) {
		std::cout << "Loading..." << std::endl;
		cpr::Response response = cpr::Get(cpr::Url{ base_url + "/" + std::to_string(id) });
		json j = json::parse(response.text);
		return Post::from_json(j);
	}

	Post update_post(int id, const Post& post) {
		std::cout << "Loading..." << std::endl;
		cpr::Response response = cpr::Put(
			cpr::Url{ base_url + "/" + std::to_string(id) },
			cpr::Body{ post.to_json().dump() },
			cpr::Header{ {"Content-Type", "application/json"} }
		);
		json j = json::parse(response.text);
		return Post::from_json(j);
	}

	void delete_post(int id) {
		std::cout << "Loading..." << std::endl;
		cpr::Response response = cpr::Delete(cpr::Url{ base_url + "/" + std::to_string(id) });
		if (response.status_code == 200 || response.status_code == 204) {
			std::cout << "Post deleted!" << std::endl;
		}
		else {
			std::cout << "Error" << std::endl;
		}
	}
};
