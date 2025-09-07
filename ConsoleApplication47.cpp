#include <iostream>

// Напишите программу на C++ для реализации класса BankAccount с приватными переменными-членами для номера счёта и баланса. 
// Включите функции-члены для пополнения и снятия денег со счёта.

class BankAccount {
private:
	int number;
	double balance;

public: 
	BankAccount() {
		this->number = 111111;
		this->balance = 0;
	}

	int getNumber() const {
		return number;
	}

	int getBalance() const {
		return balance;
	}

	void deposit(double amount) {
		if (amount > 0) balance += amount;
	}

	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) balance -= amount;
	}
};

int main()
{
	BankAccount account;

	account.deposit(500);
	account.withdraw(250);

	std::cout << account.getBalance() << std::endl;
}
