#pragma once
#include "resources.h"

struct Pendulum {
	Texture smallGearTexture;
	Texture bigGearTexture;
	Texture pendulumTexture;
	Sprite pendulumSprite;
	Sprite topSmallGearSprite;
	Sprite bigGearSprite;
	Sprite leftBotSmallGearSprite;
	Sprite rightBotSmallGearSprite;
	Sprite left2BotSmallGearSprite;
	Sprite right2BotSmallGearSprite;

	RectangleShape threadLeft;
	RectangleShape threadRight;

	CircleShape coilLeft;
	CircleShape coilRight;

	float bigGearSpeed;
	float topSmallGearSpeed;
	float pendulumSpeed;
	float botSmallGearSpeed;

	bool smallGearToRotate;

	void CreatePendulum();
	void CreateTopSmallGearWheel();
	void CreateBigGearWheel();
	void CreateBotSmallGears();
	void CreateThreads();

	void RotatePendulum(float &time);
	void RotateTopSmallGear(float &time);
	void RotateBotSmallGears(float &time);
	void RotateBigGear(float &time);
};