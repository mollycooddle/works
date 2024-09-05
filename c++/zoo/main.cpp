#include "Animal.h"

int main() {
	//Cat cat("Barsik");
	//Dog dog("Sobaka");
	//Dolphin dolphin("Vitalya");
	//Fox fox("Igor");
	//Parrot parrot("Petya");
	//Twitter twitter("Sol");
	//Bee bee("Tvar");


	Animal* cat = new Cat("1");
	Animal* dog = new Dog("1");
	Animal* dolphin = new Dolphin("1");
	Animal* fox = new Fox("1");
	Animal* parrot = new Parrot("1");

	//std::cout << "\n\n\n";

	//Animal* dogs = new Cat("111", 9);

	//cat.sleep();
	//cat.eat();
	//cat.say();
	//cat.play();
	//cat.catchMouse();

	//dog.sleep();
	//dog.eat();
	//dog.say();
	//dog.play();
	//dog.secure();

	//dolphin.sleep();
	//dolphin.eat();
	//dolphin.say();
	//dolphin.play();
	//dolphin.performs();

	//fox.sleep();
	//fox.eat();
	//fox.say();
	//fox.play();
	//fox.beatEggs();

	//parrot.sleep();
	//parrot.eat();
	//parrot.say();
	//parrot.fly();
	//parrot.repeat();

	//twitter.sleep();
	//twitter.eat();
	//twitter.say();
	//twitter.fly();
	//twitter.layEggs();

	//bee.sleep();
	//bee.eat();
	//bee.say();
	//bee.fly();
	//bee.collectsHoney();

	//std::cout << "\n\n";

	Zoo zoo;

	//zoo.add(&cat);
	//zoo.add(&dog);
	//zoo.add(&dolphin);
	//zoo.add(&fox);
	//zoo.add(&parrot);
	//zoo.add(&twitter);
	//zoo.add(&bee);
	//zoo.print();

	std::cout << "\n";

	//zoo.erase(1);
	//zoo.print();

	//std::cout << "\n";

	//zoo.sound();

	zoo.add(cat);
	zoo.add(dog);
	zoo.add(dolphin);
	zoo.add(fox);
	zoo.add(parrot);
	zoo.print();

	//std::cout << "\n";

	//zoo.erase(1);
	//zoo.print();

	std::cout << cat;

	std::cin >> cat;
	cat->printC();

	int k = zoo.kMammal();
	std::cout << k << std::endl;
}