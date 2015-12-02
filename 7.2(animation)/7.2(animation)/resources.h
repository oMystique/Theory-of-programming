#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <list>


using namespace std;
using namespace sf;


const Vector2i DEFAULT_WINDOW_SIZE = { 800, 600 };
const Vector2f DEFAULT_RECTANGLE_SIZE = { 40, 20 };
const int FIGURES_COUNT = 5;
const float GET_HALF = 2;
const double MOVE_SPEED = 0.05;
const double SCALE_STEP = 0.0001;
const float ROTATE_ANGLE = 5;