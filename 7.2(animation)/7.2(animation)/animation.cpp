#include "application.h"


void Animation::FirstStep() {
	int i = FIGURES_COUNT;
	bool flag = true;
	for (RectangleShape *currentRect : rectangles.rectanglesList) {
		if ((currentRect->getPosition().y) >= DEFAULT_WINDOW_SIZE.y - DEFAULT_RECTANGLE_SIZE.x * i) {
			flag = false;
			break;
		}
		else if (currentRect->getScale().x > currentRect->getScale().y / GET_HALF) {
			currentRect->setScale(currentRect->getScale().x - SCALE_STEP, currentRect->getScale().y);
		}
		currentRect->move(0, MOVE_SPEED);
		i--;
	}
	if (!flag) {
		step = 2;
	}
}

void Animation::SecondStep() {
	bool flag = true;
	for (RectangleShape *currentRect : rectangles.rectanglesList) {
		if ((currentRect->getPosition().y) >= DEFAULT_WINDOW_SIZE.y - DEFAULT_RECTANGLE_SIZE.x) {
			flag = false;
			break;
		}
		currentRect->move(MOVE_SPEED, MOVE_SPEED);
	}
	if (!flag) {
		flag = true;
		for (RectangleShape *currentRect : rectangles.rectanglesList) {
			if ((currentRect->getPosition().x) >= DEFAULT_WINDOW_SIZE.x / GET_HALF + DEFAULT_RECTANGLE_SIZE.x * 2) {
				flag = false;
				break;
			}
			if (currentRect->getScale().y < GET_HALF - MOVE_SPEED) {
				currentRect->setScale(currentRect->getScale().x + SCALE_STEP, currentRect->getScale().y + SCALE_STEP);
			}
			currentRect->move(MOVE_SPEED, 0);
		}
		if (!flag) {
			step = 3;
		}
	}
}
void Animation::ThirdStep() {
	bool flag = true;
	for (RectangleShape *currentRect : rectangles.rectanglesList) {
		if ((currentRect->getPosition().y) < DEFAULT_WINDOW_SIZE.y / GET_HALF - DEFAULT_RECTANGLE_SIZE.x) {
			flag = false;
			break;
		}
		(currentRect)->move(0, -MOVE_SPEED);
		(currentRect)->setFillColor(Color::Blue);
	}
	if (!flag) {
		step = 4;
	}
}
void Animation::FourthStep() {
	bool flag = true;
	for (RectangleShape *currentRect : rectangles.rectanglesList) {
		if (((currentRect->getPosition().x) >= DEFAULT_WINDOW_SIZE.x - DEFAULT_RECTANGLE_SIZE.x)) {
			flag = false;
			break;
		}
		if ((currentRect->getScale().y >= 1)) {
			currentRect->setScale(currentRect->getScale().x - SCALE_STEP, currentRect->getScale().y - SCALE_STEP);
			currentRect->setFillColor(Color::Cyan);
		}
		currentRect->move(MOVE_SPEED, 0);
	}
	if (!flag) {
		flag = true;
		int i = 0;
		for (RectangleShape *currentRect : rectangles.rectanglesList) {
			if ((currentRect->getPosition().y) <= DEFAULT_RECTANGLE_SIZE.x * 2.5) {
				flag = false;
				break;
			}
			else if (currentRect->getPosition().x <= DEFAULT_WINDOW_SIZE.x - DEFAULT_RECTANGLE_SIZE.x) {
				currentRect->move(MOVE_SPEED, -MOVE_SPEED);
			}
			currentRect->setFillColor(Color::Magenta);
		}
		if (!flag) {
			step = 5;
		}
	}
}
void Animation::FifthStep() {
	bool flag = true;
	int i = FIGURES_COUNT;
	for (RectangleShape *currentRect : rectangles.rectanglesList) {
		if ((currentRect->getPosition().y) < DEFAULT_RECTANGLE_SIZE.x * i) {
			flag = false;
			break;
		}
		i--;
		currentRect->move(0, -MOVE_SPEED);
	}
	if (!flag) {
		flag = true;
		for (RectangleShape *currentRect : rectangles.rectanglesList) {
			if ((currentRect->getPosition().x) <= DEFAULT_RECTANGLE_SIZE.x) {
				flag = false;
				break;
			}
			currentRect->setFillColor(Color::Red);
			currentRect->rotate(ROTATE_ANGLE);
			currentRect->setScale(1, 1);
			currentRect->move(-MOVE_SPEED, 0);
		}
		if (!flag) {
			i = 1;
			flag = true;
			for (RectangleShape *currentRect : rectangles.rectanglesList) {
				currentRect->setPosition(DEFAULT_RECTANGLE_SIZE.x, DEFAULT_RECTANGLE_SIZE.x * i);
				currentRect->setRotation(0);
				i++;
				if (i == FIGURES_COUNT) {
					flag = false;
				}
			}
			if (!flag) {
				step = 1;
			}
		}
	}
}