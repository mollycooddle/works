#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Vector.h"

int main() {
    srand(time(NULL));

    int n = 10;

    Vector<int> a(n);
    Vector<double> b(n, 1.0);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }

    a.print();
    b.print();

    a[0] = b[0];
    a.print();

    a.push_back(33);
    a.print();

    a.pop_back();
    a.print();

    a.insert(0, 300);
    a.print();

    a.erase(0);
    a.print();

    std::cout << a.size() << std::endl;

    a.resize(30);
    a.print();

    a.resize(2);
    a.print();

    a.resize(n);
    a.print();

    for (int i = 0; i < 100; i++) {
        a.push_back(rand() % 10);
    }
    a.print();

    a.resize(0);
    a.push_back(1);
    a.print();

    a.resize(500);
    a.print();
}