#include "MyString.h"
#include <string>

int main() {

	MyString a = "axpern";
	MyString b(a);
	//std::cout << b;
	MyString c{ 'H','e','l','l','o' };
	//std::cout << c<<std::endl;
	c += a;
	//std::cout << c.getCapacity();
//	c.reserve(1000);
	c.insert(3, 'k');
	std::cout << c;
	c.erase(3);
	std::cout << c;
	c.push_back('k');
	std::cout << c;
	c.pop_back();
	std::cout << c<<std::endl;
	c.append(5, 'c');
	std::cout << c;
	//std::cout << '\n' << c;
	//std::cout <<std::endl<< (c == j);
};


