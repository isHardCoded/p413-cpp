#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
protected:
	std::string title;
	std::string author;
	std::string ISBN;
	bool available;

public:
	Book(const std::string& t, const std::string& a, const std::string& i)
		: title(t), author(a), ISBN(i), available(true) {
	}

	bool checkAvailability() const {
		return available;
	}

	void setAvailability(bool avail) {
		available = avail;
	}

	virtual std::string str() const {
		return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", available" + (available ? "Yes" : "No");
	}
};

class EBook : public Book {
private:
	std::string fileFormat;

public:
	EBook(const std::string& t, const std::string& a, const std::string& i, const std::string format)
		: Book(t, a, i), fileFormat(format) {
	}

	std::string getFileFormat() const {
		return fileFormat;
	}

	std::string str() const override {
		return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", Format: " + fileFormat + ", available" + (available ? "Yes" : "No");
	}
};

class PrintedBook : public Book {
private:
	int pageCount;

public:
	PrintedBook(
		const std::string& t,
		const std::string& a,
		const std::string& i,
		const std::string format,
		int pc) : Book(t, a, i), pageCount(pc) {
	}

	int getPageCount() const {
		return pageCount;
	}

	std::string str() const override {
		return "Book: " + title + ", author: " + author + ", ISBN: " + ISBN + ", Page count: " + std::to_string(pageCount) + ", available" + (available ? "Yes" : "No");
	}
};

class Reader {
private:
	std::string name;
	int reader_id;
	std::vector<Book*> borrowedBooks;

public:
	Reader(const std::string& n, int id) : name(n), reader_id(id) {}

	void borrowBook(Book* book) {
		if (book->checkAvailability()) {
			borrowedBooks.push_back(book);
			book->setAvailability(false);

			std::cout << name << " borrowed" << book->str() << std::endl;
		}

		else {
			throw "Book is not available";
		}
	}

	void returnBook(Book* book) {
		auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);

		if (it != borrowedBooks.end()) {
			Book* borrowedBook = *it;

			borrowedBook->setAvailability(true);
			borrowedBooks.erase(it);

			std::cout << name << " returned" << std::endl;
		}

		else {
			throw "Book not borrowed";
		}
	}

	std::string str() const {
		std::string result = "Reader: " + name + "\nBorrowed books:";

		if (borrowedBooks.empty()) result += "None";

		for (auto book : borrowedBooks) {
			result += "\n - " + book->str();
		}

		return result;
	}
};

class Librarian {
private:
	std::string name;
	int employee_id;

public:
	Librarian(const std::string& n, int id) : name(n), employee_id(id) {}

	void addBook(std::vector<Book*>& books, Book* book) {
		books.push_back(book);
		std::cout << "Librarian: " << name << " added book " << book->str() << std::endl;
	}

	void removeBook(std::vector<Book*>& books, Book* book) {
		auto it = find(books.begin(), books.end(), book);

		if (it != books.end()) {
			books.erase(it);
			std::cout << "Librarian " << name << " removed book: " << book->str() << std::endl;
		}

		else {
			throw "Book not found in library";
		}
	}

	std::string str() const {
		return "Librarian " + name;
	}
};

class Library {
private:
	std::vector<Book*> books;
	std::vector<Reader> readers;
	std::vector<Librarian> librarians;

public:
	void registerReader(const Reader& reader) {
		readers.push_back(reader);
		std::cout << "Registered reader: " << reader.str() << std::endl;
	}

	void addLibrarian(const Librarian& librarian) {
		librarians.push_back(librarian);
		std::cout << "Added librarian: " << librarian.str() << std::endl;
	}

	std::vector<Book*>& getBooks() {
		return books;
	}

	std::vector<Reader> getReaders() const {
		return readers;
	}

	std::vector<Librarian> getLibrarian() const {
		return librarians;
	}
};

int main() {
	try {
		Library library;
		Reader reader("John", 1);
		Reader reader2("Tom", 2);
		Librarian librarian("Bob", 1);
		Book* book = new Book("Book 1", "Author 1", "ISBN 1");
		library.registerReader(reader);
		library.addLibrarian(librarian);

		try {
			librarian.removeBook(library.getBooks(), book);
		}
		catch (const char* error) {
			std::cout << "Error: " << error << std::endl;
		}

		reader.borrowBook(book);

		try {
			reader2.borrowBook(book);
		}
		catch (const char* error) {
			std::cout << "Error: " << error << std::endl;
		}

		try {
			reader2.returnBook(book);
		}
		catch (const char* error) {
			std::cout << "Error: " << error << std::endl;
		}
	}
	catch (...) {
		std::cout << "Unknown error" << std::endl;
	}
}