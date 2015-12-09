#pragma once


#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

static const float APP_SPEED = 800.f;
static const Vector2f DEFAULT_WINDOW_SIZE = { 1280, 720 };
static const float SCALE_OBJECTS = 0.5f;
static const float GET_HALF = 2.f;
static const float GET_THIRD = 3.f;
static const IntRect CAR_TEXTURE_RECT = { 43, 5, 829, 233 };
static const IntRect WHEEL_TEXTURE_RECT = { 145, 306, 130, 130 };
static const float BODY_CORRECTION_FOR_WHEEL = 4.7f;
static const Vector2f LEFT_WHEEL_CORRECTION_FOR_BODY = { 90.5f, 98.f };
static const float RIGHT_WHEEL_CORRECTION_FOR_BODY = 340.5f;
static const Color ROAD_COLOR = { 131, 139, 139 };
static const float CAR_MAXIMUM_SPEED = 0.1f;
static const float CAR_MINIMUM_SPEED = CAR_MAXIMUM_SPEED / 2000.f;
static const float BORDER_UNIT = 50.f;