#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player:public sf::Sprite {
protected:
	int money = 20000;
	int x = 1;
	sf::Texture texture;

public:
	Player(std::string name) {
		if (!texture.loadFromFile(name)) {
			return;
		}
		this->setTexture(texture);
		this->setPosition(sf::Vector2f(280, 0));
	}

	void setPositionobj(int x, int y) {
		this->setPosition(sf::Vector2f(x, y));
	}

	void setPositionobj(sf::Vector2f x) {
		this->setPosition(x);
	}

	sf::Vector2f getPositionobj() {
		return this->getPosition();
	}

	void setCoord(int x) {
		this->x = x;
	}

	int getCoord() {
		return this->x;
	}

	void setMoney(int n) {
		money = n;
	}

	int getMoney() {
		return money;
	}

	std::string getMoneyStr() {
		return std::to_string(money);
	}

	void drawobj(sf::RenderWindow& window) {
		window.draw(*this);
	}
};
