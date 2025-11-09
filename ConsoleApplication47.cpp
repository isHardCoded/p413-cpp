#include <iostream>

int main()
{
	try {
		int* ptr = nullptr;
		int size;

		std::cout << "Put size: ";
		std::cin >> size;

		if (size < 1 || size > 500) {
			throw "Incorrect size";
		}

		ptr = new int[size];

		if (!ptr) {
			throw "Error memory";
		}
	}

	catch (char* error) {
		std::cout << error << std::endl;
	}

	catch (...) {
		std::cout << "Unknown error!" << std::endl;
	}
}
