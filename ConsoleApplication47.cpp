#include <iostream>

class Array {
private:
	int* data;
	int size;

public:
	Array(int n) : size(n) {
		data = new int[size];
	}

	~Array() {
		delete[] data;
	}
};

int main()
{
	
}
