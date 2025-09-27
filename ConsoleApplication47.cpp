#include <iostream>

class Circle {
private:
	double radius;
	static double scale;
public:
	Circle(double r) : radius(r) {}

	double area() const {
		return 3.14 * radius * radius * scale;
	}

	static double getScale() {
		return scale;
	}

	static void setScale(double value) {
		scale = value;
	}
};

double Circle::scale = 1.0;

int main()
{
	Circle c1(1);
	Circle c2(2);
	Circle c3(3);

	std::cout << Circle::getScale() << std::endl;
	std::cout << c1.area() << std::endl;
	std::cout << c2.area() << std::endl;
	std::cout << c3.area() << std::endl;

	std::cout << std::endl;
	Circle::setScale(2.0);

	std::cout << Circle::getScale() << std::endl;
	std::cout << c1.area() << std::endl;
	std::cout << c2.area() << std::endl;
	std::cout << c3.area() << std::endl;
}