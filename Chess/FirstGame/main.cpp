#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <Windows.h>
#include <map>

using namespace sf;
using namespace std;

////////////////////////////////////////////////////CLASS OF PLAYER////////////////////////
class Player { // класс Игрока
public:
	float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
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
	}

	///////////////////////FUNCTIONS OF CLASS PLAYER//////////////////////////////
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	}


	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	}
	void step_Peshka(int tempX, int tempY)
	{
		if (color == "white")
		{
			if ((abs(tempY - y - 78)) < 78 * 2)
				y -= 78;
			else
				y -= 78 * 2;
		}
		if (color == "black")
		{
			if ((abs(tempY - y)) < 78 * 2)
				y += 78;
			else
				y += 78 * 2;
		}
	}

	void step_Tower(int tempX, int tempY)
	{
			if (abs(x - tempX) < abs(y - tempY))
			{
				if (tempY < y)
				{
					while (y > tempY)
					{
						y -= 78;
					}
				}
				else
				{
					while ((y + 78) < tempY)
					{
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
						x -= 78;
					}
				}
				else
				{
					while ((x + 78) < tempX)
					{
						x += 78;
					}
				}
			}
	}

	void step_Ladya(int tempX, int tempY)
	{
		if (tempY < y)
		{
			if (tempX < x)
			{
				while ((x > tempX), (y > tempY))
				{
					y -= 78;
					x -= 78;
				}
			}
			else
			{
				while ((y > tempY), ((x + 78) < tempX))
				{
					y -= 78;
					x += 78;
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
				}
			}
			else
			{
				while (((y + 78) < tempY), (x > tempX))
				{
					y += 78;
					x -= 78;
				}
			}
		}
	}

	void step_Horse(int tempX, int tempY)
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
	}

	void step_King(int tempX, int tempY)
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
	}
};


using namespace sf;
int main()
{
	int tempX = 0; //временная коорд Х.Снимаем ее после нажатия прав клав мыши
	int tempY = 0; //коорд Y
	float distance = 0;//это расстояние от объекта до тыка курсора

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;
	RenderWindow window(sf::VideoMode(730, 730), "CHESS! Author: IldarkinAlexey; PS-22."); // создаём окно размером 730x730 (в нашем случае)
	Texture BGtexture;
	BGtexture.loadFromFile("images/chess.png");

	Sprite BGsprite;
	BGsprite.setTexture(BGtexture);
	BGsprite.setTextureRect(IntRect(2, 0, 730, 730)); //задаём координаты нашей фигурки [смотрим их в пэйнте]; (начало по х, по у, размер, размер);
	BGsprite.setPosition(0, 0); //выводим спрайт в позицию x y 

	std::list<Player*> players;
	std::list<Player*>::iterator it;
	std::list<Player*>::iterator at;

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

	bool isMove = false;
	float dX = 0;//корректировка движения по х
	float dY = 0;//по у

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed, isMove == false)//если нажата клавиша мыши
			{
				if (event.key.code == Mouse::Left)//а именно левая
				{
					for (it = players.begin(); it != players.end(); it++)
					{
						if ((*it)->sprite.getGlobalBounds().contains(pos.x, pos.y)) //и при этом координата курсора попадает в спрайт
						{
							((*it)->sprite).setColor(Color::Green);
							isMove = true;
							((*it)->isSelect) = true;
						}
					}
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
								break;
							}
						}
					}




			if (isMove)
			{
				for (it = players.begin(); it != players.end(); it++)
				{
					if ((*it)->isMove)
					{
						bool check_death = false;
						int count = 0;
						for (at = players.begin(); at != players.end(); at++)
						{
							if ((*it) != (*at))
							{
								float check_dist = (abs(((tempX - ((*it)->x + 39))*(((*at)->y + 39) - ((*it)->y + 39)) - (tempY - ((*it)->y + 39))*(((*at)->x + 39) - ((*it)->x + 39)))) / (sqrt(pow((tempX - ((*it)->x + 39)), 2) + pow((tempY - ((*it)->y + 39)), 2))));
								if (check_dist < 39.0)
								{
								//	std::cout << check_dist <<" x0"<<" " << (*at)->x <<" y0"<<" "<< (*at)->y << " x1"<<" "<<(*it)->x<<" y1"<<" "<< (*it)->y<< " x2" <<" "<< tempX << " y2" <<" "<< tempY << "\n";
									if ((abs(tempX - ((*it)->x)) > 39))
									{
										if (abs(tempY - ((*it)->y)) > 39)
										{
											if (tempX < ((*at)->x))
											{
												if (((*at)->x) < ((*it)->x))
												{
													if (tempY < (*at)->y)
													{
														if (((*at)->y) < ((*it)->y))
														{
															count += 1; 
														}
													}
													else
													{
														if (((*at)->y) > ((*it)->y))
														{
															count += 1;
														}
													}
												}
											}
											else
											{
												if (((*at)->x) > ((*it)->x))
												{
													if (tempY < ((*at)->y))
													{
														if (((*at)->y) < ((*it)->y))
														{
															count += 1;
														}
													}
													else
													{
														if (((*at)->y) > ((*it)->y))
														{
															count += 1;
														}
													}
												}
											}
										}
										else
										{
											if (tempX < ((*at)->x))
											{
												if ((*at)->x < (*it)->x)
												{
													count += 1;
												}
											}
											else
											{
												if (((*at)->x) > ((*it)->x))
												{
													count += 1;
												}
											}
										}
									}
									else
									{
										if (tempY < ((*at)->y))
										{
											if (((*at)->y) < ((*it)->y))
											{
												count += 1;
											}
										}
										else
										{
											if (((*at)->y) > ((*it)->y))
											{
												count += 1;
											}
										}
									}
								}
							}
							if (count == 1)
							{
								if (((*it)->color) != ((*at)->color))
								{
									check_death = true;
									isMove = true;
								}
								else
								{
									isMove = false;
									((*it)->isMove) = false;
									break;
								}
							}
							if ((count > 1) && (isMove))
							{
								check_death = false;
								isMove = false;
								((*it)->isMove) = false;
								break;
							}
						}
						if (isMove)
						{
							if ((*it)->type == "peshka")
							{
								(*it)->step_Peshka(tempX, tempY);
							}
							if ((*it)->type == "tower")
							{
								(*it)->step_Tower(tempX, tempY);
							}
							if ((*it)->type == "ladya")
							{
								(*it)->step_Ladya(tempX, tempY);
							}
							if ((*it)->type == "ferz")
							{
								if ((abs(tempX - ((*it)->x) - 39)) > 40)
								{
									if (abs(tempY - (*it)->y - 39) > 40)
									{
										(*it)->step_Ladya(tempX, tempY);
									}
									else
									{
										(*it)->step_Tower(tempX, tempY);
									}
								}
								else
								{
									(*it)->step_Tower(tempX, tempY);
								}
							}
							if ((*it)->type == "horse")
							{
								(*it)->step_Horse(tempX, tempY);
							}
							if ((*it)->type == "king")
							{
								(*it)->step_King(tempX, tempY);
							}
							((*it)->isMove) = false;
							isMove = false;
							if (check_death)
							{
								for (at = players.begin(); at != players.end(); at++)
								{
									if (((*it)->x) == ((*at)->x - 78))
									{
										if (((*it)->color) != ((*at)->color))
										{
											(*at)->life = false;
											(*at)->x += 1000;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		for (it = players.begin(); it != players.end();) 
		{
			Player*b = *it;
			b->update(time);
			if (b->life == false)
			{
				it = players.erase(it);
				delete(b);
			}
			else
			{
				it++;
			}
		}

		window.clear();
		window.draw(BGsprite);
		for (it = players.begin(); it != players.end(); it++) 
		{
			window.draw((*it)->sprite);
		}
		window.display();
	}

	return 0;
}