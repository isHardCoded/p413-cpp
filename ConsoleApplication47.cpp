#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Post {
	public:
		std::string id;
		std::string title;
		std::string content;

		Post() : id("0") {}
		Post(const std::string& title, const std::string& content) 
			: title(title), content(content), id("0") {
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
			p.id = j.value("id", "0");
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

void print_menu() {
	std::cout << "\nChoose an option\n"
		<< "1. Create post\n"
		<< "2. Read post\n"
		<< "3. Update post\n"
		<< "4. Delete post\n"
		<< "5. Exit\n"
		<< "Enter choice: ";
}

int main()
{
	PostService postService;
	int choice;

	do {
		print_menu();
		std::cin >> choice;

		if (choice == 1) {
			Post post;
			std::cout << "Enter title: ";
			std::cin >> post.title;
			std::cout << "Enter content: ";
			std::cin >> post.content;

			Post createdPost = postService.create_post(post);
			std::cout << "Created post:\n";
			createdPost.Show();
		}

		else if (choice == 2) {
			int id;
			std::cout << "Enter Post ID to read: ";
			std::cin >> id;

			Post readedPost = postService.get_post(id);
			std::cout << "Post:\n";
			readedPost.Show();
		}

		else if (choice == 3) {
			int id;
			std::cout << "Enter Post ID to read: ";
			std::cin >> id;

			Post newPost;
			std::cout << "Enter title: ";
			std::cin >> newPost.title;
			std::cout << "Enter content: ";
			std::cin >> newPost.content;

			Post updatedPost = postService.update_post(id, newPost);
			updatedPost.Show();
		}

		else if (choice == 4) {
			int id;
			std::cout << "Enter Post ID to delete: ";
			std::cin >> id;
			postService.delete_post(id);
		}

		else if (choice == 5) {
			std::cout << "Exiting...";
		}

		else {
			std::cout << "Invalid choice.";
		}

	} while (choice != 5);
}