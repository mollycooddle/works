#include <iostream>
#include "complex.h"


int main() {

	complex a;
	a.real = -1;
	a.image = 1;

	complex b;
	b.real = 2;
	b.image = 3;
	
	complex c(2, 2);
	
	complex d(4, 4);

	complex e(-1, -3);

	//complex + * / -
	complex resadd = a.add(b);

	complex resmul = a.mul(b);

	complex resdiv = a.div(b);

	complex ressub = a.sub(b);

	resadd.print();
	resmul.print();
	resdiv.print();
	ressub.print();

	//double + * / -
	complex resadd_d = a.add(2.1);

	complex resmul_d = a.mul(2.1);

	complex resdiv_d = a.div(2.1);

	complex ressub_d = a.sub(2.1);

	resadd_d.print();
	resmul_d.print();
	resdiv_d.print();
	ressub_d.print();

	//conj
	complex resconj = a.conj();

	resconj.print();

	//mod+arg
	double mod = a.mod();
	double arg = a.arg();

	std::cout << mod << "   " << arg << std::endl;

	//complex += *= /= -=
	a.addassert(b);
	b.mulassert(c);
	c.divassert(d);
	d.subassert(e);

	a.print();
	b.print();
	c.print();
	d.print();

	//create complex using mod, arg
	complex res(0,0);
	res.create(4, 0.785);
	res.print();
}

