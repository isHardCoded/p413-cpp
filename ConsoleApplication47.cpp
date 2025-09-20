#include <iostream>

class Counter {
	public:
		static int count;

		Counter() { ++count; }

		static int getCount() {
			return count;
		}
};

int Counter::count = 0;

int main()
{
	Counter a, b, c;
	std::cout << a.getCount();
}
