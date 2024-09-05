#pragma once
#include <random>
#include "Players.h"
#include "Corporations.h"

int randomCube() {
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<> dis(0, 5);

	return dis(gen);
}

std::tuple<corporation, int> movePlayer (int& step, int& flag, sf::RenderWindow& window, int x, Player& player, std::vector<corporation>& corps) {
	std::string str;

	if (player.getCoord() + x < 25) {
		player.setCoord(player.getCoord() + x);
	}
	else if (player.getCoord() + x == 25) {
		player.setCoord(1);
	}
	else if (player.getCoord() + x > 25) {
		player.setCoord(player.getCoord() + x - 25 + 1);
	}

	for (int i = 0; i < 25; i++) {
		if (corps[i].getCoord() == player.getCoord()) {
			player.setPositionobj(corps[i].getPositionobj());

			if (player.getCoord() == 5) {
				str = "Give " + corps[i].getDonateStr();
				flag = 5;
				corps[i].setText(str);
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			else if (player.getCoord() == 7) {
				corps[i].setText("You skip 1 step.");
				flag = 7;
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			else if (player.getCoord() == 13) {
				str = "Take " + corps[i].getDonateStr();
				flag = 13;
				corps[i].setText(str);
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			else if (player.getCoord() == 19) {
				corps[i].setText("You skip 1 step.");
				flag = 7;
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			else if (player.getCoord() == 21) {
				str = "Give " + corps[i].getDonateStr();
				flag = 21;
				corps[i].setText(str);
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			if (corps[i].getAffiliation() == 0) {
				str = "Byu for " + corps[i].getPriceStr();
				flag = 0;
				corps[i].setText(str);
				corps[i].setTextPosition(550, 120);
				window.draw(corps[i].text);
				return std::make_tuple(corps[i], flag);
			}
			if (corps[i].getAffiliation() == 1) {
				if (step % 2 == 0) {
					str = "Its your corporation.";
					flag = 0;
					corps[i].setText(str);
					corps[i].setTextPosition(550, 120);
					window.draw(corps[i].text);
					return std::make_tuple(corps[i], flag);
				}
				else {
					str = "Take " + corps[i].getDonateStr();
					flag = 0;
					corps[i].setText(str);
					corps[i].setTextPosition(550, 120);
					window.draw(corps[i].text);
					return std::make_tuple(corps[i], flag);
				}
			}
			if (corps[i].getAffiliation() == 2) {
				if (step % 2 != 0) {
					str = "Its your corporation.";
					flag = 0;
					corps[i].setText(str);
					corps[i].setTextPosition(550, 120);
					window.draw(corps[i].text);
					return std::make_tuple(corps[i], flag);
				}
				else {
					str = "Take " + corps[i].getDonateStr();
					flag = 0;
					corps[i].setText(str);
					corps[i].setTextPosition(550, 120);
					window.draw(corps[i].text);
					return std::make_tuple(corps[i], flag);
				}
			}

		}
	}
}

void playerMoneyYes(int& stepFlag, int& step, int& flag, Player& player, corporation corpFlag, std::vector<corporation>& corps) {
	std::string corpName;
	for (auto& corp : corps) {
		corpName = corp.getName();
		if (corp == corpFlag) {
			switch (flag) {
			case 0:
				if (corpFlag.getAffiliation() == 0) {
					player.setMoney(player.getMoney() - corpFlag.getPrice());
					if (step % 2 == 0) {
						corp.setAffiliation(1);
						corp.setTextureobj("Images/corporationsGreen/" + corpName + ".png");
					}
					else {
						corp.setAffiliation(2);
						corp.setTextureobj("Images/corporationsRed/" + corpName + ".png");
					}
				}
				else if (corpFlag.getAffiliation() == 1) {
					if (step % 2 != 0) {
						player.setMoney(player.getMoney() - corpFlag.getDonate());
					}
				}
				else if (corpFlag.getAffiliation() == 2) {
					if (step % 2 == 0) {
						player.setMoney(player.getMoney() - corpFlag.getDonate());
					}
				}
				break;
			case 5:
				player.setMoney(player.getMoney() - corpFlag.getDonate());
				break;
			case 7:
				stepFlag = 1;
				break;
			case 13:
				player.setMoney(player.getMoney() + corpFlag.getDonate());
				break;
			case 19:
				stepFlag = 1;
				break;
			case 21:
				player.setMoney(player.getMoney() - corpFlag.getDonate());
				break;
			}
		}
	}
}