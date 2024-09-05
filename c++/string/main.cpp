#include <iostream>
#include "mystring.h"

int main() {
	string str = "Hello";
	string str2 = " world!";

	str.print();
	str2.print();

	string str3 = str;
	str3.print();

	str[0] = 'h';
	str2[4] = str[2];
	str.print();
	str2.print();

	string str4 = str + str2;
	str4.print();

	str += str2;
	str.print();

	string str5 = str.substr(2, 2);
	str5.print();

	int index = str.find("el");
	std::cout << index << std::endl;

	str2.insert(0, "Hello");
	str2.print();

	str2.insert(0, '_');
	str2.print();

	str2.erase(0, 2);
	str2.print();

	int n = str.size();
	std::cout << n << std::endl;

	bool tr = str.empty();
	std::cout << tr << std::endl;

	str.clear();
	str.print();

}