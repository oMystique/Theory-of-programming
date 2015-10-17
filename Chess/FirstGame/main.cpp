#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <Windows.h>

using namespace sf;
using namespace std;

const float size_move = 78.0;
const float half_size_move = 39.0;
const string color_white = "white";
const string color_black = "black";
const string type_peshka = "peshka";
const string type_tower = "tower";
const string type_ladya = "ladya";
const string type_king = "king";
const string type_ferz = "ferz";
const string type_horse = "horse";
const string type_empty = "empty";
const string color_neutral = "neutral";
const int min_border_board = 52;
const int max_border_board = 660;
const string readyNone = "None.";
const string readyGo = "Go.";
const string readyNot = "Not.";

class Player { // ����� ������
public:
	float x, y, w, h; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	bool life, isMove, isSelect;
	String type, color;

	Player(String F, float X, float Y, float W, float H, String TYPE, String COLOR) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		life = true; isMove = false; isSelect = false;
		type = TYPE;
		color = COLOR;
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		image.loadFromFile("images/figures/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
		texture.loadFromImage(image);//���������� ���� ����������� � ��������
		sprite.setTexture(texture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
		sprite.setTextureRect(IntRect(0, 0, w, h));  //������ �������  �������������. IntRect - ���������� �����
	};

	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	};


	void update(float time) { //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
		sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	};

	bool step_Peshka(int tempX, int tempY) {
		if ((abs(tempX - (x + half_size_move)) > (half_size_move + 1)))
			step_Ladya(tempX, tempY);
		else {
			step_Tower(tempX, tempY);
		}
		return true;
	};

	bool step_Tower(int tempX, int tempY) {
		if (abs(x - tempX) < abs(y - tempY)) {
			if (tempY < y) {
				while (y > tempY) {
					if ((type == type_empty) || (type == type_peshka) || (type == type_king)) {
						y -= size_move;
						return false;
					}
					else
						y -= size_move;
				}
			}
			else {
				while ((y + size_move) < tempY) {
					if ((type == type_empty) || (type == type_peshka) || (type == type_king)) {
						y += size_move;
						return false;
					}
					else
						y += size_move;
				}
			}
		}
		else {
			if (tempX < x) {
				while (x > tempX) {
					if ((type == type_empty) || (type == type_peshka) || (type == type_king)) {
						x -= size_move;
						return false;
					}
					else
						x -= size_move;
				}
			}
			else {
				while ((x + size_move) < tempX) {
					if ((type == type_empty) || (type == type_peshka) || (type == type_king)) {
						x += size_move;
						return false;
					}
					else
						x += size_move;
				}
			}
		}
		return true;
	};

	bool step_Ladya(int tempX, int tempY) {
		if (tempY < y) {
			if (tempX < x) {
				while ((x > tempX), (y > tempY)) {
					y -= size_move;
					x -= size_move;
					if (type == type_empty || type == type_peshka || (type == type_king))
					{
						return false;
					}

				}
			}
			else {
				while ((y > tempY), ((x + size_move) < tempX)) {
					y -= size_move;
					x += size_move;
					if (type == type_empty || type == type_peshka || (type == type_king))
					{
						return false;
					}
				}
			}
		}
		else {
			if (tempX > x) {
				while (((y + size_move) < tempY), ((x + size_move) < tempX)) {
					y += size_move;
					x += size_move;
					if (type == type_empty || type == type_peshka || (type == type_king)) {
						return false;
					}
				}
			}
			else {
				while (((y + size_move) < tempY), (x > tempX)) {
					y += size_move;
					x -= size_move;
					if (type == type_empty || type == type_peshka || (type == type_king)) {
						return false;
					}
				}
			}
		}
		return true;
	};

	bool step_Horse(int tempX, int tempY) {
		if (abs(tempX - (x + half_size_move)) > abs(tempY - (y + half_size_move))) {
			if (tempX > x) {
				x += size_move * 2;
			}
			else {
				x -= size_move * 2;
			}
			if (tempY > y) {
				y += size_move;
			}
			else {
				y -= size_move;
			}
		}
		else {
			if (tempY > y) {
				y += size_move * 2;
			}
			else {
				y -= size_move * 2;
			}
			if (tempX > x) {
				x += size_move;
			}
			else {
				x -= size_move;
			}
		}
		return true;
	};


	bool step_Ferz(int tempX, int tempY) {
		if (abs(tempX - x - half_size_move) > (half_size_move + 1)) {
			if (abs(tempY - y - half_size_move) > (half_size_move + 1)) {
				return step_Ladya(tempX, tempY);
			}
			else {
				return step_Tower(tempX, tempY);
			}
		}
		else {
			return step_Tower(tempX, tempY);
		}
		return true;
	}
};


bool IdentifyType(string element_type, Player *tat, int tempX, int tempY) {
	if (element_type == type_peshka)
		return ((tat)->step_Peshka(tempX, tempY));
	else if (element_type == type_tower)
		return ((tat)->step_Tower(tempX, tempY));
	else if (element_type == type_ladya)
		return ((tat)->step_Ladya(tempX, tempY));
	else if (element_type == type_horse)
		return ((tat)->step_Horse(tempX, tempY));
	else if (element_type == type_ferz)
		return ((tat)->step_Ferz(tempX, tempY));
	else if (element_type == type_king)
		return ((tat)->step_Ferz(tempX, tempY));
}

string CheckLegalOfMove(list<Player*>players, Player *element, int tempX, int tempY) {
	std::list<Player*>::iterator at; //��� ��������� ���������
	std::list<Player*>::iterator that;
	string checkReady = readyNone;
	bool check;
	for (at = players.begin(); at != players.end(); at++) {
		if ((*at)->type == type_empty) {
			(*at)->x = element->x + 7;
			(*at)->y = element->y + 7;
			while (checkReady == readyNone) {
				IdentifyType(element->type, *at, tempX, tempY);
				for (that = players.begin(); that != players.end(); that++){
					if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (element))) {
						if ((IdentifyType(element->type, *at, tempX, tempY)) && ((element->color) != (*that)->color) && (((element->type == type_peshka) && (abs(tempX - (element->x + half_size_move)) > (half_size_move + 1))) || (element->type != type_peshka))) {
							checkReady = readyGo;
							(*that)->life = false;
							(*that)->sprite.setScale(0, 0);
							break;
						}
						else {
							checkReady = readyNot;
							element->isMove = false;
						}
						checkReady = readyNot;

					}
				}
				if ((checkReady == readyNone) && (element->type == type_peshka) && ((abs(tempX - (element->x + half_size_move)) > half_size_move)))
					checkReady = readyNot;
				else if ((IdentifyType(element->type, *at, tempX, tempY)) && (checkReady == readyNone)) {
					checkReady = readyGo;
				}
			}
		}
	}
	return checkReady;
};


int main(){
	std::list<Player*> players; //������ ������ �������� ������;
	std::list<Player*>::iterator it; //�������� ��� ��������� �������
	std::list<Player*>::iterator at; //��� ��������� ���������
	std::list<Player*>::iterator that; //��� ���������

	Font font;//����� 
	font.loadFromFile("CyrilicOld.ttf");//�������� ������ ������ ���� ������
	Text text("", font, 19);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
	text.setColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	text.setStyle(sf::Text::Italic | sf::Text::Underlined);//������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������

	int tempX = 0; //��������� ����� �.������� �� ����� ������� ���� ���� ����
	int tempY = 0; //����� Y
	float distance = 0;//��� ���������� �� ������� �� ���� �������

	float CurrentFrame = 0;//������ ������� ����
	Clock clock;
	RenderWindow window(sf::VideoMode(821, 730), "CHESS! Author: IldarkinAlexey; PS-22."); // ������ ���� �������� 821x730 (� ����� ������)
	Texture BGtexture;
	BGtexture.loadFromFile("images/chess.png");

	Texture Paneltexture;
	Paneltexture.loadFromFile("images/panel.png");

	Sprite BGsprite;
	BGsprite.setTexture(BGtexture);
	BGsprite.setTextureRect(IntRect(2, 0, 730, 730)); //����� ���������� ����� ������� [������� �� � ������]; (������ �� �, �� �, ������, ������);
	BGsprite.setPosition(0, 0); //������� ������ � ������� x y 

	Sprite Panelsprite;
	Panelsprite.setTexture(Paneltexture);
	Panelsprite.setTextureRect(IntRect(2, 0, 100, 730)); //����� ���������� ����� ������� [������� �� � ������]; (������ �� �, �� �, ������, ������);
	Panelsprite.setPosition(730, 0); //������� ������ � ������� x y 

	Texture exitButton_texture;
	exitButton_texture.loadFromFile("images/logout.png");

	Sprite exitButton_sprite;
	exitButton_sprite.setTexture(exitButton_texture);
	exitButton_sprite.setTextureRect(IntRect(0, 0, 32, 32));
	exitButton_sprite.setPosition(740, 5);

	Texture restartButton_texture;
	restartButton_texture.loadFromFile("images/restart.png");

	Sprite restartButton_sprite;
	restartButton_sprite.setTexture(restartButton_texture);
	restartButton_sprite.setTextureRect(IntRect(0, 0, 32, 32));
	restartButton_sprite.setPosition(774, 5);

	players.push_back(new Player("w_peshka.png", 53.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 131.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 209.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 287.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 365.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 443.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 521.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("w_peshka.png", 599.0, 524.0, size_move, size_move, type_peshka, color_white));
	players.push_back(new Player("b_peshka.png", 53.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 131.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 209.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 287.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 365.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 443.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 521.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_peshka.png", 599.0, 130.0, size_move, size_move, type_peshka, color_black));
	players.push_back(new Player("b_tower.png", 53.0, 53.0, size_move, size_move, type_tower, color_black));
	players.push_back(new Player("b_tower.png", 599.0, 53.0, size_move, size_move, type_tower, color_black));
	players.push_back(new Player("b_horse.png", 131.0, 53.0, size_move, size_move, type_horse, color_black));
	players.push_back(new Player("b_horse.png", 521.0, 53.0, size_move, size_move, type_horse, color_black));
	players.push_back(new Player("b_ladya.png", 209.0, 53.0, size_move, size_move, type_ladya, color_black));
	players.push_back(new Player("b_ladya.png", 443.0, 53.0, size_move, size_move, type_ladya, color_black));
	players.push_back(new Player("b_king.png", 365.0, 53.0, size_move, size_move, type_king, color_black));
	players.push_back(new Player("b_ferz.png", 287.0, 53.0, size_move, size_move, type_ferz, color_black));
	players.push_back(new Player("w_tower.png", 53.0, 602.0, size_move, size_move, type_tower, color_white));
	players.push_back(new Player("w_tower.png", 602.0, 602.0, size_move, size_move, type_tower, color_white));
	players.push_back(new Player("w_horse.png", 131.0, 602.0, size_move, size_move, type_horse, color_white));
	players.push_back(new Player("w_horse.png", 521.0, 602.0, size_move, size_move, type_horse, color_white));
	players.push_back(new Player("w_ladya.png", 209.0, 602.0, size_move, size_move, type_ladya, color_white));
	players.push_back(new Player("w_ladya.png", 443.0, 602.0, size_move, size_move, type_ladya, color_white));
	players.push_back(new Player("w_king.png", 365.0, 602.0, size_move, size_move, type_king, color_white));
	players.push_back(new Player("w_ferz.png", 287.0, 602.0, size_move, size_move, type_ferz, color_white));
	players.push_back(new Player("empty_sprite.png", 0.0, 0.0, 60.0, 60.0, type_empty, color_neutral));

	bool isMove = false;
	bool game = true;
	bool gameOVER = true;
	string moving_color = color_white;
	while ((window.isOpen())) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
		Vector2f pos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)
		sf::Event event;
		while ((window.pollEvent(event))) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (game)
				if (event.type == Event::MouseButtonPressed, !(isMove)) { //���� ������ ������� ���� 
					if (event.key.code == Mouse::Left) { //� ������ �����
						if (exitButton_sprite.getGlobalBounds().contains(pos.x, pos.y)) {
							window.close();
						}
						if (restartButton_sprite.getGlobalBounds().contains(pos.x, pos.y)) {
							window.close();
							main();
						}
						for (it = players.begin(); it != players.end(); it++) {
							if ((*it)->sprite.getGlobalBounds().contains(pos.x, pos.y)) { //� ��� ���� ���������� ������� �������� � ������
								if ((*it)->color == moving_color) {
									((*it)->sprite).setColor(Color::Green);
									isMove = true;
									((*it)->isSelect) = true;
								}
							}
						}
						if (!(isMove))
							break;
					}
				}

			if (isMove)//���� ������� ������
				if (event.type == Event::MouseButtonPressed)//���� ������ ������� ����
					if ((event.key.code == Mouse::Right) && ((min_border_board < pos.x) && ((max_border_board + 20) > pos.x)) && ((min_border_board < pos.y) && ((max_border_board + 20) > pos.y))) {
						for (it = players.begin(); it != players.end(); it++) {
							if (((*it)->isSelect) == true) {
								((*it)->isMove) = true;//�� �������� ��������
								((*it)->isSelect) = false;//������ ��� �� ������
								((*it)->sprite).setColor(Color::White);//���������� ������� ���� �������
								tempX = pos.x;//�������� ���������� ������� ������� �
								tempY = pos.y;//� Y
							}
						}
					}
					else {
						isMove = false;
						for (it = players.begin(); it != players.end(); it++) {
							if ((*it)->isSelect) {
								(*it)->isSelect = false;
								((*it)->sprite).setColor(Color::White);
							}
						}
					}
		}
		for (it = players.begin(); it != players.end(); it++) {
			if (((*it)->isMove) && (isMove)) {
				string checkReady = readyNone;
				if ((*it)->type == type_peshka) {
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						(*it)->step_Peshka(tempX, tempY);
						if (((*it)->color == color_white) && ((*it)->y < 60)) {
							(*it)->life = false;
							players.push_back(new Player("w_ferz.png", (*it)->x, (*it)->y, size_move, size_move, type_ferz, color_white));
						}
						if (((*it)->color == color_black) && (((*it)->y + size_move) > 650)) {
							(*it)->life = false;
							players.push_back(new Player("b_ferz.png", (*it)->x, (*it)->y, size_move, size_move, type_ferz, color_black));
						}
					}
				}
				if ((*it)->type == type_tower){
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						(*it)->step_Tower(tempX, tempY);
					}
				}
				if ((*it)->type == type_ladya) {
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						(*it)->step_Ladya(tempX, tempY);
					}
				}
				if ((*it)->type == type_ferz) {
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						(*it)->step_Ferz(tempX, tempY);
					}
				}
				if ((*it)->type == type_horse) {
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						float current_x = (*it)->x;
						float current_y = (*it)->y;
						(*it)->step_Horse(tempX, tempY);
						if (((min_border_board > (*it)->x) || (max_border_board < (*it)->x)) || (((min_border_board + 1) >(*it)->y) || (max_border_board < (*it)->y))) {
							(*it)->x = current_x;
							(*it)->y = current_y;
						}
					}
				}
				if ((*it)->type == type_king) {
					checkReady = CheckLegalOfMove(players, (*it), tempX, tempY);
					if (checkReady == readyGo) {
						(*it)->step_Peshka(tempX, tempY);
					}
				}
				((*it)->isMove) = false;
				isMove = false;
				if (checkReady == readyGo) {
					if (moving_color == color_white)
					{
						moving_color = color_black;
					}
					else
						moving_color = color_white;
				}
			}
		}
		window.clear();
		window.draw(BGsprite);
		window.draw(Panelsprite);
		for (it = players.begin(); it != players.end();) {
			Player*b = *it;
			b->update(time);
			if (b->life == false) {
				if (b->type == type_king) {
					gameOVER = false;
				}
				it = players.erase(it);
				delete(b);
			}
			else {
				it++;
			}
		}

		for (it = players.begin(); it != players.end(); it++) {
			if (gameOVER) {
				if (moving_color == color_white) {
					text.setString(color_white);//������ ������ ������
					text.setPosition(748, 649);//������ ������� ������, ����� ������
				}
				else {
					text.setString(color_black);//������ ������ ������
					text.setPosition(752, 63);//������ ������� ������, ����� ������
				}
			}
			else {
				text.setString("G\nA\nM\nE\n\nO\nV\nE\nR\n");//������ ������ ������
				text.setPosition(765, 295);//������ ������� ������, ����� ������
				window.draw(text);
				window.draw((*it)->sprite);
				game = false;
			}
			window.draw(text);//����� ���� �����
			window.draw((*it)->sprite);
		}
		window.draw(exitButton_sprite);
		window.draw(restartButton_sprite);
		window.display();
	}
	return 0;
}