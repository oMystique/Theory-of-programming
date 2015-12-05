#pragma once


#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


static const Vector2i DEFAULT_WINDOW_SIZE = { 800, 600 };
static const float GET_HALF = 2.0f;
static const float CORRECTION_UNIT = 30.f;
static const float CORRECTION_ANGLE = 30.f;
static const float BIG_GEAR_SPEED = 0.0409f;
static const float SMALL_GEAR_SPEED = 0.058f;
static const float PENDULUM_SPEED = 0.025f;			
static const int APP_SPEED = 800;
static const Vector2f SMALL_GEAR_POINTS_ROTATION_TORIGHT = { 14.f, 15.f };
static const Vector2f SMALL_GEAR_POINTS_ROTATION_TOLEFT = { 341.f, 340.f }; 
static const Vector2f SMALL_GEAR_POINTS_ROTATION_STOP_LEFT = { 35.f, 30.f };
static const Vector2f SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT = { 275.f, 270.f };
static const Vector2f BIG_GEAR_POINTS_ROTATION_STOP_LEFT = { 270.f, 275.f };
static const Vector2f BIG_GEAR_POINTS_ROTATION_STOP_RIGHT = { 90.f, 95.f };
static const Vector2f BIG_GEAR_WIDTH_HEIGHT_ORIGIN = {105.f, 101.f};
static const Vector2f PENDULUM_POINTS_ROTATION_STOP_LEFT = { 31.f, 30.99f };
static const Vector2f PENDULUM_POINTS_ROTATION_STOP_RIGHT = { 322.f, 321.99f };
static const Vector2f PENDULUM_MIN_RESET_SPEED_LEFT = {25.f, 0.f};
static const Vector2f PENDULUM_MIN_RESET_SPEED_RIGHT = {360.f, 335.f};
static const Vector2f PENDULUM_MAX_RESET_SPEED_LEFT = {30.f, 25.f};
static const Vector2f PENDULUM_MAX_RESET_SPEED_RIGHT = {335.f, 330.f};
static const float PENDULUM_MIN_RESET_SPEED = 0.015f;
static const float PENDULUM_MAX_RESET_SPEED = 0.009f;
