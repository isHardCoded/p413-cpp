#include <iostream>

class Device {
	public:
		int serial_number = 1010;

		void turn_on() {
			std::cout << "Device is turn on\n";
		}

		virtual void identify() {
			std::cout << "I am device";
		}
};

class Phone : public Device {
	public:
		int ram_size = 16;

		void identify() override {
			std::cout << "I am phone with " << ram_size << "GB RAM\n";
		}
};

class Computer : public Device {
	public:
		void identify() override {
			std::cout << "I am computer";
		}
};

int main()
{
	Phone phone;
	
	std::cout << phone.serial_number << std::endl;
	phone.turn_on();
	phone.identify();

}
