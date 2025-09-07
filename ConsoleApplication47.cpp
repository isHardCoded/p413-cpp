#include <iostream>

// Напишите программу на C++ для создания класса Person с приватными переменными-членами для имени, возраста и страны. 
// Реализуйте функции-члены для установки и получения значений этих переменных.

class Person {
	private:
		std::string name;
		int age;
		std::string country;

	public:
		int getAge() const {
			return age;
		}

		void setAge(int a) {
			age = a;
		}

		std::string getName() const {
			return name;
		}

		void setName(const std::string& n) {
			name = n;
		}

		std::string getCountry() const {
			return country;
		}

		void setCountry(const std::string& c) {
			country = c;
		}


};

int main()
{
	Person n;

	n.setName("John");
	n.setAge(20);
	n.setCountry("Russia");

	std::cout << n.getName() << ", " << n.getAge() << ", " << n.getCountry() << std::endl;
}
