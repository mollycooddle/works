#include <iostream>
#include <cmath>
#include "Vector10D.h"

Vector::Vector(int n) {
	if (n <= 0) {
		return;
	}

	data = new double[n];
	resize(n);
	for (int i = 0; i < n; i++) {
		data[i] = 0;
	}
}

Vector::~Vector() {
	delete[] data;
}

Vector::Vector(const Vector& v) : n(v.n) {
	data = new double[n];
	for (int i = 0; i < n; i++) {
		data[i] = v.data[i];
	}
}

Vector& Vector::operator=(Vector v) {
	if (n != v.n) {
		throw "sizes are not equel";
	}
	
	delete[n] data;
	data = new double[v.n];
	n = v.n;
	for (int i = 0; i < n; i++) {
		data[i] = v.data[i];
	}
	return *this;
}

void Vector::print() const {
	for (int i = 0; i < n; i++) {
		std::cout << data[i] << "  ";
	}
	std::cout << std::endl;
}

double Vector::operator[](int index) const {
	return data[index];
}

double& Vector::operator[](int index) {
	return data[index];
}

Vector Vector::operator+(const Vector& v2) const{
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	Vector res(n);
	for (int i = 0; i < n; i++) {
		res.data[i] = data[i] + v2[i];
	}
	return res;
}

Vector& Vector::operator+=(const Vector& v2) {
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	for (int i = 0; i < n; i++) {
		data[i] += v2.data[i];
	}
	return *this;
}

Vector Vector::operator-(const Vector& v2) const {
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	Vector res(n);
	for (int i = 0; i < n; i++) {
		res.data[i] = data[i] - v2.data[i];
	}
	return res;
}

Vector& Vector::operator-=(const Vector& v2) {
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	for (int i = 0; i < n; i++) {
		data[i] -= v2.data[i];
	}
	return *this;
}

double Vector::dot(Vector v2) const {
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	double res = 0;
	for (int i = 0; i < n; i++) {
		res += this->data[i] * v2.data[i];
	}
	return sqrt(res);
}

double Vector::norm() const {
	double res;
	res = dot(*this);
	return res;
}

double Vector::distance(const Vector& v2) const {
	if (n != v2.n) {
		throw "sizes are not equel";
	}

	double res;
	Vector a = *this - v2;
	res = a.norm();
	return res;
}

Vector Vector::operator*(double c) const {
	Vector res(n);
	for (int i = 0; i < n; i++) {
		res.data[i] = data[i] * c;
	}
	return res;
}

Vector& Vector::operator*=(double c) {
	for (int i = 0; i < n; i++) {
		data[i] *= c;
	}
	return *this;
}

Vector Vector::operator/(double c) const {
	Vector res(n);
	for (int i = 0; i < n; i++) {
		res.data[i] = data[i] / c;
	}
	return res;
}

Vector& Vector::operator/=(double c) {
	for (int i = 0; i < n; i++) {
		data[i] /= c;
	}
	return *this;
}

Vector Vector::operator-()  const{
	Vector res(n);
	for (int i = 0; i < n; i++) {
		res.data[i] = -data[i];
	}
	return res;
}

int Vector::size() const { return n; }
bool Vector::empty() const { return size() == 0; }

Vector& Vector::resize(int N) {
	double* tmp = new double[N];
	if (n < N) {
		for (int i = 0; i < n; i++) {
			tmp[i] = data[i];
		}
		for (int i = n; i < N; i++) {
			tmp[i] = 0;
		}
	}
	if (n > N) {
		for (int i = 0; i < N; i++) {
			tmp[i] = data[i];
		}
	}
	delete[] data;
	data = tmp;
	
	this->n = N;
	return *this;
}
