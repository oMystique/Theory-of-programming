#pragma once
#include "resources.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct Car {
	Car();
	Texture carTexture;
	Sprite bodySprite;
	Sprite leftWheelSprite;
	Sprite rightWheelSprite;

	float rotation;
	float speed;

	void CreateCarElements();
	void SetPositionCarElements();
	void MoveCar(float &time);
};