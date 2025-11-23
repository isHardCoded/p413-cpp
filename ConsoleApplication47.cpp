#include <iostream>
#include <vector>

class Transport {
	public:
		virtual double calculateTime(double distance) const = 0;
		virtual double calculateCost(double distance) const = 0;
		virtual void Print() const = 0;
};

class Car : public Transport {
	private:
		double speed;
		double costPerKm;

	public:
		Car(double speed, double costPerKm) : speed(speed), costPerKm(costPerKm) {}

		double calculateTime(double distance) const override {
			return distance / speed;
		}

		double calculateCost(double distance) const override {
			return distance * costPerKm;
		}

		void Print() const override {
			std::cout << "Transport: Car" << std::endl;
		}
};

class Bicycle : public Transport {
private:
	double speed;
	double costPerKm;

public:
	Bicycle(double speed, double costPerKm) : speed(speed), costPerKm(costPerKm) {}

	double calculateTime(double distance) const override {
		return distance / speed;
	}

	double calculateCost(double distance) const override {
		return distance * costPerKm;
	}

	void Print() const override {
		std::cout << "Transport: Bicycle" << std::endl;
	}
};

class Cart : public Transport {
private:
	double speed;
	double costPerKm;

public:
	Cart(double speed, double costPerKm) : speed(speed), costPerKm(costPerKm) {}

	double calculateTime(double distance) const override {
		return distance / speed;
	}

	double calculateCost(double distance) const override {
		return distance * costPerKm;
	}

	void Print() const override {
		std::cout << "Transport: Cart" << std::endl;
	}
};

int main()
{
	double distance = 100.0;

	Car car(80.0, 0.5);
	Bicycle bicycle(20.0, 0.3);
	Cart cart(15.0, 0.1);

	std::vector<Transport*> transports = { &car, &bicycle, &cart };

	for (const auto& transport : transports) {
		transport->Print();

		std::cout << "Time: " << transport->calculateTime(distance) << std::endl;
		std::cout << "Cost: " << transport->calculateCost(distance) << std::endl;
	}
}
