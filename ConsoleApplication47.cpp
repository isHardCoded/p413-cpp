#include <iostream>

class User {
	private:	
		std::string name;

	public:
		User(const std::string& n) : name(n) {
			std::cout << "Object created" << std::endl;
		}

		User(const User& other) {
			name = other.name;
			std::cout << "Object copied" << std::endl;
		}

		std::string getName() {
			return name;
		}
};

int main()
{
	User user1("John");
	User user2 = user1;

	std::cout << user1.getName() << std::endl;
	std::cout << user2.getName() << std::endl;
}
