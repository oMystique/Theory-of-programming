#pragma once


#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


static const float COIL_RADIUS = 50.f;
static const Vector2i DEFAULT_WINDOW_SIZE = { 1280, 920 };
static const float GET_HALF = 2.0f;
static const float CORRECTION_UNIT = 30.f;
static const float CORRECTION_ANGLE = 30.f;
static const float BIG_GEAR_SPEED = 0.045f;
static const float SMALL_GEAR_SPEED = 0.05619f;
static const float PENDULUM_SPEED = 0.0301f;			
static const int APP_SPEED = 800;
static const Vector2f SMALL_GEAR_POINTS_ROTATION_TORIGHT = { 14.f, 15.f };
static const Vector2f SMALL_GEAR_POINTS_ROTATION_TOLEFT = { 341.f, 340.f }; 
static const Vector2f SMALL_GEAR_POINTS_ROTATION_STOP_LEFT = { 30.f, 25.f };
static const Vector2f SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT = { 270.f, 265.f };
static const Vector2f BIG_GEAR_POINTS_ROTATION_STOP_LEFT = { 258.f, 259.f };
static const Vector2f BIG_GEAR_POINTS_ROTATION_STOP_RIGHT = { 91.f, 92.f };
static const Vector2f BIG_GEAR_WIDTH_HEIGHT_ORIGIN = {105.f, 101.f};
static const Vector2f PENDULUM_POINTS_ROTATION_STOP_LEFT = { 46.f, 45.99f };
static const Vector2f PENDULUM_POINTS_ROTATION_STOP_RIGHT = { 314.f, 313.99f };
static const Vector2f PENDULUM_MIN_RESET_SPEED_LEFT = {35.f, 25.f};
static const Vector2f PENDULUM_MIN_RESET_SPEED_RIGHT = {335.f, 324.f};
static const Vector2f PENDULUM_MAX_RESET_SPEED_LEFT = {46.f, 36.f};
static const Vector2f PENDULUM_MAX_RESET_SPEED_RIGHT = {321.f, 320.f};
static const float PENDULUM_MIN_RESET_SPEED = 0.017f;
static const float PENDULUM_MAX_RESET_SPEED = 0.008f;
static const float THREAD_HEIGHT = 3.f;
