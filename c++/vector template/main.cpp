#include <iostream>
#include <cstdlib>
#include <ctime>
#include "VectorND.h"
#include <vector>

int main() {
	srand(time(NULL));
	int n = 10;
	Vector<int> a(n);
	Vector<double> b(n);

	Vector<std::string> s(3);
	Vector<std::string> t(3);
	

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
		b[i] = rand() % 10;
	}

	std::cout << "Int and Double:\n\n";

	a.print();
	b.print();

	double dot1 = a.dot(b);
	std::cout << dot1 << "  " << std::endl;

	double norm1 = a.norm();
	std::cout << norm1 << "  " << std::endl;

	double distance1 = a.distance(b);
	std::cout << distance1 << "  " << std::endl;
	
	Vector<int> res1 = a + b;
	res1.print();

	a += b;
	a.print();

	Vector<int> res2 = a - b;
	res2.print();

	a -= b;
	a.print();

	double c = 2.0;
	Vector<int> res3 = a * c;
	res3.print();

	a *= c;
	a.print();

	Vector<int> res4 = a / c;
	res4.print();

	a /= c;
	a.print();

	Vector<int> res5 = -a;
	res5.print();
	a.print();

	c = a[0];
	std::cout << c << std::endl;

	a[0] = 999.0;
	std::cout << a[0] << std::endl;

	a.resize(11);
	a.print();
	std::cout << a.size() << std::endl;

	a.resize(3);
	a.print();
	std::cout << a.size() << std::endl;




	std::cout << "\n\n";

	std::cout << "Strings:\n\n";
	
	for (int i = 0; i < 3; i++) {
		s[i] = 'h';
		t[i] = 'G';
	}

	s.print();
	t.print();

	//double dot1 = a.dot(b);                      //net
	//std::cout << dot1 << "  " << std::endl;

	//double norm1 = a.norm();					   //net
	//std::cout << norm1 << "  " << std::endl;

	//double distance1 = a.distance(b);            //net
	//std::cout << distance1 << "  " << std::endl;
	
	Vector<std::string> resStr1 = s+t;
	resStr1.print();

	s += t;
	s.print();

	//Vector<std::string> resStr2 = s - t;         //net
	//resStr2.print();

	//a -= b;                                      //net
	//a.print();

	//double c = 2.0;                              //net
	//Vector<std::string> resStr3 = s * c;
	//resStr3.print();

	//a *= c;                                      //net
	//a.print();

	//Vector<int> res4 = a / c;                    //net
	//res4.print();

	//a /= c;                                      //net
	//a.print();

	//Vector<int> res5 = -a;                       //net
	//res5.print();
	//a.print();

	std::string g = s[0];
	std::cout << g << std::endl;

	s[0] = 'F';
	std::cout << s[0] << std::endl;

	s.resize(11);
	s.print();
	std::cout << s.size() << std::endl;

	s.resize(2);
	s.print();
	std::cout << s.size() << std::endl;




	std::cout << "\n\n";

	std::cout << "Matrix:\n\n";

	int m = 2;

	Vector<Vector<int>> mat;
	Vector<Vector<int>> mat2;
	
	mat.resize(m);
	mat2.resize(m);
	for (int i = 0; i < m; i++) {
		mat[i].resize(2);
		mat2[i].resize(2);
		for (int j = 0; j < m; j++) {
			mat[i][j] = rand() % 10;
			mat2[i][j] = rand() % 10;
		}
	}


	std::cout << mat << std::endl;
	std::cout << mat2 << std::endl;

	//double dot1 = a.dot(b);                      //net
	//std::cout << dot1 << "  " << std::endl;

	//double norm1 = a.norm();					   //net
	//std::cout << norm1 << "  " << std::endl;

	//double distance1 = a.distance(b);            //net
	//std::cout << distance1 << "  " << std::endl;

	//Vector<Vector<int>> resMat1 = mat + mat2;      //mojno napisat' otdel'nyu fynkciu, chto bi skladivat' vectora, a tak net napisannou' fynkciu operator+ dlya vectorov
	//std::cout << resMat1 << std::endl;

	//s += t;                                        //analogichno
	//s.print();

	//Vector<std::string> resStr2 = s - t;         //analogichno
	//resStr2.print();

	//a -= b;                                      //analogichno
	//a.print();

	//double c = 2.0;                              //analogichno
	//Vector<Vector<int>> resMat2 = mat * c;
	//std::cout << resMat2 << std::endl;

	//a *= c;                                      //analogichno
	//a.print();

	//Vector<int> res4 = a / c;                    //analogichno
	//res4.print();

	//a /= c;                                      //analogichno
	//a.print();

	//Vector<int> res5 = -a;                       //analogichno
	//res5.print();
	//a.print();

	int I = mat[0][1];
	std::cout << I << std::endl;

	mat[0][0] = 1;
	std::cout << mat[0][0] << std::endl;

	//mat.resize(5);                                 //mojno, esli kak-to nemnogo perepisat' resize
	//std::cout << mat << std::endl;
	//std::cout << mat.size() << std::endl;

	//s.resize(2);                                   //analogichno
	//s.print();
	//std::cout << s.size() << std::endl;
}