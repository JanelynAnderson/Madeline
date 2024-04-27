#include <iostream>
#include <limits>
int main(int, char* [])
{	
	std::cout << "test";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}