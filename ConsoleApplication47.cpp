#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Post {
	public:
		int id;
		std::string title;
		std::string content;

		Post() : id(0) {}
		Post(const std::string& title, const std::string& content) 
			: title(title), content(content), id(0) {
		}

		json to_json() const {
			json j;
			j["id"] = id;
			j["title"] = title;
			j["content"] = content;
			return j;
		}

		static Post from_json(const json& j) {
			Post p;
			p.id = j.value("id", 0);
			p.title = j.value("title", "");
			p.content = j.value("content", "");
			return p;
		}

		void Show() const {
			std::cout << "Post ID: " << id << "\nTitle: " << title << "\nContent: " << content;
		}
};

class PostService {
	private:
		std::string base_url = "https://6764432352b2a7619f5bfef7.mockapi.io/posts";
	public:
		Post create_post(const Post& post) {
			cpr::Response response = cpr::Post(
				cpr::Url{ base_url },
				cpr::Body{ post.to_json().dump() },
				cpr::Header{ {"Content-Type", "application/json"} }
			);
			json j = json::parse(response.text);
			return Post::from_json(j);
		}

		Post get_post(int id) {
			cpr::Response response = cpr::Get(cpr::Url{ base_url + "/" + std::to_string(id) });
			json j = json::parse(response.text);
			return Post::from_json(j);
		}

		Post update_post(int id, const Post& post) {
			cpr::Response response = cpr::Put(
				cpr::Url{ base_url + "/" + std::to_string(id) },
				cpr::Body{ post.to_json().dump() },
				cpr::Header{ {"Content-Type", "application/json"} }
			);
			json j = json::parse(response.text);
			return Post::from_json(j);
		}

		void delete_post(int id) {
			cpr::Response response = cpr::Delete(cpr::Url{ base_url + "/" + std::to_string(id) });
			if (response.status_code == 200 || response.status_code == 204) {
				std::cout << "Post deleted!" << std::endl;
			}
			else {
				std::cout << "Error" << std::endl;
			}
		}
};

int main()
{
	PostService postService;

	Post p("My Post", "Text post");
	postService.create_post(p).Show();
	postService.get_post(4).Show();

	//Post p_updated("My Post UPDATED", "Text post UPDATED");
	//postService.update_post(p_updated.id, p_updated).Show();

	/*postService.delete_post(p_updated.id);*/
}