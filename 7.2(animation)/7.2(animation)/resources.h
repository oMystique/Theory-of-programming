#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <list>


using namespace std;
using namespace sf;


static const Vector2i DEFAULT_WINDOW_SIZE = { 800, 600 };
static const Vector2f DEFAULT_RECTANGLE_SIZE = { 40, 20 };
static const int FIGURES_COUNT = 5;
static const float GET_HALF = 2;
static const double MOVE_SPEED = 0.05;
static const double SCALE_STEP = 0.0001;
static const float ROTATE_ANGLE = 5;