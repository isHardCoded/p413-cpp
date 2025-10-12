#include <iostream>
#include "PostService.h"

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