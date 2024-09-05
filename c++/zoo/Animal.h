#pragma once
#include <iostream>

class Animal {
	static inline int count = 0;
protected:
	void print(std::string name, std::string operation) {
		std::cout << name << " is " << operation << std::endl;
	}
public:
	std::string name;
	int id;
	Animal() {
		id = ++count;
	}
	Animal(std::string imya) {
		name = imya;
		id = ++count;
	}

	virtual ~Animal() {	}
	void sleep() {
		print(name, "sleeping");
	}
	void eat() {
		print(name, "eating");
	}
	virtual void say() = 0;
	virtual std::string getClass() { return "Not class "; }
	void printC() {
		std::cout << getClass() << "  " << name << std::endl;
	}

	friend std::istream& operator>> (std::istream& istr, Animal *a) {
		std::string name;
		istr >> name;
		a->name = name;
		return istr;
	}

	friend std::ostream& operator<< (std::ostream& ostr, Animal *a) {
		ostr << a->name << std::endl;
		return ostr;
	}

};

class Mammal :public Animal {
public:
	Mammal(std::string name) :Animal(name) { }
	Mammal() :Animal() { }

	~Mammal() { }

	void play() {
		print(name, "playing");
	}
};

class Bird :public Animal {
public:
	Bird(std::string name) :Animal(name) {}
	Bird() :Animal() {}

	~Bird() { }

	void fly() {
		print(name, "flying");
	}
};

class Insect :public Animal {
public:
	Insect(std::string name) :Animal(name) {}
	Insect() :Animal() {}

	~Insect() { }

	void fly() {
		print(name, "flying");
	}
};

class Spider :public Animal {
public:
	Spider(std::string name) :Animal(name) {}
	Spider() :Animal() {}
	void crawl() {
		print(name, "crawling");
	}
};

class Cat :public Mammal {
public:
	Cat(std::string name) :Mammal(name) { }
	Cat() :Mammal() { }

	~Cat() { }

	void catchMouse() {
		print(name, "catching mouse");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Meow" << std::endl;
	}
	std::string getClass() {
		return "Cat";
	}
};

class Dog :public Mammal {
public:
	Dog(std::string name) :Mammal(name) {}
	Dog() :Mammal() {}
	void secure() {
		print(name, "securing");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Woof!" << std::endl;
	}
	std::string getClass() {
		return "Dog";
	}
};

class Dolphin :public Mammal {
public:
	Dolphin(std::string name) :Mammal(name) {}
	Dolphin() :Mammal() {}
	void performs() {
		print(name, "performs");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Urrr..." << std::endl;
	}
	std::string getClass() {
		return "Dolphin";
	}
};

class Fox :public Mammal {
public:
	Fox(std::string name) :Mammal(name) {}
	Fox() :Mammal() {}
	void beatEggs() {
		print(name, "beating eggs");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Uiii..." << std::endl;
	}
	std::string getClass() {
		return "Fox";
	}
};

class Parrot :public Bird {
public:
	Parrot(std::string name) :Bird(name) {}
	Parrot() :Bird() {}
	void repeat() {
		print(name, "repeating");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Hi, people!" << std::endl;
	}
	std::string getClass() {
		return "Parrot";
	}
};

class Twitter :public Bird {
public:
	Twitter(std::string name) :Bird(name) {}
	Twitter() :Bird() {}
	void layEggs() {
		print(name, "laing eggs");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "chirik" << std::endl;
	}
	std::string getClass() {
		return "Twitter";
	}
};

class Bee :public Insect {
public:
	Bee(std::string name) :Insect(name) {}
	Bee() :Insect() {}
	void collectsHoney() {
		print(name, "collecting honey");
	}
	void say() {
		std::cout << name << " is " << "saying: " << "Jy-Jy" << std::endl;
	}
	std::string getClass() {
		return "Bee";
	}
};

class Zoo {
	Animal** animals = nullptr;
	int n = 0;
public:
	void add(Animal* a) {
		Animal** tmp = new Animal * [n + 1];
		for (int i = 0; i < n; i++) {
			tmp[i] = animals[i];
		}
		delete[] animals;
		animals = tmp;
		animals[n++] = a;
	}

	void erase(int ind) {
		for (int i = 0; i < n; i++) {
			if (animals[i]->id == ind) {
				Animal** tmp = new Animal * [n - 1];
				for (int i = 0; i < ind; i++) {
					tmp[i] = animals[i];
				}
				for (int i = ind + 1; i < n; i++) {
					tmp[i - 1] = animals[i];
				}
				delete[] animals;
				animals = tmp;
				n--;
				break;
			}
		}
	}

	void sound() {
		for (int i = 0; i < n; i++) {
			animals[i]->say();
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			animals[i]->printC();
		}
	}

	int kMammal() {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if ((dynamic_cast<Mammal*>(animals[i])) != 0) {
				k++;
			}
		}
		return k;
	}
};