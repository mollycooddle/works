#pragma once

class Vector {
	double* data=nullptr;
	int n;

public:
	Vector(int n = 0);
	~Vector();
	Vector(const Vector& v);
	Vector& operator=(Vector v);
	void print() const;
	double operator[](int index) const;
	double& operator[](int index);
	double dot(Vector v2) const;
	double norm() const;
	double distance(const Vector& v2) const;
	Vector operator+(const Vector& v2) const;
	Vector& operator+=(const Vector& v2);
	Vector operator-(const Vector& v2) const;
	Vector& operator-=(const Vector& v2);
	Vector operator*(double c) const;
	Vector& operator*=(double c);
	Vector operator/(double c) const;
	Vector& operator/=(double c);
	Vector operator-() const;
	int size() const;
	bool empty() const;
	Vector& resize(int n);
};