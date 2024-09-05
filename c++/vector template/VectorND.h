#pragma once
#include <iostream>
#include <vector>

template <class T>
class Vector {
	T* data = nullptr;
	int n = 0;

public:
	Vector<T>(int n = 0) {
		if (n < 0) {
			return;
		}

		data = new T[n];
		resize(n);
		for (int i = 0; i < n; i++) {
			data[i] = T();
		}
	}

	~Vector<T>() {
		delete[] data;
	}

	Vector(const Vector<T>& v) : n(v.n) {
		data = new T[n];
		for (int i = 0; i < n; i++) {
			data[i] = v.data[i];
		}
	}

	template <class T2>
	Vector(const Vector<T2>& v) : n(v.size()) {
		data = new T[n];
		for (int i = 0; i < n; i++) {
			data[i] = v[i];
		}
	}

	Vector<T>& operator=(Vector<T> v) {
		if (n != v.n) {
			throw "sizes are not equel";
		}

		delete[] data;
		data = new T[v.n];
		n = v.n;
		for (int i = 0; i < n; i++) {
			data[i] = v.data[i];
		}
		return *this;
	}

	void print() const {
		for (int i = 0; i < n; i++) {
			std::cout << data[i] << "  ";
		}
		std::cout << std::endl;
	}

	T operator[](int index) const {
		return data[index];
	}

	T& operator[](int index) {
		return data[index];
	}

	Vector<T> operator+(const Vector<T>& v2) const {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		Vector<T> res(n);
		for (int i = 0; i < n; i++) {
			res.data[i] = data[i] + v2[i];
		}
		return res;
	}

	Vector<T>& operator+=(const Vector<T>& v2) {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		for (int i = 0; i < n; i++) {
			data[i] += v2.data[i];
		}
		return *this;
	}

	Vector<T> operator-(const Vector<T>& v2) const {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		Vector<T> res(n);
		for (int i = 0; i < n; i++) {
			res.data[i] = data[i] - v2.data[i];
		}
		return res;
	}

	Vector<T>& operator-=(const Vector<T> v2) {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		for (int i = 0; i < n; i++) {
			data[i] -= v2.data[i];
		}
		return *this;
	}

	T dot(Vector<T> v2) const {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		T res = 0;
		for (int i = 0; i < n; i++) {
			res += this->data[i] * v2.data[i];
		}
		return sqrt(res);
	}

	T norm() const {
		T res;
		res = dot(*this);
		return res;
	}

	T distance(const Vector<T>& v2) const {
		if (n != v2.n) {
			throw "sizes are not equel";
		}

		T res;
		Vector<T> a = *this - v2;
		res = a.norm();
		return res;
	}

	Vector<T> operator*(double c) const {
		Vector res(n);
		for (int i = 0; i < n; i++) {
			res.data[i] = data[i] * c;
		}
		return res;
	}

	Vector<T>& operator*=(double c) {
		for (int i = 0; i < n; i++) {
			data[i] *= c;
		}
		return *this;
	}

	Vector<T> operator/(double c) const {
		Vector res(n);
		for (int i = 0; i < n; i++) {
			res.data[i] = data[i] / c;
		}
		return res;
	}

	Vector<T>& operator/=(double c) {
		for (int i = 0; i < n; i++) {
			data[i] /= c;
		}
		return *this;
	}

	Vector<T> operator-()  const {
		Vector res(n);
		for (int i = 0; i < n; i++) {
			res.data[i] = -data[i];
		}
		return res;
	}

	int size() const { return n; }
	bool empty() const { return size() == 0; }

	Vector<T>& resize(int N) {
		T* tmp = new T[N];
		if (n < N) {
			for (int i = 0; i < n; i++) {
				tmp[i] = data[i];
			}
			for (int i = n; i < N; i++) {
				tmp[i] = T();
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

	friend std::ostream& operator<<(std::ostream& os, Vector<Vector<T>>& matrix) {
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 0; j < matrix.size(); j++) {
				os << "  " << matrix[i][j];
			}
			os << std::endl;
		}
		return os;
	}
};