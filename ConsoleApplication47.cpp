#include <iostream>

// Напишите программу на C++ для создания класса Rectangle с приватными переменными-членами для хранения длины и ширины. 
// Реализуйте функции-члены для вычисления площади и периметра прямоугольника.

class Rectangle {
	private:
		double width;
		double height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		double area() const {
			return width * height;
		}

		double perimeter() const {
			return 2 * (width + height);
		}
};

int main()
{
	Rectangle r(5, 2);
	std::cout << r.area() << std::endl;
	std::cout << r.perimeter() << std::endl;
}
