#include <iostream>

class Device {
	protected:
		std::string brand;

	public:
		Device(const std::string& brand) {
			this->brand = brand;
		}

		virtual void show() {
			std::cout << "Device brand: " << brand << std::endl;
		}
};

class Computer : public Device {
	protected:
		int ram;

	public:
		Computer(const std::string& b, int r) : Device(b), ram(r) {}

		void show() override {
			std::cout << "Computer brand: " << brand << std::endl;
			std::cout << "RAM: " << ram << std::endl;
		}
};

class Phone : public Device {
	protected:
		std::string phone_number;

	public:
		Phone(const std::string& phone, const std::string& b) 
			: Device(b), phone_number(phone) {}

		void show() override {
			std::cout << "Phone brand: " << brand << std::endl;
			std::cout << "Phone number: " << phone_number << std::endl;
		}
};

class Smartphone : public Computer, public Phone {
	public:
		Smartphone(const std::string& b, int r, const std::string& phone)
			: Computer(b, r), Phone(phone, b) {}
};

int main()
{
	Computer computer("Samsung", 16);
}
