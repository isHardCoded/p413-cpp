#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

// Напишите программу на C++ для реализации класса Circle с приватными переменными-членами для хранения радиуса.
// Включите функции-члены для вычисления площади и длины окружности.

class Circle {
	private:
		double radius;
		double PI = 3.14;

	public:
		Circle(double r) : radius(r) {}

		double area() const {
			return PI * radius * radius;
		}

		double circumference() const {
			return 2 * PI * radius;
		}
};

int main()
{
	Circle c(5);
	std::cout << c.area() << std::endl;
	std::cout << c.circumference() << std::endl;
}
