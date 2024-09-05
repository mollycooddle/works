#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class corporation :public sf::Sprite {
protected:
	std::string name;
	sf::Texture texture;
	int price;
	int donate;
	int x = 1;
	int Affiliation = 0;   //0 - nicheu'  1 - Green  2 - Red

public:
	sf::Text text;

	corporation(std::string name, int x, int price, int donate, std::string str, sf::Font& font) {
		if (!texture.loadFromFile(str))
			return;

		text.setFont(font);
		text.setCharacterSize(35);
		text.setFillColor(sf::Color::Black);
		text.setString("ERROR");
		text.setPosition(1280, 1280);

		this->name = name;
		this->x = x;
		this->price = price;
		this->donate = donate;
		this->setTexture(texture);
		this->setPosition(sf::Vector2f(0, 0));
	}

	void setPositionobj(int x, int y) {
		this->setPosition(sf::Vector2f(x, y));
	}

	sf::Vector2f getPositionobj() {
		return this->getPosition();
	}

	int getCoord() {
		return this->x;
	}

	void setText(std::string string) {
		text.setString(string);
	}

	void setTextPosition(int x, int y) {
		text.setPosition(x, y);
	}

	void setAffiliation(int n) {
		Affiliation = n;
	}

	int getAffiliation() {
		return Affiliation;
	}

	int getPrice() {
		return price;
	}

	std::string getPriceStr() {
		return std::to_string(price);
	}

	int getDonate() {
		return donate;
	}

	std::string getDonateStr() {
		return std::to_string(donate);
	}

	bool operator==(corporation corp) {
		return (this->x == corp.x);
	}

	std::string getName() {
		return name;
	}

	void setTextureobj(std::string str) {
		if (!texture.loadFromFile(str))
			return;

		this->setTexture(texture);
	}

	void drawobj(sf::RenderWindow& window) {
		window.draw(*this);
	}
};