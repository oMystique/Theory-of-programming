#include "application.h"

void Pendulum::CreatePendulum() {
	pendulumTexture.loadFromFile("images/_pendulum.png");
	pendulumSprite.setTexture(pendulumTexture);
	pendulumSprite.setOrigin(pendulumSprite.getGlobalBounds().width / GET_HALF, pendulumSprite.getGlobalBounds().width / GET_HALF + GET_HALF);
	pendulumSprite.setPosition(smallGearSprite.getPosition().x, smallGearSprite.getPosition().y);
	pendulumSprite.rotate(CORRECTION_ANGLE);
	pendulumSpeed = 0;
}

void Pendulum::CreateSmallGearWheel() {
	smallGearTexture.loadFromFile("images/_smallGearWheel.png");
	smallGearSprite.setTexture(smallGearTexture);
	smallGearSprite.setOrigin(smallGearSprite.getGlobalBounds().width / GET_HALF, smallGearSprite.getGlobalBounds().height / GET_HALF);
	smallGearSprite.rotate(CORRECTION_ANGLE);
	smallGearSpeed = 0;
	smallGearSprite.setPosition(DEFAULT_WINDOW_SIZE.x / GET_HALF + smallGearSprite.getGlobalBounds().width / GET_HALF, DEFAULT_WINDOW_SIZE.y / GET_HALF - smallGearSprite.getGlobalBounds().height / GET_HALF - CORRECTION_UNIT / GET_HALF);
}

void Pendulum::CreateBigGearWheel() {
	bigGearTexture.loadFromFile("images/_bigGearWheel.png");
	bigGearSprite.setTexture(bigGearTexture);
	bigGearSprite.setOrigin(BIG_GEAR_WIDTH_HEIGHT_ORIGIN.x, BIG_GEAR_WIDTH_HEIGHT_ORIGIN.y);
	bigGearSprite.setPosition(DEFAULT_WINDOW_SIZE.x / GET_HALF - bigGearSprite.getGlobalBounds().width / GET_HALF + CORRECTION_UNIT, DEFAULT_WINDOW_SIZE.y / GET_HALF - bigGearSprite.getGlobalBounds().height / GET_HALF - CORRECTION_UNIT - 10);
	bigGearSprite.setRotation(CORRECTION_ANGLE);
	bigGearSpeed = -0.1f;
} 

void Pendulum::RotatePendulum(float &time) {
	if (smallGearSpeed > 0) {
		pendulumSpeed = PENDULUM_SPEED;
	}
	else if (smallGearSpeed < 0) {
		pendulumSpeed = -PENDULUM_SPEED;
	}
	if ((pendulumSprite.getRotation() < PENDULUM_MIN_RESET_SPEED_LEFT.x) && (pendulumSprite.getRotation() > PENDULUM_MIN_RESET_SPEED_LEFT.y) && (pendulumSpeed > 0)) {
		pendulumSpeed = PENDULUM_MIN_RESET_SPEED;
	}
	else if ((pendulumSprite.getRotation() < PENDULUM_MIN_RESET_SPEED_RIGHT.x) && (pendulumSprite.getRotation() > PENDULUM_MIN_RESET_SPEED_RIGHT.y) && (pendulumSpeed < 0)) {
		pendulumSpeed = -PENDULUM_MIN_RESET_SPEED;
	}
	if ((pendulumSprite.getRotation() < PENDULUM_MAX_RESET_SPEED_LEFT.x) && (pendulumSprite.getRotation() > PENDULUM_MAX_RESET_SPEED_LEFT.y) && (pendulumSpeed > 0)) {
			pendulumSpeed = PENDULUM_MAX_RESET_SPEED;
	}
	else if ((pendulumSprite.getRotation() < PENDULUM_MAX_RESET_SPEED_RIGHT.x) && (pendulumSprite.getRotation() > PENDULUM_MAX_RESET_SPEED_RIGHT.y) && (pendulumSpeed < 0)) {
			pendulumSpeed = -PENDULUM_MAX_RESET_SPEED;
	}
	if ((pendulumSprite.getRotation() < PENDULUM_POINTS_ROTATION_STOP_LEFT.x) && (pendulumSprite.getRotation() > PENDULUM_POINTS_ROTATION_STOP_LEFT.y) && (pendulumSpeed > 0)) {
		pendulumSpeed = 0;
	}
	else if ((pendulumSprite.getRotation() < PENDULUM_POINTS_ROTATION_STOP_RIGHT.x) && (pendulumSprite.getRotation() > PENDULUM_POINTS_ROTATION_STOP_RIGHT.y) && (pendulumSpeed < 0)) {
		pendulumSpeed = 0;
	}
	pendulumSprite.rotate(pendulumSpeed * time);
}

void Pendulum::RotateSmallGear(float &time) {
	if (!smallGearToRotate) {
		if ((bigGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_TORIGHT.x) && (bigGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_TORIGHT.y) && (bigGearSpeed < 0)) {
			smallGearSpeed = SMALL_GEAR_SPEED;
			smallGearToRotate = true;
		}
		else if ((bigGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_TOLEFT.x) && (bigGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_TOLEFT.y) && (bigGearSpeed > 0)) {
			smallGearSpeed = -SMALL_GEAR_SPEED;
			smallGearToRotate = true;
		}
	}
	else {
		if (((smallGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_STOP_LEFT.x) && (smallGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_STOP_LEFT.y) && (bigGearSpeed < 0)) || ((smallGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT.x) && (smallGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT.y) && (bigGearSpeed > 0))){
			smallGearSpeed = 0;
		}
		smallGearSprite.rotate(smallGearSpeed * time);
	}
}

void Pendulum::RotateBigGear(float &time) {
	if ((bigGearSprite.getRotation() > BIG_GEAR_POINTS_ROTATION_STOP_LEFT.x) && (bigGearSprite.getRotation() < BIG_GEAR_POINTS_ROTATION_STOP_LEFT.y)) {
		bigGearSpeed = BIG_GEAR_SPEED;
		smallGearToRotate = false;
	}
	else if ((bigGearSprite.getRotation() > BIG_GEAR_POINTS_ROTATION_STOP_RIGHT.x) && (bigGearSprite.getRotation() < BIG_GEAR_POINTS_ROTATION_STOP_LEFT.y)) {
		bigGearSpeed = -BIG_GEAR_SPEED;
		smallGearToRotate = false;
	}
	bigGearSprite.rotate(bigGearSpeed * time);
}