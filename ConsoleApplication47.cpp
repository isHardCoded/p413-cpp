#include <iostream>

// explicit
class Fraction {
	private:
		int numerator; // числитель
		int denominator; // знаменатель

	public:
		explicit Fraction(int number) : numerator(number), denominator(1) {}
		void print() const {
			std::cout << numerator << "/" << denominator << std::endl;
		}
};

void printFraction(const Fraction& frac) {
	frac.print();
}

int main()
{
	// Fraction f = 'B'; Ошибка: неявное преобразование запрещено 
	Fraction f(5); // Явное создание объекта - ОК
	// printFraction(10); Ошибка: неявное преобразование запрещено 
	printFraction(Fraction(10)); // Явное создание объекта - ОК
}
