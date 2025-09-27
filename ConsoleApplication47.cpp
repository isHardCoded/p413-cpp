#include <iostream>

class Product {
	private:
		std::string name;
		double priceUSD;
		static double exchangeRate;
	public:
		Product(const std::string& n, double price) : name(n), priceUSD(price) {}

		double getPrice() {
			return priceUSD * exchangeRate;
		}

		static void setExchangeRate(double rate) {
			exchangeRate = rate;
		}
};

double Product::exchangeRate = 75.3;

int main()
{
	Product p1("Phone", 800);
	Product p2("PC", 1100);

	Product::setExchangeRate(82.2);

	std::cout << p1.getPrice() << std::endl;
	std::cout << p2.getPrice() << std::endl;

}