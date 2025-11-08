#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class String {
	private:
		char* data;

	public:
		String(const char* str) {
			if (str) {
				data = new char[strlen(str) + 1];
				strcpy(data, str);
			}
			else {
				data = nullptr;
			}
		}

		String(const String& other) {
			if (other.data) {
				data = new char[strlen(other.data) + 1];
				strcpy(data, other.data);
			}
			else {
				data = nullptr;
			}
			std::cout << "Object copied" << std::endl;
		}

		void print() const {
			if (data) std::cout << data << std::endl;
			else std::cout << "null" << std::endl;
		}

		~String() {
			delete[] data;
		}
};

int main()
{
	String s("Hello");
	String s2 = s;
	s2.print();
	s.print();
}
