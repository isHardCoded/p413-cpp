#include <iostream>

class Book {
	private:
		std::string author;
		std::string name;
		std::string publisher;
		int year;
		int pagesCount;

	public:
		explicit Book(const std::string& author, const std::string& name, const std::string& publisher, int year, int pagesCount) {
			this->author = author;
			this->name = name;
			this->publisher = publisher;
			this->year = year;
			this->pagesCount = pagesCount;
		}

		const std::string& getAuthor() const {
			return author;
		}

		const int getYear() const {
			return year;
		}

		const std::string& getPublisher() const {
			return publisher;
		}

		static void showBooksToAuthor(const Book books[], int size, const std::string& author) {
			for (int i = 0; i < size; i++) {
				if (books[i].getAuthor() == author) {
					books[i].showBook();
				}
			}
		}

		static void showBooksToPublisher(const Book books[], int size, const std::string& publisher) {
			for (int i = 0; i < size; i++) {
				if (books[i].getPublisher() == publisher) {
					books[i].showBook();
				}
			}
		}

		static void showBooksToYear(const Book books[], int size, int year) {
			for (int i = 0; i < size; i++) {
				if (books[i].getYear() == year) {
					books[i].showBook();
				}
			}
		}

		void showBook() const {
			std::cout << author << " " << name << " " << publisher << " " << year << " " << pagesCount << std::endl;
		}
};

int main()
{
	Book book1("John", "Book 1", "Publisher 1", 2025, 200);
	Book book2("John", "Book 2", "Publisher 2", 2015, 500);
	Book book3("John", "Book 3", "Publisher 3", 2015, 400);

	Book book4("Tom", "Book 4", "Publisher 4", 2013, 700);
	Book book5("Tim", "Book 5", "Publisher 4", 2017, 100);
	Book book6("Tim", "Book 6", "Publisher 5", 2018, 50);

	Book books[6] = { book1, book2, book3, book4, book5, book6 };

	Book::showBooksToAuthor(books, 6, "Tom");
	std::cout << std::endl;
	Book::showBooksToPublisher(books, 6, "Publisher 4");
	std::cout << std::endl;
	Book::showBooksToYear(books, 6, 2015);
}
