#include <iostream>

class Employee {
	private:
		std::string name;
		int id;
		static int nextId;
		static int employeeCount;

	public:
		Employee(const std::string& employeeName) : name(employeeName) {
			id = nextId++;
			employeeCount++;
		}

		~Employee() {
			employeeCount--;
		}

		int getId() {
			return id;
		}

		std::string getName() {
			return name;
		}

		static int getEmployeeCount() {
			return employeeCount;
		}

		static void reset() {
			nextId = 1;
			employeeCount = 0;
		}
};

int Employee::nextId = 1;
int Employee::employeeCount = 0;

int main()
{
	std::cout << "Starting Employee count: " << Employee::getEmployeeCount() << std::endl;

	Employee e1("John");
	Employee e2("Tom");
	Employee e3("Sam");

	std::cout << "Employees created: " << std::endl;

	std::cout << e1.getName() << " with ID " << e1.getId() << std::endl;
	std::cout << e2.getName() << " with ID " << e2.getId() << std::endl;
	std::cout << e3.getName() << " with ID " << e3.getId() << std::endl;

	std::cout << "Current Employee count: " << Employee::getEmployeeCount() << std::endl;

	{
		Employee e4("Tim");
		std::cout << "New employee created: " << e4.getName() << std::endl;
		std::cout << "Employee count now: " << Employee::getEmployeeCount() << std::endl;
	}

	std::cout << "After destruct, employee count: " << Employee::getEmployeeCount() << std::endl;
	
	Employee::reset();
	std::cout << "After rest, employee count: " << Employee::getEmployeeCount() << std::endl;
}
