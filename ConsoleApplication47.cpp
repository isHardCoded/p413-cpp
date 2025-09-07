#include <iostream>

class Shape {
	public:
		virtual double area() const = 0;
		virtual double perimeter() const = 0;
};

class Circle : public Shape {
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {};

		double area() const override {
			return 3.14 * radius * radius;
		}

		double perimeter() const override {
			return 2 * 3.14 * radius;
		}
};

class Rectangle : public Shape {
	private:
		double width;
		double height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		double area() const override {
			return width * height;
		}

		double perimeter() const override {
			return 2 * (width + height);
		}
};

class Triangle : public Shape {
	private:
		double a, b, c, h;

	public:
		Triangle(double a, double b, double c, double h) {
			this->a = a;
			this->b = b;
			this->c = c;
			this->h = h;
		}

		double area() const override {
			return b * h / 2;
		}

		double perimeter() const override {
			return a + b + c;
		}
};

int main()
{
	Shape* shapes[] = { new Circle(5), new Rectangle(2, 2), new Triangle(3, 4, 5, 5) };

	for (auto shape : shapes) {
		std::cout << "Area: " << shape->area() << std::endl;
		std::cout << "Perimeter: " << shape->perimeter() << std::endl;
	}
}
