#include <iostream>
#include "mystring.h"

int dl(const char* f) {
	size_t length = strlen(f);
	return length;
}

string::string(int n = 0, char value = ' ' ) {
	len = n;
	data = new char[len + 1];
	for (int i = 0; i < len; i++) {
		data[i] = '0';
	}
	data[len] = '\0';
}

string::string(const char* c) {
	data = new char[dl(c) + 1];
	len = dl(c);
	for (int i = 0; i < len; i++) {
		data[i] = c[i];
	}
}

string::string(const string& s) : len(s.len) {
	data = new char[len + 1];
	for (int i = 0; i < len; i++) {
		data[i] = s.data[i];
	}
	data[len] = '\0';
}

string::~string() {
	delete[] data;
}

string& string::operator=(const string& str2) {
	if (this == &str2) {
		return *this;
	}

	delete[] data;
	data = new char[str2.len + 1];
	len = str2.len;
	for (int i = 0; i < len; i++) {
		data[i] = str2.data[i];
	}
	return *this;
}

char string::operator[](int index) const {
	return data[index];
}

char& string::operator[](int index) {
	return data[index];
}

string string::operator+(const string& str2) {
	string res(len + str2.len);
	for (int i = 0; i < len; i++) {
		res[i] = data[i];
	}
	for (int i = len; i < len + str2.len; i++) {
		res[i] = str2.data[i - len];
	}
	return res;
}

string& string::operator+=(const string& str2) {
	string res(len + str2.len);
	for (int i = 0; i < len; i++) {
		res[i] = data[i];
	}
	for (int i = len; i < len + str2.len; i++) {
		res[i] = str2.data[i - len];
	}
	delete[] data;
	data = new char[res.len];
	len = res.len;
	for (int i = 0; i < len; i++) {
		data[i] = res.data[i];
	}
	return *this;
}

string string::substr(int pos, int n) {
	if (pos + n > len) {
		return 0;
	}
	string res(len);
	for (int i = pos; i < n + pos; i++) {
		res[i - pos] = (*this)[i];
	}
	res.len = n;
	return res;
}

int string::find(const string& str2) {
	int n = len;
	int m = str2.len;
	for (int i = 0; i < n - m + 1; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {
			if (str2[j] != (*this)[i + j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
	return n;
}

string& string::insert(int pos, const string& str2) {
	string res = data;
	delete[] data;
	data = new char[len + str2.len + 1];
	len = len + str2.len;
	for (int i = 0; i < pos; i++) {
		data[i] = res[i];
	}
	for (int i = pos; i < pos + str2.len; i++) {
		data[i] = str2[i - pos];
	}
	for (int i = pos + str2.len; i < len; i++) {
		data[i] = res[i - str2.len];
	}
	return *this;
}

string& string::insert(int pos, char c) {
	string res = data;
	delete[] data;
	data = new char[len + 1 + 1];
	len = len + 1;
	for (int i = 0; i < pos; i++) {
		data[i] = res[i];
	}
	data[pos] = c;
	for (int i = pos + 1; i < len - pos; i++) {
		data[i] = res[i - 1];
	}
	return *this;
}

string& string::erase(int pos, int n = 1) {
	if (pos + n > len) {
		throw "sizes are not equel";
	}
	string res(len);
	res = (*this);
	delete[] data;
	data = new char[len - n + 1];
	len = len - n;
	for (int i = 0; i < pos; i++) {
		data[i] = res[i];
	}
	for (int i = pos + n; i < len + n; i++) {
		data[i - n] = res[i];
	}
	return *this;
}

int string::size() {
	return len;
}

void string::print() {
	for (int i = 0; i < len; i++) {
		std::cout << data[i];
	}
	std::cout << "  " << len << std::endl;
}

bool string::empty() {
	return len == 0;
}

void string::clear() {
	for (int i = 0; i < len; i++) {
		data[i] = '\0';
	}
	len = 0;
}