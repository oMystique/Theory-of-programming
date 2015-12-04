#pragma once
#include "resources.h"

struct Pendulum {
	Texture smallGearTexture;
	Texture bigGearTexture;
	Texture pendulumTexture;
	Sprite pendulumSprite;
	Sprite smallGearSprite;
	Sprite bigGearSprite;

	float bigGearSpeed;
	float smallGearSpeed;
	float pendulumSpeed;

	bool smallGearToRotate;

	void CreatePendulum();
	void CreateSmallGearWheel();
	void CreateBigGearWheel();

	void RotatePendulum(float &time);
	void RotateSmallGear(float &time);
	void RotateBigGear(float &time);
};