#include <iostream>

// cast

// static_cast
// const_cast
// dynamic_cast
// reinterpret_cast

class MyClass {
	int value;
	int a;

public:
	void setValue(int v) { value = v; }
	void printValue() const {
		std::cout << value;
		const_cast<MyClass*>(this)->value = 100;
		std::cout << value;
	}
};

int main()
{
	MyClass obj;
	obj.setValue(5);
	obj.printValue();

	int a = 5;
	int b = 7;
	double res = static_cast<double>(a) / b;
}
