#include <iostream>

// Напишите программу на C++ для создания класса Car с приватными переменными-членами для хранения данных о компании, модели и годе выпуска. 
// Реализуйте функции-члены для получения и установки этих переменных.

class Car {
	private:
		std::string model;
		std::string company;
		int year;

	public:
		int getYear() const {
			return year;
		}

		void setYear(int y) {
			year = y;
		}

		std::string getCompany() const {
			return company;
		}

		void setCompany(const std::string c) {
			company = c;
		}

		std::string getModel() const {
			return model;
		}

		void setModel(const std::string m) {
			model = m;
		}
};

int main()
{
	Car c;
	c.setCompany("Toyota");
	c.setModel("Camry");
	c.setYear(2022);

	std::cout << c.getCompany() << ", " << c.getModel() << ", " << c.getYear() << std::endl;
}
