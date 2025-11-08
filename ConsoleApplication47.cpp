#include <iostream>
#include <string>
#include <unordered_map>

class CurrencyConverter {
	private:
		std::unordered_map<std::string, double> rates{
			{"USD", 1.0},
			{"EUR", 1.1},
			{"RUB", 0.013}
		};

	public:
		double convert(double amount, const std::string& from, const std::string& to) const
		{
			// 1 EUR = 1.1 USD
			// 1 RUB = 0.013 USD

			// 100 RUB * 0.013 = USB / RUB = 1.3 USD
			// USD / EUR = 1.3 / 1.1 = 1.18
			double amountInUSD = amount / rates.at(from);
			return amountInUSD * rates.at(to);
		}
};

class Money {
	private:
		double amount;
		std::string currency;
		static CurrencyConverter converter;

	public:
		Money(double amt, std::string curr) : amount(amt), currency(curr) {}

		Money operator+(const Money& rhs) const {
			if (currency == rhs.currency) {
				return Money(amount + rhs.amount, currency);
			}
			else {
				double converted = converter.convert(rhs.amount, rhs.currency, currency);
				return Money(amount + converted, currency);
			}
		}

		Money operator-(const Money& rhs) const {
			if (currency == rhs.currency) {
				return Money(amount - rhs.amount, currency);
			}
			else {
				double converted = converter.convert(rhs.amount, rhs.currency, currency);
				return Money(amount - converted, currency);
			}
		}

		void print() const {
			std::cout << amount << " " << currency;
		}
};

CurrencyConverter Money::converter;

int main()
{
	Money salary(1000, "USD");
	Money bonus(900, "EUR");

	Money total = salary + bonus;
	total.print();
};
