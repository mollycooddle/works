#pragma once
#include <iostream>
#include <cmath>

struct complex {
	double real;
	double image;

	complex() {}
	complex(double r, double i) {
		this->real = r;
		this->image = i;
	}

	void print() {
		std::cout << this->real << "  " << this->image << std::endl;
	}

	complex add(complex b) {
		complex c;
		c.real = this->real + b.real;
		c.image = this->image + b.image;
		return c;
	}

	complex mul(complex b) {
		complex c;
		c.real = this->real * b.real;
		c.image = this->image * b.image;
		return c;
	}

	complex div(complex b) {
		complex c;
		c.real = (this->real * b.real + this->image * b.image) / (b.real * b.real + b.image * b.image);
		c.image = (this->image * b.real - this->real * b.image) / (b.real * b.real + b.image * b.image);
		return c;
	}

	complex sub(complex b) {
		complex c;
		c.real = this->real - b.real;
		c.image = this->image - b.image;
		return c;
	}

	complex add(double b) {
		complex c;
		c.real = this->real + b;
		c.image = this->image;
		return c;
	}

	complex mul(double b) {
		complex c;
		c.real = this->real * b;
		c.image = this->image;
		return c;
	}

	complex div(double b) {
		complex c;
		c.real = this->real / b;
		c.image = this->image;
		return c;
	}
	
	complex sub(double b) {
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

	double mod() {
		double r = sqrt(pow(this->real, 2) + pow(this->image, 2));
		return r;
	}

	double arg() {
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

	void addassert(complex b) {
		this->real = this->real + b.real;
		this->image = this->image + b.image;
	}

	void mulassert(complex b) {
		this->real = this->real * b.real;
		this->image = this->image * b.image;
	}

	void divassert(complex b) {
		this->real = (this->real * b.real + this->image * b.image) / (b.real * b.real + b.image * b.image);
		this->image = (this->image * b.real - this->real * b.image) / (b.real * b.real + b.image * b.image);
	}

	void subassert(complex b) {
		this->real = this->real - b.real;
		this->image = this->image - b.image;
	}

	void create(double r, double fi) {
		this->image = r * fi;
		this->real = sqrt(pow(r, 2) - pow(this->image, 2));
	}
};