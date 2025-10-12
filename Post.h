#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Post {
public:
	std::string id;
	std::string title;
	std::string content;

	Post();
	Post(const std::string& title, const std::string& content);

	nlohmann::json to_json() const;

	static Post from_json(const nlohmann::json& j);

	void Show() const;
};
