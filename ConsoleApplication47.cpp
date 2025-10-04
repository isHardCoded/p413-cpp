#include <iostream>
#include <cpr/cpr.h>

using namespace std;
using namespace cpr;

int main()
{
	auto response = cpr::Get(cpr::Url{"https://jsonplaceholder.typicode.com/users"});

	std::cout << response.text;
}