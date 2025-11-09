#include <iostream>

int main()
{
	try {
		float a, b;

		std::cout << "Put digit a: ";
		std::cin >> a;

		std::cout << "Put digit b: ";
		std::cin >> b;

		if (b == 0) {
			throw b;
		}

		std::cout << "Result = " << (a / b) << std::endl;
	}
	catch (float error) {
		std::cout << "Error - Divide by " << error << std::endl;
	}
}
