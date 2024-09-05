#include <vector>
#include "Process.h"
#include "Textures.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), L"Монополия");

	sf::Image icon;
	if (!icon.loadFromFile("Images/icon.png")) {
		return 1;
	}

	sf::Font font;
	if (!font.loadFromFile("Font/font.ttf"))
		return 0;

	window.setIcon(32, 32, icon.getPixelsPtr());

	//Background

	TexturedSprite<sf::Texture> Background("Images/Background.jpg");
	Background.setScaleobj(0.69f);

	//FrameGreen

	TexturedSprite<sf::Texture> FrameGreen("Images/Frame1.png");
	FrameGreen.setPositionobj(40, 110);

	sf::Text Frame1;
	Frame1.setFont(font);
	Frame1.setCharacterSize(24);
	Frame1.setFillColor(sf::Color::Green);
	Frame1.setString("GREEN");
	Frame1.setPosition(sf::Vector2f(100, 120));

	sf::Text GreenMoney;
	GreenMoney.setFont(font);
	GreenMoney.setCharacterSize(24);
	GreenMoney.setFillColor(sf::Color::White);
	GreenMoney.setPosition(sf::Vector2f(100, 280));

	//FrameRed

	TexturedSprite<sf::Texture> FrameRed("Images/Frame2.png");
	FrameRed.setPositionobj(40, 370);
	sf::Text Frame2;
	Frame2.setFont(font);
	Frame2.setCharacterSize(24);
	Frame2.setFillColor(sf::Color::Red);
	Frame2.setString("Red");
	Frame2.setPosition(sf::Vector2f(117, 380));

	sf::Text RedMoney;
	RedMoney.setFont(font);
	RedMoney.setCharacterSize(24);
	RedMoney.setFillColor(sf::Color::White);
	RedMoney.setPosition(sf::Vector2f(100, 550));

	//Center

	TexturedSprite<sf::Texture> Center("Images/Center.png");
	Center.setPositionobj(390, 110);

	//Change & Yes & No

	TexturedSprite<sf::Texture> Change("Images/ForText.png");
	Change.setPositionobj(1280, 1280);

	sf::Texture TextureYes;
	TextureYes.loadFromFile("Images/Yes.jpg");
	sf::Sprite Yes;
	Yes.setTexture(TextureYes);
	Yes.setPosition(sf::Vector2f(1280, 1280));

	sf::Texture TextureNo;
	TextureNo.loadFromFile("Images/No.jpg");
	sf::Sprite No;
	No.setTexture(TextureNo);
	No.setPosition(sf::Vector2f(1280, 1280));


	//Cubes

	Cube Cube1(1, "Images/Cubes/Cube1.png");
	Cube Cube2(2, "Images/Cubes/Cube2.png");
	Cube Cube3(3, "Images/Cubes/Cube3.png");
	Cube Cube4(4, "Images/Cubes/Cube4.png");
	Cube Cube5(5, "Images/Cubes/Cube5.png");
	Cube Cube6(6, "Images/Cubes/Cube6.png");
	Cube Cube11(1, "Images/Cubes/Cube1.png");
	Cube Cube22(2, "Images/Cubes/Cube2.png");
	Cube Cube33(3, "Images/Cubes/Cube3.png");
	Cube Cube44(4, "Images/Cubes/Cube4.png");
	Cube Cube55(5, "Images/Cubes/Cube5.png");
	Cube Cube66(6, "Images/Cubes/Cube6.png");

	//ChangeCubes

	sf::Texture TextureRoll1;
	TextureRoll1.loadFromFile("Images/Roll1.png");
	sf::Texture TextureRoll2;
	TextureRoll2.loadFromFile("Images/Roll2.png");
	sf::RectangleShape Roll(sf::Vector2f(200, 100));
	Roll.setTexture(&TextureRoll1);
	Roll.setPosition(sf::Vector2f(540, 360));

	//Corporations

	corporation LeftHigh("LeftHigh", 1, 0, 0, "Images/corporations/LeftHigh.png", font);
	LeftHigh.setPositionobj(280, 0);
	corporation Chanel("Chanel", 2, 600, 300, "Images/corporations/Chanel.png", font);
	Chanel.setPositionobj(390, 0);
	corporation Boss("Boss", 3, 600, 600, "Images/corporations/Boss.png", font);
	Boss.setPositionobj(490, 0);
	corporation Mercedes("Mercedes", 4, 2000, 1000, "Images/corporations/Mercedes.png", font);
	Mercedes.setPositionobj(590, 0);
	corporation Bank("Bank",5, 0, 2000, "Images/corporations/Bank.png", font);
	Bank.setPositionobj(690, 0);
	corporation Adidas("Adidas", 6, 1000, 900, "Images/corporations/Adidas.png", font);
	Adidas.setPositionobj(790, 0);
	corporation Escape("Escape", 7, 0, 0, "Images/corporations/Escape.png", font);
	Escape.setPositionobj(890, 0);
	corporation Puma("Puma", 8, 1000, 900, "Images/corporations/Puma.png", font);
	Puma.setPositionobj(890, 110);
	corporation Lacoste("Lacoste", 9, 1200, 1000, "Images/corporations/Lacoste.png", font);
	Lacoste.setPositionobj(890, 210);
	corporation Audi("Audi", 10, 2000, 1000, "Images/corporations/Audi.png", font);
	Audi.setPositionobj(890, 310);
	corporation Vk("Vk", 11, 1400, 1500, "Images/corporations/Vk.png", font);
	Vk.setPositionobj(890, 410);
	corporation Facebook("Facebook", 12, 1400, 1500, "Images/corporations/Facebook.png", font);
	Facebook.setPositionobj(890, 510);
	corporation Jackpot("Jackpot", 13, 0, 1000, "Images/corporations/Jackpot.png", font);
	Jackpot.setPositionobj(890, 610);
	corporation Twitter("Twitter", 14, 1600, 1800, "Images/corporations/Twitter.png", font);
	Twitter.setPositionobj(790, 610);
	corporation Coca_cola("Coca_cola", 15, 1800, 2000, "Images/corporations/Coca_cola.png", font);
	Coca_cola.setPositionobj(690, 610);
	corporation Ford("Ford", 16, 2000, 1000, "Images/corporations/Ford.png", font);
	Ford.setPositionobj(590, 610);
	corporation Pepsi("Pepsi", 17, 1800, 2000, "Images/corporations/Pepsi.png", font);
	Pepsi.setPositionobj(490, 610);
	corporation Fanta("Fanta", 18, 1000, 900, "Images/corporations/Fanta.png", font);
	Fanta.setPositionobj(390, 610);
	corporation Police("Police", 19, 0, 0, "Images/corporations/Police.png", font);
	Police.setPositionobj(280, 610);
	corporation Holiday("Holiday", 20, 3000, 3900, "Images/corporations/Holiday.png", font);
	Holiday.setPositionobj(280, 510);
	corporation Diamond("Diamond", 21, 0, 1000, "Images/corporations/Diamond.png", font);
	Diamond.setPositionobj(280, 410);
	corporation Land_Rover("Land_Rover", 22, 2000, 1000, "Images/corporations/Land_Rover.png", font);
	Land_Rover.setPositionobj(280, 310);
	corporation Radison("Radison", 23, 3000, 3900, "Images/corporations/Radison.png", font);
	Radison.setPositionobj(280, 210);
	corporation Novotel("Novotel", 24, 3000, 3900, "Images/corporations/Novotel.png", font);
	Novotel.setPositionobj(280, 110);

	//Corporations vector

	std::vector<corporation> corporations;
	corporations.push_back(LeftHigh);
	corporations.push_back(Chanel);
	corporations.push_back(Boss);
	corporations.push_back(Mercedes);
	corporations.push_back(Bank);
	corporations.push_back(Adidas);
	corporations.push_back(Escape);
	corporations.push_back(Puma);
	corporations.push_back(Lacoste);
	corporations.push_back(Audi);
	corporations.push_back(Vk);
	corporations.push_back(Facebook);
	corporations.push_back(Jackpot);
	corporations.push_back(Twitter);
	corporations.push_back(Coca_cola);
	corporations.push_back(Ford);
	corporations.push_back(Pepsi);
	corporations.push_back(Fanta);
	corporations.push_back(Police);
	corporations.push_back(Holiday);
	corporations.push_back(Diamond);
	corporations.push_back(Land_Rover);
	corporations.push_back(Radison);
	corporations.push_back(Novotel);

	//Players

	Player PlayerGreen("Images/PlayerGreen.png");
	Player PlayerRed("Images/PlayerRed.png");

	//End

	TexturedSprite<sf::Texture> End("Images/End.png");
	End.setPositionobj(1280, 1280);

	sf::Text EndGreen;
	EndGreen.setFont(font);
	EndGreen.setCharacterSize(50);
	EndGreen.setFillColor(sf::Color::Green);
	EndGreen.setString("Green Win!!!");
	EndGreen.setPosition(sf::Vector2f(1500, 1500));

	sf::Text EndRed;
	EndRed.setFont(font);
	EndRed.setCharacterSize(50);
	EndRed.setFillColor(sf::Color::Red);
	EndRed.setString("Red Win!!!");
	EndRed.setPosition(sf::Vector2f(1500, 1500));

	//Next

	sf::Clock clock;
	float timer = 0.f;
	float delay = 5.f;
	float delayEnd = 10.f;

	int step = 0;
	int stepFlag = 0;
	int x = 0;
	int flag = 0;
	corporation corpFlag("corpFlag", 0, 0, 0, "Images/corporations/LeftHigh.png", font);

	while (window.isOpen()) {
		sf::Event event;
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		x = 0;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseButtonPressed)
				if(event.mouseButton.button == sf::Mouse::Left)
					if (Roll.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						Roll.setTexture(&TextureRoll2);
					}
			if (event.type == sf::Event::MouseButtonReleased)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (Roll.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						Roll.setTexture(&TextureRoll1);

						int cube1 = randomCube();
						int cube2 = randomCube();
						switch (cube1) {
						case 0:
							Cube1.setPositionCube(490, 170);
							Cube1.drawCube(window);
							x += 1;
							break;
						case 1:
							Cube2.setPositionCube(490, 170);
							Cube2.drawCube(window);
							x += 2;
							break;
						case 2:
							Cube3.setPositionCube(490, 170);
							Cube3.drawCube(window);
							x += 3;
							break;
						case 3:
							Cube4.setPositionCube(490, 170);
							Cube4.drawCube(window);
							x += 4;
							break;
						case 4:
							Cube5.setPositionCube(490, 170);
							Cube5.drawCube(window);
							x += 5;
							break;
						case 5:
							Cube6.setPositionCube(490, 170);
							Cube6.drawCube(window);
							x += 6;
							break;
						}
						switch (cube2) {
						case 0:
							Cube11.setPositionCube(690, 170);
							Cube11.drawCube(window);
							x += 1;
							break;
						case 1:
							Cube22.setPositionCube(690, 170);
							Cube22.drawCube(window);
							x += 2;
							break;
						case 2:
							Cube33.setPositionCube(690, 170);
							Cube33.drawCube(window);
							x += 3;
							break;
						case 3:
							Cube44.setPositionCube(690, 170);
							Cube44.drawCube(window);
							x += 4;
							break;
						case 4:
							Cube55.setPositionCube(690, 170);
							Cube55.drawCube(window);
							x += 5;
							break;
						case 5:
							Cube66.setPositionCube(690, 170);
							Cube66.drawCube(window);
							x += 6;
							break;
						}
						if (step % 2 == 0) {
							std::tie(corpFlag, flag) = movePlayer(step, flag,window, x, PlayerGreen, corporations);

							Change.setPositionobj(390, 110);
							if (corpFlag.getCoord() != 1 && corpFlag.getCoord() != 5 && corpFlag.getCoord() != 7 && corpFlag.getCoord() != 19 && corpFlag.getCoord() != 21) {
								Yes.setPosition(sf::Vector2f(440, 485));
								No.setPosition(sf::Vector2f(750, 485));
							}
							else {
								Yes.setPosition(sf::Vector2f(440, 485));
								No.setPosition(sf::Vector2f(1280, 1280));
							}
						}
						else {
							std::tie(corpFlag, flag) = movePlayer(step, flag, window, x, PlayerRed, corporations);

							Change.setPositionobj(390, 110);
							if (corpFlag.getCoord() != (1, 5, 7, 19, 21)) {
								Yes.setPosition(sf::Vector2f(440, 485));
								No.setPosition(sf::Vector2f(750, 485));
							}
							else {
								Yes.setPosition(sf::Vector2f(440, 485));
							}
						}
					}

			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (Yes.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						if (step % 2 == 0) {
							playerMoneyYes(stepFlag, step, flag, PlayerGreen, corpFlag, corporations);
						}
						else {
							playerMoneyYes(stepFlag, step, flag, PlayerRed, corpFlag, corporations);
						}

						for (int i = 0; i < corporations.size(); i++) {
							corporations[i].setTextPosition(1280, 1280);
						}
						Change.setPositionobj(1280, 1280);
						Yes.setPosition(sf::Vector2f(1280, 1280));
						No.setPosition(sf::Vector2f(1280, 1280));
						
						if (stepFlag == 1) {
							if (step % 2 == 0) {
								step = 1;
							}
							else {
								step = 0;
							}
						}
						else {
							step += 1;
						}
					}

			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (No.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						for (int i = 0; i < corporations.size(); i++) {
							corporations[i].setTextPosition(1280, 1280);
						}
						Change.setPositionobj(1280, 1280);
						Yes.setPosition(sf::Vector2f(1280, 1280));
						No.setPosition(sf::Vector2f(1280, 1280));

						if (stepFlag == 1) {
							if (step % 2 == 0) {
								step = 1;
							}
							else {
								step = 0;
							}
						}
						else {
							step += 1;
						}
					}
		}

		sf::Time time = clock.restart();
		timer += time.asSeconds();

		if (timer >= delay) {
			Cube1.unvisible();
			Cube2.unvisible();
			Cube3.unvisible();
			Cube4.unvisible();
			Cube5.unvisible();
			Cube6.unvisible();
			Cube11.unvisible();
			Cube22.unvisible();
			Cube33.unvisible();
			Cube44.unvisible();
			Cube55.unvisible();
			Cube66.unvisible();
			timer = 0.0f;
		}

		if (PlayerGreen.getMoney() <= 0) {
			End.setPositionobj(0, 0);
			EndRed.setPosition(sf::Vector2f(540, 260));
			if (timer >= delayEnd) {
				return 0;
			}
		}
		else if (PlayerRed.getMoney() <= 0) {
			End.setPositionobj(0, 0);
			EndGreen.setPosition(sf::Vector2f(540, 260));
			if (timer >= delayEnd) {
				return 0;
			}
		}

		GreenMoney.setString(PlayerGreen.getMoneyStr());
		RedMoney.setString(PlayerRed.getMoneyStr());

		window.clear();
		Background.drawobj(window);
		Center.drawobj(window);

		FrameGreen.drawobj(window);
		window.draw(Frame1);
		window.draw(GreenMoney);
		FrameRed.drawobj(window);
		window.draw(Frame2);
		window.draw(RedMoney);

		for (int i = 0; i < corporations.size(); i++) {
			corporations[i].drawobj(window);
		}

		window.draw(Roll);

		Change.drawobj(window);
		for (int i = 0; i < corporations.size(); i++) {
			window.draw(corporations[i].text);
		}		
		window.draw(Yes);
		window.draw(No);

		Cube1.drawCube(window);
		Cube2.drawCube(window);
		Cube3.drawCube(window);
		Cube4.drawCube(window);
		Cube5.drawCube(window);
		Cube6.drawCube(window);
		Cube11.drawCube(window);
		Cube22.drawCube(window);
		Cube33.drawCube(window);
		Cube44.drawCube(window);
		Cube55.drawCube(window);
		Cube66.drawCube(window);

		PlayerGreen.drawobj(window);
		PlayerRed.drawobj(window);

		End.drawobj(window);
		window.draw(EndGreen);
		window.draw(EndRed);

		window.display();

	}

	return 0;
}