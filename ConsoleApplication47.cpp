#include <iostream>

class Device {
	public:
		int serial_number = 1010;

		void turn_on() {
			std::cout << "Device is turn on\n";
		}
};

class Phone : public Device {};

int main()
{
	Phone phone;
	
	std::cout << phone.serial_number << std::endl;
	phone.turn_on();

}
