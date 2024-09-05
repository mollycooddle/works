#pragma once

class string {
	char* data = nullptr;
	int len = 0;

public:
	string(int n, char value);
	string(const char*);
	string(const string& s);
	~string();
	string& operator=(const string&);
	char operator[](int index) const;
	char& operator[](int index);
	string operator+(const string&);
	string& operator+=(const string&);
	string substr(int pos, int n);
	int find(const string&);
	string& insert(int pos, const string&);
	string& insert(int pos, char c);
	string& erase(int pos, int n);
	int size();
	void print();
	bool empty();
	void clear();

};