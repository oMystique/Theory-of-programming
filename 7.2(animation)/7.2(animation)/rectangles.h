#pragma once
#include "application.h"

struct Rectangles {
	float scale;
	list<RectangleShape*> rectanglesList;
	list<RectangleShape*>::iterator currentRectangle;
};