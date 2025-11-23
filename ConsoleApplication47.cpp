#include <iostream>

class Student {
	protected:
		std::string name;
		int age;
		std::string group;

	public:
		Student(const std::string& name, int age, const std::string& group)
			: name(name), age(age), group(group) {}

		virtual void Print() const {
			std::cout << "Student: " << name << std::endl;
			std::cout << "Age: " << age << std::endl;
			std::cout << "Group: " << group << std::endl;
		}
};

class Aspirant : public Student {
	private:
		std::string workId;

	public:
		Aspirant(const std::string& name, int age, const std::string& group, const std::string& workId)
			: Student(name, age, group), workId(workId) {}

		void Print() const override {
			std::cout << "Aspirant: " << name << std::endl;
			std::cout << "Age: " << age << std::endl;
			std::cout << "Group: " << group << std::endl;
			std::cout << "Work ID: " << workId << std::endl;
		}
};

int main()
{
	
}
