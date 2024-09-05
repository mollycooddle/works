#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector10D.h"

int main() {
	srand(time(NULL));
	int n = 10;
	Vector a(n);
	Vector b(n);

	for (int i = 0; i < n; i++) {
		a[i] = rand();
		b[i] = rand();
	}

	a.print();
	b.print();

	double dot1 = a.dot(b);
	std::cout << dot1 << "  " << std::endl;

	double norm1 = a.norm();
	std::cout << norm1 << "  " << std::endl;

	double distance1 = a.distance(b);
	std::cout << distance1 << "  " << std::endl;

	Vector res1 = a + b;
	res1.print();

	a += b;
	a.print();

	Vector res2 = a - b;
	res2.print();

	a -= b;
	a.print();

	double c = 2.0;
	Vector res3 = a * c;
	res3.print();

	a *= c;
	a.print();

	Vector res4 = a / c;
	res4.print();

	a /= c;
	a.print();

	Vector res5 = -a;
	res5.print();
	a.print();

	c = a[0];
	std::cout << c << std::endl;

	a[0] = 999.0;
	std::cout << a[0] << std::endl;

	std::cout << "\n\n\n";

	a.resize(11);
	a.print();
	std::cout << a.size() << std::endl;

	a.resize(3);
	a.print();
	std::cout << a.size() << std::endl;
}