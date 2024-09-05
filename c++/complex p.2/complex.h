#pragma once

#include <iostream>
#include <cmath>

class complex {
	double real = 0;
	double image = 0;
	double mod = 0;
	double arg = 0;

public:
	double getreal() { return this->real; }
	double setreal(double r) { real = r; }

	double getimage() { return this->image; }
	double setimage(double i) { image = i; }

	complex(double r, double i) {
		this->real = r;
		this->image = i;
	}
	complex(double r) {
		this->real = r;
		//this->image = i;
	}
	complex() {
		//this->real = r;
		//this->image = i;
	}

	void print() {
		std::cout << this->real << "  " << this->image << std::endl;
	}

	complex operator+(complex b) {
		complex c;
		c.real = this->real + b.real;
		c.image = this->image + b.image;
		return c;
	}

	complex operator*(complex b) {
		complex c;
		c.real = this->real * b.real;
		c.image = this->image * b.image;
		return c;
	}

	complex operator/(complex b) {
		complex c;
		c.real = (this->real * b.real + this->image * b.image) / (b.real * b.real + b.image * b.image);
		c.image = (this->image * b.real - this->real * b.image) / (b.real * b.real + b.image * b.image);
		return c;
	}

	complex operator-(complex b) {
		complex c;
		c.real = this->real - b.real;
		c.image = this->image - b.image;
		return c;
	}

	complex operator+(double b) {
		complex c;
		c.real = this->real + b;
		c.image = this->image;
		return c;
	}

	complex operator*(double b) {
		complex c;
		c.real = this->real * b;
		c.image = this->image;
		return c;
	}

	complex operator/(double b) {
		complex c;
		c.real = this->real / b;
		c.image = this->image;
		return c;
	}

	complex operator-(double b) {
		complex c;
		c.real = this->real - b;
		c.image = this->image;
		return c;
	}

	complex conj() {
		complex c;
		c.real = this->real;
		c.image = -this->image;
		return c;
	}

	double getAbs() {
		return sqrt(pow(this->real, 2) + pow(this->image, 2));
	}
	void setAbs(double r) {
		mod = r;
	}

	double getArg() {
		double fi = asin(this->image / sqrt(pow(this->real, 2) + pow(this->image, 2))) * 53.7;
		if (this->real < 0 and this->image > 0) {
			fi += 90;
		}
		if (this->real < 0 and this->image < 0) {
			fi -= 90;
		}
		if (this->real > 0 and this->image == 0) {
			fi = 0;
		}
		if (this->real < 0 and this->image == 0) {
			fi = 180;
		}
		if (this->real == 0 and this->image > 0) {
			fi = 90;
		}
		if (this->real == 0 and this->image < 0) {
			fi = -90;
		}
		return fi;
	}
	void setArg(double r) {
		arg = r;
	}

	complex& operator+=(complex b) {
		this->real = this->real + b.real;
		this->image = this->image + b.image;
		return *this;
	}

	complex& operator*=(complex b) {
		this->real = this->real * b.real;
		this->image = this->image * b.image;
		return *this;
	}

	complex& operator/=(complex b) {
		this->real = (this->real * b.real + this->image * b.image) / (b.real * b.real + b.image * b.image);
		this->image = (this->image * b.real - this->real * b.image) / (b.real * b.real + b.image * b.image);
		return *this;
	}

	complex& operator-=(complex b) {
		this->real = this->real - b.real;
		this->image = this->image - b.image;
		return *this;
	}

	void create(double r, double fi) {
		this->image = r * fi;
		this->real = sqrt(pow(r, 2) - pow(this->image, 2));
	}
};
