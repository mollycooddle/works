#include <iostream>
#include "complex.h"


int main() {

	complex a(2,2);

	complex b(2, 3);

	complex c(2, 2);

	complex d(4, 4);

	complex e(-1, -3);

	//complex + * / -
	complex resadd = a+b;

	complex resmul = a*b;

	complex resdiv = a/b;

	complex ressub = a-b;

	resadd.print();
	resmul.print();
	resdiv.print();
	ressub.print();

	//double + * / -
	complex resadd_d = a + 2.1;

	complex resmul_d = a * 2.1;

	complex resdiv_d = a / 2.1;

	complex ressub_d = a - 2.1;

	resadd_d.print();
	resmul_d.print();
	resdiv_d.print();
	ressub_d.print();

	//conj
	complex resconj = a.conj();

	resconj.print();

	//mod+arg
	double mod = a.getAbs();
	double arg = a.getArg();
	
	std::cout << mod << "   " << arg << std::endl;

	//complex += *= /= -=
	a += b;
	b *= c;
	c /= d;
	d -= e;

	a.print();
	b.print();
	c.print();
	d.print();

	//create complex using mod, arg
	complex res(0, 0);
	res.create(4, 0.785);
	res.print();
}

