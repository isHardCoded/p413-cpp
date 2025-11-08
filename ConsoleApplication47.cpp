#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Book {
	char* title;
	int pages;

public:
	Book(const char* t, int p) : pages(p) {
		title = new char[strlen(t) + 1];
		strcpy(title, t);
		std::cout << "Object created" << std::endl;
	}

	Book(const Book& other) : pages(other.pages) {
		if (other.title) {
			title = new char[strlen(other.title) + 1];
			strcpy(title, other.title);
		}
		else {
			title = nullptr;
		}
		std::cout << "Object copied" << std::endl;
	}

	void print() const {
		std::cout << "Book: " << title << ", Pages: " << pages << std::endl;
	}

	~Book() {
		delete[] title;
		std::cout << "Object deleted" << std::endl;
	}
};

int main()
{
	Book book1("Book 1", 20);
	Book book2 = book1;

	book1.print();
	book2.print();
}
