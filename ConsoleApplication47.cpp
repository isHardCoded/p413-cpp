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

		void print() const {
			if (data) std::cout << data << std::endl;
			else std::cout << "null" << std::endl;
		}

		// 
};


int main()
{
	String s("Hello");
	String s2 = s;
	s.print();
	s2.print();
}
