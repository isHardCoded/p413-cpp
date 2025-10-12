#pragma once
#include "Post.h"

class PostService {
private:
	std::string base_url = "https://6764432352b2a7619f5bfef7.mockapi.io/posts";
public:
	Post create_post(const Post& post);

	Post get_post(int id);

	Post update_post(int id, const Post& post);

	void delete_post(int id);
};
