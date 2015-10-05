#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <Windows.h>

using namespace sf;
using namespace std;

////////////////////////////////////////////////////CLASS OF PLAYER////////////////////////
class Player { // класс Игрока
public:
	float x, y, w, h; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	bool life, isMove, isSelect;
	String type, color; 

	Player(String F, float X, float Y, float W, float H, String TYPE, String COLOR) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		life = true; isMove = false; isSelect = false;
		type = TYPE;
		color = COLOR;
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("images/figures/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
		texture.loadFromImage(image);//закидываем наше изображение в текстуру
		sprite.setTexture(texture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		sprite.setTextureRect(IntRect(0, 0, w, h));  //Задаем спрайту  прямоугольник. IntRect - приведение типов
	};

	///////////////////////FUNCTIONS OF CLASS PLAYER//////////////////////////////
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	};


	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	};

	bool step_Peshka(int tempX, int tempY)
	{
		if (tempY < y)
		{
			y -= 78;
		}
		else
		{
			if ((abs(tempY - y)) < 78 * 2)
				y += 78;
		}
		return true;
	};

	bool step_Tower(int tempX, int tempY)
	{
			if (abs(x - tempX) < abs(y - tempY))
			{
				if (tempY < y)
				{
					while (y > tempY)
					{
						if ((type == "empty"))
						{
							y -= 39;
							return false;
						}
						else
							y -= 78;
					}
				}
				else
				{
					while ((y + 78) < tempY)
					{
						if (type == "empty")
						{
							y += 78;
							return false;
						}
						else
							y += 78;
					}
				}	
			}
			else
			{
				if (tempX < x)
				{
					while (x > tempX)
					{
						if (type == "empty")
						{
							x -= 39;
							return false;
						}
						else
							x -= 78;
					}
				}
				else
				{
					while ((x + 78) < tempX)
					{
						if (type == "empty")
						{
							x += 39;
							return false;
						}
						else
							x += 78;
					}
				}
			}
		return true;
	};

	bool step_Ladya(int tempX, int tempY)
	{
		if (tempY < y)
		{
			if (tempX < x)
			{
				while ((x > tempX), (y > tempY))
				{
					y -= 78;
					x -= 78;
					if (type == "empty")
					{
						return false;
					}

				}
			}
			else
			{
				while ((y > tempY), ((x + 78) < tempX))
				{
					y -= 78;
					x += 78;
					if (type == "empty")
					{
						return false;
					}
				}
			}
		}
		else
		{
			if (tempX > x)
			{
				while (((y + 78) < tempY), ((x + 78) < tempX))
				{
					y += 78;
					x += 78;
					if (type == "empty")
					{
						return false;
					}
				}
			}
			else
			{
				while (((y + 78) < tempY), (x > tempX))
				{
					y += 78;
					x -= 78;
					if (type == "empty")
					{
						return false;
					}
				}
			}
		}
		return true;
	};

	bool step_Horse(int tempX, int tempY)
	{
		if (abs(tempX - x) > abs(tempY - y))
		{
			if (tempX > x)
			{
				x += 78 * 2;
			}
			else
			{
				x -= 78 * 2;
			}
			if (tempY > y)
			{
				y += 78;
			}
			else
			{
				y -= 78;
			}
		}
		else
		{
			if (tempY > y)
			{
				y += 78 * 2;
			}
			else
			{
				y -= 78 * 2;
			}
			if (tempX > x)
			{
				x += 78;
			}
			else
			{
				x -= 78;
			}
		}
		return true;
	};

	bool step_King(int tempX, int tempY)
	{
		if (abs(abs(x + 39 - tempX) - abs(y + 39 - tempY)) > 40)
		{
			if (abs(x - tempX) < abs(y - tempY))
			{
				if (tempY < y)
				{
					y -= 78;
				}
				else
				{
					y += 78;
				}
			}
			else
			{
				if (tempX < x)
				{
					x -= 78;
				}
				else
				{
					x += 78;
				}
			}
		}
		else
		{
			if (tempY < y)
			{
				if (tempX < x)
				{
						y -= 78;
						x -= 78;
				}
				else
				{
						y -= 78;
						x += 78;
				}
			}
			else
			{
				if (tempX > x)
				{
						y += 78;
						x += 78;
				}
				else
				{
						y += 78;
						x -= 78;
				}
			}
		}
		return true;;
	};

	bool step_Ferz(int tempX, int tempY)
	{
		if (abs(tempX - x - 39) > 40)
		{
			if (abs(tempY - y - 39) > 40)
			{
				return step_Ladya(tempX, tempY);
			}
			else
			{
				return step_Tower(tempX, tempY);
			}
		}
		else
		{
			return step_Tower(tempX, tempY);
		}
		return true;
	}
};


using namespace sf;
int main()
{
	std::list<Player*> players;
	std::list<Player*>::iterator it;
	std::list<Player*>::iterator at;
	std::list<Player*>::iterator that;

	Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 19);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

	int tempX = 0; //временная коорд Х.Снимаем ее после нажатия прав клав мыши
	int tempY = 0; //коорд Y
	float distance = 0;//это расстояние от объекта до тыка курсора

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;
	RenderWindow window(sf::VideoMode(821, 730), "CHESS! Author: IldarkinAlexey; PS-22."); // создаём окно размером 730x730 (в нашем случае)
	Texture BGtexture;
	BGtexture.loadFromFile("images/chess.png");

	Texture Paneltexture;
	Paneltexture.loadFromFile("images/panel.png");

	Sprite BGsprite;
	BGsprite.setTexture(BGtexture);
	BGsprite.setTextureRect(IntRect(2, 0, 730, 730)); //задаём координаты нашей фигурки [смотрим их в пэйнте]; (начало по х, по у, размер, размер);
	BGsprite.setPosition(0, 0); //выводим спрайт в позицию x y 

	Sprite Panelsprite;
	Panelsprite.setTexture(Paneltexture);
	Panelsprite.setTextureRect(IntRect(2, 0, 100, 730)); //задаём координаты нашей фигурки [смотрим их в пэйнте]; (начало по х, по у, размер, размер);
	Panelsprite.setPosition(730, 0); //выводим спрайт в позицию x y 

	/*Sprite Board;
	Board.setTexture(BGtexture);
	Board.setTextureRect(IntRect(51, 51, 680, 680));*/

	players.push_back(new Player("w_peshka.png", 53.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 131.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 209.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 287.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 365.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 443.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 521.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("w_peshka.png", 599.0, 524.0, 78.0, 78.0, "peshka", "white"));
	players.push_back(new Player("b_peshka.png", 53.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 131.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 209.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 287.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 365.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 443.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 521.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_peshka.png", 599.0, 130.0, 78.0, 78.0, "peshka", "black"));
	players.push_back(new Player("b_tower.png", 53.0, 53.0, 78.0, 78.0, "tower", "black"));
	players.push_back(new Player("b_tower.png", 599.0, 53.0, 78.0, 78.0, "tower", "black"));
	players.push_back(new Player("b_horse.png", 131.0, 53.0, 78.0, 78.0, "horse", "black"));
	players.push_back(new Player("b_horse.png", 521.0, 53.0, 78.0, 78.0, "horse", "black"));
	players.push_back(new Player("b_ladya.png", 209.0, 53.0, 78.0, 78.0, "ladya", "black"));
	players.push_back(new Player("b_ladya.png", 443.0, 53.0, 78.0, 78.0, "ladya", "black"));
	players.push_back(new Player("b_king.png", 365.0, 52.0, 78.0, 78.0, "king", "black"));
	players.push_back(new Player("b_ferz.png", 287.0, 52.0, 78.0, 78.0, "ferz", "black"));
	players.push_back(new Player("w_tower.png", 53.0, 602.0, 78.0, 78.0, "tower", "white"));
	players.push_back(new Player("w_tower.png", 602.0, 602.0, 78.0, 78.0, "tower", "white"));
	players.push_back(new Player("w_horse.png", 131.0, 602.0, 78.0, 78.0, "horse", "white"));
	players.push_back(new Player("w_horse.png", 521.0, 602.0, 78.0, 78.0, "horse", "white"));
	players.push_back(new Player("w_ladya.png", 209.0, 602.0, 78.0, 78.0, "ladya", "white"));
	players.push_back(new Player("w_ladya.png", 443.0, 602.0, 78.0, 78.0, "ladya", "white"));
	players.push_back(new Player("w_king.png", 365.0, 602.0, 78.0, 78.0, "king", "white"));
	players.push_back(new Player("w_ferz.png", 287.0, 602.0, 78.0, 78.0, "ferz", "white"));
	players.push_back(new Player("empty_sprite.png", 0.0, 0.0, 60.0, 60.0, "empty", "neutral"));

	bool isMove = false;
	float dX = 0;//корректировка движения по х
	float dY = 0;//по у
	bool game = true;
	bool gameOVER = true;
	string moving_color = "white";

	while ((window.isOpen()))
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
		sf::Event event;
		while ((window.pollEvent(event)))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (game)
			
			if (event.type == Event::MouseButtonPressed, isMove == false)//если нажата клавиша мыши
			{
				if (event.key.code == Mouse::Left)//а именно левая
				{
					for (it = players.begin(); it != players.end(); it++)
					{
						if ((*it)->sprite.getGlobalBounds().contains(pos.x, pos.y)) //и при этом координата курсора попадает в спрайт
						{
							if ((*it)->color == moving_color)
							{
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

			if (isMove)//если выбрали объект
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == Mouse::Right) //правая
					{
						for (it = players.begin(); it != players.end(); it++)
						{
							if (((*it)->isSelect) == true)
							{
								((*it)->isMove) = true;//то начинаем движение
								((*it)->isSelect) = false;//объект уже не выбран
								((*it)->sprite).setColor(Color::White);//возвращаем обычный цвет спрайту
								tempX = pos.x;//забираем координату нажатия курсора Х
								tempY = pos.y;//и Y
							}
						}
					}
					else
					{
						isMove = false;
						for (it = players.begin(); it != players.end(); it++)
						{
							if ((*it)->isSelect)
							{
								(*it)->isSelect = false;
								((*it)->sprite).setColor(Color::White);
							}
						}
					}
		}
			for (it = players.begin(); it != players.end(); it++)
			{
				if ((*it)->isMove)
				{
					if (isMove)
					{
						string checkReady = "None.";
						if ((*it)->type == "peshka")
						{
							if (checkReady == "None.")
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if ((*at)->type == "empty")
									{
										(*at)->x = (*it)->x + 7;
										(*at)->y = (*it)->y + 7;
										while (checkReady == "None.")
										{
											(*at)->step_Peshka(tempX, tempY);
											for (that = players.begin(); that != players.end(); that++)
											{
												if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (*it)))
												{
													if (((*at)->step_Peshka(tempX, tempY)) && ((*it)->color != (*that)->color))
													{
														checkReady = "Go.";
														(*that)->life = false;
														(*that)->sprite.setScale(0, 0);
														break;
													}
													else
													{
														checkReady = "Not.";
														isMove = false;
														(*it)->isMove = false;
													}
													checkReady = "Not.";

												}
											}
											if (((*at)->step_Peshka(tempX, tempY)) && (checkReady == "None."))
											{
												checkReady = "Go.";
											}
										}
									}
								}
							}
							if (checkReady == "Go.")
							{
								(*it)->step_Peshka(tempX, tempY);
							}
						}
						if ((*it)->type == "tower")
						{
							if (checkReady == "None.")
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if ((*at)->type == "empty")
									{
										(*at)->x = (*it)->x + 7;
										(*at)->y = (*it)->y + 7;
										while (checkReady == "None.")
										{
											std::cout << (*at)->y << " at" << "\n";
											(*at)->step_Tower(tempX, tempY);
											for (that = players.begin(); that != players.end(); that++)
											{
												std::cout << "*";
												if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (*it)))
												{
													std::cout << (*that)->y <<" that"<< "\n";
													//distance = abs(((tempX - (*at)->x)*((*that)->y - (*at)->y) - (tempY - (*at)->y)*((*that)->x - (*at)->x)) / sqrt(pow((tempX - (*at)->x), 2) + pow(((tempY)-(*at)->y), 2)));
													if (((*at)->step_Tower(tempX, tempY)) && ((*it)->color != (*that)->color))
													{
														checkReady = "Go.";
														(*that)->life = false;
														(*that)->sprite.setScale(0, 0);
														break;
													}
													else
													{
														checkReady = "Not.";
														isMove = false;
														(*it)->isMove = false;
													}
													checkReady = "Not.";

												}
											}
											if (((*at)->step_Tower(tempX, tempY)) && (checkReady == "None."))
											{
												checkReady = "Go.";
											}
											std::cout << "\n" << "flag=true" << "\n";
										}
									}
								}
							}
							if (checkReady == "Go.")
							{
								(*it)->step_Tower(tempX, tempY);
							}
						}
						if ((*it)->type == "ladya")
						{
							if (checkReady == "None.")
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if ((*at)->type == "empty")
									{
										(*at)->x = (*it)->x + 7;
										(*at)->y = (*it)->y + 7;
										while (checkReady == "None.")
										{
											(*at)->step_Ladya(tempX, tempY);
											for (that = players.begin(); that != players.end(); that++)
											{
												if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (*it)))
												{
													if (((*at)->step_Ladya(tempX, tempY)) && ((*it)->color != (*that)->color))
													{
														checkReady = "Go.";
														(*that)->life = false;
														(*that)->sprite.setScale(0, 0);
														break;
													}
													else
													{
														checkReady = "Not.";
														isMove = false;
														(*it)->isMove = false;
													}
													checkReady = "Not.";

												}
											}
											if (((*at)->step_Ladya(tempX, tempY)) && (checkReady == "None."))
											{
												checkReady = "Go.";
											}
										}
									}
								}
							}
							if (checkReady == "Go.")
							{
								(*it)->step_Ladya(tempX, tempY);
							}
						}
						if ((*it)->type == "ferz")
						{
							if (checkReady == "None.")
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if ((*at)->type == "empty")
									{
										(*at)->x = (*it)->x + 7;
										(*at)->y = (*it)->y + 7;
										while (checkReady == "None.")
										{
											(*at)->step_Ladya(tempX, tempY);
											for (that = players.begin(); that != players.end(); that++)
											{
												if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (*it)))
												{
													if (((*at)->step_Ferz(tempX, tempY)) && ((*it)->color != (*that)->color))
													{
														checkReady = "Go.";
														(*that)->life = false;
														(*that)->sprite.setScale(0, 0);
														break;
													}
													else
													{
														checkReady = "Not.";
														isMove = false;
														(*it)->isMove = false;
													}
													checkReady = "Not.";

												}
											}
											if (((*at)->step_Ferz(tempX, tempY)) && (checkReady == "None."))
											{
												checkReady = "Go.";
											}
										}
									}
								}
							}
							if (checkReady == "Go.")
							{
								(*it)->step_Ferz(tempX, tempY);
							}
						}
						if ((*it)->type == "horse")
						{
							(*it)->step_Horse(tempX, tempY);
						}
						if ((*it)->type == "king")
						{
							if (checkReady == "None.")
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if ((*at)->type == "empty")
									{
										(*at)->x = (*it)->x + 7;
										(*at)->y = (*it)->y + 7;
										while (checkReady == "None.")
										{
											(*at)->step_King(tempX, tempY);
											for (that = players.begin(); that != players.end(); that++)
											{
												if (((*at)->getRect().intersects((*that)->getRect())) && ((*at) != (*that)) && ((*that) != (*it)))
												{
													if (((*at)->step_King(tempX, tempY)) && ((*it)->color != (*that)->color))
													{
														checkReady = "Go.";
														(*that)->life = false;
														(*that)->sprite.setScale(0, 0);
														break;
													}
													else
													{
														checkReady = "Not.";
														isMove = false;
														(*it)->isMove = false;
													}
													checkReady = "Not.";

												}
											}
											if (((*at)->step_King(tempX, tempY)) && (checkReady == "None."))
											{
												checkReady = "Go.";
											}
										}
									}
								}
							}
							if (checkReady == "Go.")
							{
								(*it)->step_King(tempX, tempY);
							}
						}
						((*it)->isMove) = false;
						isMove = false;
						if (moving_color == "white")
						{
							moving_color = "black";
						}
						else
							moving_color = "white";
					}
				}
			}
		window.clear();
		window.draw(BGsprite);
		window.draw(Panelsprite);
		for (it = players.begin(); it != players.end();) 
		{
			Player*b = *it;
			b->update(time);
			if (b->life == false)
			{
				if (b->type == "king")
				{
					gameOVER = false;
				}
				it = players.erase(it);
				delete(b);
			}
			else
			{
				it++;
			}
		}

		for (it = players.begin(); it != players.end(); it++) 
		{
			if (gameOVER)
			{
				if (moving_color == "white")
				{
					text.setString("White");//задает строку тексту
					text.setPosition(748, 649);//задаем позицию текста, центр камеры
				}
				else
				{
					text.setString("Black");//задает строку тексту
					text.setPosition(752, 63);//задаем позицию текста, центр камеры
				}
			}
			else
			{
				text.setString("G\nA\nM\nE\n\nO\nV\nE\nR\n");//задает строку тексту
				text.setPosition(765, 295);//задаем позицию текста, центр камеры
				window.draw(text);
				window.draw((*it)->sprite);
				game = false;
			}
			window.draw(text);//рисую этот текст
			window.draw((*it)->sprite);
		}
		window.display();
	}

	return 0;
}