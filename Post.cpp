#include "Post.h"
#include <iostream>
#include <nlohmann/json.hpp>

class Post {
public:
	std::string id;
	std::string title;
	std::string content;

	Post() : id("0") {}
	Post(const std::string& title, const std::string& content)
		: title(title), content(content), id("0") {
	}

	nlohmann::json to_json() const {
		nlohmann::json j;
		j["id"] = id;
		j["title"] = title;
		j["content"] = content;
		return j;
	}

	static Post from_json(const nlohmann::json& j) {
		Post p;
		p.id = j.value("id", "0");
		p.title = j.value("title", "");
		p.content = j.value("content", "");
		return p;
	}

	void Show() const {
		std::cout << "Post ID: " << id << "\nTitle: " << title << "\nContent: " << content;
	}
};