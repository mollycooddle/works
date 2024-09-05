#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Cube : public sf::Sprite {
protected:
	int num;
	sf::Texture TextureCube;
public:
	Cube(int n, std::string name) {
		if (!TextureCube.loadFromFile(name)) {
			return;
		}
		this->num = n;
		this->setTexture(TextureCube);
		this->setPosition(sf::Vector2f(1280, 1280));
	}

	void setPositionCube(int x, int y) {
		this->setPosition(sf::Vector2f(x, y));
	}

	void drawCube(sf::RenderWindow& window) {
		window.draw(*this);
	}

	void unvisible() {
			this->setPositionCube(1280, 1280);
	}
};

template <typename T>
class TexturedSprite : public sf::Sprite {
protected:
	T texture;
public:
	TexturedSprite(std::string name) {
		if (!texture.loadFromFile(name)) {
			return;
		}
		this->setTexture(texture);
		this->setPosition(sf::Vector2f(0, 0));
	}
	
	void setPositionobj(int x, int y) {
		this->setPosition(sf::Vector2f(x, y));
	}

	void setScaleobj(float x) {
		this->setScale(x, x);
	}

	void drawobj(sf::RenderWindow& window) {
		window.draw(*this);
	}

	void unvisible(float timer, float delay) {
		if (timer >= delay) {
			this->setPositionCube(1280, 1280);
		}
	}
};