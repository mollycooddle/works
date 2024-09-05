#pragma once
#include <iostream>

template <class T>
class Vector {
	T* data = nullptr;
	int n = 0;
	int capacity = 1;
public:
	Vector<T>(int N = 0) {
		if (N < 0) {
			return;
		}

		data = new T[N];
		n = N;
		capacity = n;
		for (int i = 0; i < n; i++) {
			data[i] = T();
		}
	}

	Vector<T>(int N, T value) {
		if (N < 0) {
			return;
		}

		data = new T[N];
		n = N;
		capacity = n;
		for (int i = 0; i < n; i++) {
			data[i] = value;
		}
	}

	~Vector<T>() {
		delete[] data;
	}

	Vector(const Vector<T>& v) : n(v.n), capacity(v.capacity) {
		data = new T[n];
		for (int i = 0; i < n; i++) {
			data[i] = v.data[i];
		}
	}

	Vector<T>& operator=(Vector<T> v) {
		if (this != &v) {
			T* newData = new T[v.capacity];
			for (int i = 0; i < v.n; i++) {
				newData[i] = v.data[i];
			}
			delete[] data;
			data = newData;
			n = v.n;
			capacity = v.capacity;
		}
		return *this;
	}

	T operator[](int index) const {
		return data[index];
	}

	T& operator[](int index) {
		return data[index];
	}

	Vector<T>& push_back(T value) {
		if (n == capacity) {
			reallocate(capacity * 2);
		}
		data[n++] = value;
		return *this;
	}

	Vector<T>& pop_back() {
		n--;
		return *this;
	}

	void reallocate(int newCapacity) {
		if (newCapacity == capacity) {
			return;
		}

		T* newData = new T[newCapacity];
		for (int i = 0; i < n; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

	void insert(int pos, T value) {
		if (n >= capacity) {
			reallocate(capacity * 2);
		}
		for (int i = n; i > pos; --i) {
			data[i] = data[i - 1];
		}
		data[pos] = value;
		++n;

	}

	void erase(int index) {
		for (int i = index; i < n - 1; i++) {
			data[i] = data[i + 1];
		}

		n--;
		capacityTest();
	}

	int size() const { return n; }

	void resize(int newSize) {
		if (newSize > capacity) {
			reallocate(newSize);
		}
		if (newSize <= capacity) {
			for (int i = n; i < capacity; i++) {
				data[i] = T();
			}
		}
		n = newSize;
	}

	void print() const {
		for (int i = 0; i < n; i++) {
			std::cout << data[i] << "  ";
		}
		std::cout << std::endl;
	}

	void capacityTest() {
		if (capacity < n) {
			capacity = n;
		}
	}
};