#include "application.h"


void Animation::FirstStep() {
	int i = FIGURES_COUNT;
	bool flag = true;
	for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
		if (((*rectangles.currentRectangle)->getPosition().y) >= DEFAULT_WINDOW_SIZE.y - DEFAULT_RECTANGLE_SIZE.x * i) {
			flag = false;
			break;
		}
		else if ((*rectangles.currentRectangle)->getScale().x > (*rectangles.currentRectangle)->getScale().y / GET_HALF) {
			(*rectangles.currentRectangle)->setScale((*rectangles.currentRectangle)->getScale().x - SCALE_STEP, (*rectangles.currentRectangle)->getScale().y);
		}
		(*rectangles.currentRectangle)->move(0, MOVE_SPEED);
		i--;
	}
	if (!flag) {
		step = 2;
	}
}

void Animation::SecondStep() {
	bool flag = true;
	for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
		if (((*rectangles.currentRectangle)->getPosition().y) >= DEFAULT_WINDOW_SIZE.y - DEFAULT_RECTANGLE_SIZE.x) {
			flag = false;
			break;
		}
		(*rectangles.currentRectangle)->move(MOVE_SPEED, MOVE_SPEED);
	}
	if (!flag) {
		flag = true;
		for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
			if (((*rectangles.currentRectangle)->getPosition().x) >= DEFAULT_WINDOW_SIZE.x / GET_HALF + DEFAULT_RECTANGLE_SIZE.x * 2) {
				flag = false;
				break;
			}
			if ((*rectangles.currentRectangle)->getScale().y < GET_HALF - MOVE_SPEED) {
				(*rectangles.currentRectangle)->setScale((*rectangles.currentRectangle)->getScale().x + SCALE_STEP, (*rectangles.currentRectangle)->getScale().y + SCALE_STEP);
			}
			(*rectangles.currentRectangle)->move(MOVE_SPEED, 0);
		}
		if (!flag) {
			step = 3;
		}
	}
}
void Animation::ThirdStep() {
	bool flag = true;
	for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
		if (((*rectangles.currentRectangle)->getPosition().y) < DEFAULT_WINDOW_SIZE.y / GET_HALF - DEFAULT_RECTANGLE_SIZE.x) {
			flag = false;
			break;
		}
		(*rectangles.currentRectangle)->move(0, -MOVE_SPEED);
		(*rectangles.currentRectangle)->setFillColor(Color::Blue);
	}
	if (!flag) {
		step = 4;
	}
}
void Animation::FourthStep() {
	bool flag = true;
	for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
		if (((*rectangles.currentRectangle)->getPosition().x) >= DEFAULT_WINDOW_SIZE.x - DEFAULT_RECTANGLE_SIZE.x) {
			flag = false;
			break;
		}
		if (((*rectangles.currentRectangle)->getScale().y >= 1)) {
			(*rectangles.currentRectangle)->setScale((*rectangles.currentRectangle)->getScale().x - SCALE_STEP, (*rectangles.currentRectangle)->getScale().y - SCALE_STEP);
			(*rectangles.currentRectangle)->setFillColor(Color::Cyan);
		}
		(*rectangles.currentRectangle)->move(MOVE_SPEED, 0);
	}
	if (!flag) {
		flag = true;
		int i = 0;
		for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
			if (((*rectangles.currentRectangle)->getPosition().y) <= DEFAULT_RECTANGLE_SIZE.x * 2.5) {
				flag = false;
				break;
			}
			else if ((*rectangles.currentRectangle)->getPosition().x <= DEFAULT_WINDOW_SIZE.x - DEFAULT_RECTANGLE_SIZE.x) {
				(*rectangles.currentRectangle)->move(MOVE_SPEED, -MOVE_SPEED);
			}
			(*rectangles.currentRectangle)->setFillColor(Color::Magenta);
		}
		if (!flag) {
			step = 5;
		}
	}
}
void Animation::FifthStep() {
	bool flag = true;
	int i = FIGURES_COUNT;
	for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
		if (((*rectangles.currentRectangle)->getPosition().y) < DEFAULT_RECTANGLE_SIZE.x * i) {
			flag = false;
			break;
		}
		i--;
		(*rectangles.currentRectangle)->move(0, -MOVE_SPEED);
	}
	if (!flag) {
		flag = true;
		for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
			if (((*rectangles.currentRectangle)->getPosition().x) <= DEFAULT_RECTANGLE_SIZE.x) {
				flag = false;
				break;
			}
			(*rectangles.currentRectangle)->setFillColor(Color::Red);
			(*rectangles.currentRectangle)->rotate(ROTATE_ANGLE);
			(*rectangles.currentRectangle)->setScale(1, 1);
			(*rectangles.currentRectangle)->move(-MOVE_SPEED, 0);
		}
		if (!flag) {
			i = 1;
			flag = true;
			for (rectangles.currentRectangle = rectangles.rectanglesList.begin(); rectangles.currentRectangle != rectangles.rectanglesList.end(); rectangles.currentRectangle++) {
				(*rectangles.currentRectangle)->setPosition(DEFAULT_RECTANGLE_SIZE.x, DEFAULT_RECTANGLE_SIZE.x * i);
				(*rectangles.currentRectangle)->setRotation(0);
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