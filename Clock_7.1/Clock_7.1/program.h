#pragma once
#include <SFML/Graphics.hpp>

static const float WIDTH_WINDOW = 200;
static const float HEIGHT_WINDOW = 200;
static const float RADIUS_CLOCK_FACE = 100;
static const float WIDTH_HOUR_HAND = 65;
static const float HEIGHT_HOUR_HAND = 5;
static const float WIDTH_MINUTE_HAND = 75;
static const float HEIGHT_MINUTE_HAND = 3;
static const float WIDTH_SECOND_HAND = 95;
static const float HEIGHT_SECOND_HAND = 2;

using namespace sf;
using namespace std;

struct Program {
	RenderWindow window;
};

struct ClockElements {
	CircleShape clockFace;
	RectangleShape hourHand;
	RectangleShape minuteHand;
	RectangleShape secondHand;
};

void ActionProgram(Program &program, ClockElements &clock);