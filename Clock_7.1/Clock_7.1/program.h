#pragma once


#include <SFML/Graphics.hpp>
#include <Windows.h>


static const unsigned int WIDTH_WINDOW = 200;
static const unsigned int HEIGHT_WINDOW = 200;
static const float RADIUS_CLOCK_FACE = 100;
static const float WIDTH_HOUR_HAND = 65;
static const float HEIGHT_HOUR_HAND = 5;
static const float WIDTH_MINUTE_HAND = 75;
static const float HEIGHT_MINUTE_HAND = 3;
static const float WIDTH_SECOND_HAND = 95;
static const float HEIGHT_SECOND_HAND = 2;
static const float RADIUS_HOUR_CORE = 5;
static const float DEGREES_IN_CIRCLE = 360;
static const float COUNT_TIME_UNITS = 60;
static const float ELEMENTS_ON_CLOCK_FACE = 12;
static const float CORRECTION_UNIT = 10;
static const double PI = 3.14159265;
static const unsigned int FONT_SIZE = 14;


using namespace sf;
using namespace std;


struct Program {
	RenderWindow window;
};

struct ClockSynchronization {
	SYSTEMTIME systemTime;
};

struct ClockElements {
	CircleShape clockFace;
	RectangleShape hourHand;
	RectangleShape minuteHand;
	RectangleShape secondHand;
	CircleShape clockCore;
	Font font;
	Text hour;
	ClockSynchronization time;
};

void ActionProgram(Program &program, ClockElements &clock);