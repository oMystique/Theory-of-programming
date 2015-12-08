#include "application.h"

void Pendulum::CreatePendulum() {
	pendulumTexture.loadFromFile("images/_pendulum.png");
	pendulumSprite.setTexture(pendulumTexture);
	pendulumSprite.setOrigin(pendulumSprite.getGlobalBounds().width / GET_HALF, pendulumSprite.getGlobalBounds().width / GET_HALF + GET_HALF);
	pendulumSprite.setPosition(topSmallGearSprite.getPosition().x, topSmallGearSprite.getPosition().y);
	pendulumSprite.rotate(CORRECTION_ANGLE);
	pendulumSpeed = 0;
}

void Pendulum::CreateThreads() {
	threadLeft.setSize(Vector2f(pendulumSprite.getGlobalBounds().height, THREAD_HEIGHT));
	threadLeft.setPosition(bigGearSprite.getPosition().x + CORRECTION_UNIT * 1.3f, bigGearSprite.getPosition().y);
	threadLeft.rotate(98);
	threadLeft.setFillColor(Color::Red);

	threadRight.setSize(Vector2f(pendulumSprite.getGlobalBounds().height * 1.6f, THREAD_HEIGHT));
	threadRight.setPosition(bigGearSprite.getPosition().x + CORRECTION_UNIT * 1.3f, bigGearSprite.getPosition().y);
	threadRight.rotate(37);
	threadRight.setFillColor(Color::Red);
}

void Pendulum::CreateBotSmallGears() {
	leftBotSmallGearSprite.setTexture(smallGearTexture);
	leftBotSmallGearSprite.setOrigin(leftBotSmallGearSprite.getGlobalBounds().width / GET_HALF, leftBotSmallGearSprite.getGlobalBounds().height / GET_HALF);
	leftBotSmallGearSprite.setPosition(topSmallGearSprite.getPosition().x - topSmallGearSprite.getGlobalBounds().width - CORRECTION_UNIT, topSmallGearSprite.getPosition().y + pendulumSprite.getGlobalBounds().height - CORRECTION_UNIT * 0.4f);
	rightBotSmallGearSprite.setTexture(smallGearTexture);
	rightBotSmallGearSprite.setOrigin(rightBotSmallGearSprite.getGlobalBounds().width / GET_HALF, rightBotSmallGearSprite.getGlobalBounds().height / GET_HALF);
	rightBotSmallGearSprite.setPosition(topSmallGearSprite.getPosition().x + topSmallGearSprite.getGlobalBounds().width + CORRECTION_UNIT * 1.55f, topSmallGearSprite.getPosition().y + pendulumSprite.getGlobalBounds().height - CORRECTION_UNIT * 0.8f);
	left2BotSmallGearSprite.setTexture(smallGearTexture);
	left2BotSmallGearSprite.setOrigin(leftBotSmallGearSprite.getGlobalBounds().width / GET_HALF, leftBotSmallGearSprite.getGlobalBounds().height / GET_HALF);
	left2BotSmallGearSprite.setPosition(topSmallGearSprite.getPosition().x - topSmallGearSprite.getGlobalBounds().width - CORRECTION_UNIT, topSmallGearSprite.getPosition().y + pendulumSprite.getGlobalBounds().height - CORRECTION_UNIT * 0.4f);
	left2BotSmallGearSprite.rotate(CORRECTION_ANGLE);
	right2BotSmallGearSprite.setTexture(smallGearTexture);
	right2BotSmallGearSprite.setOrigin(rightBotSmallGearSprite.getGlobalBounds().width / GET_HALF, rightBotSmallGearSprite.getGlobalBounds().height / GET_HALF);
	right2BotSmallGearSprite.setPosition(topSmallGearSprite.getPosition().x + topSmallGearSprite.getGlobalBounds().width + CORRECTION_UNIT * 1.55f, topSmallGearSprite.getPosition().y + pendulumSprite.getGlobalBounds().height - CORRECTION_UNIT * 0.8f);
	right2BotSmallGearSprite.rotate(CORRECTION_ANGLE);

	coilLeft.setRadius(COIL_RADIUS);
	coilLeft.setFillColor(Color::Red);
	coilLeft.setOrigin(coilLeft.getGlobalBounds().width / GET_HALF, coilLeft.getGlobalBounds().height / GET_HALF);
	coilLeft.setPosition(leftBotSmallGearSprite.getPosition().x, leftBotSmallGearSprite.getPosition().y);

	coilRight.setRadius(COIL_RADIUS);
	coilRight.setFillColor(Color::Red);
	coilRight.setOrigin(coilLeft.getGlobalBounds().width / GET_HALF, coilLeft.getGlobalBounds().height / GET_HALF);
	coilRight.setPosition(rightBotSmallGearSprite.getPosition().x, rightBotSmallGearSprite.getPosition().y);
}

void Pendulum::CreateTopSmallGearWheel() {
	smallGearTexture.loadFromFile("images/_smallGearWheel.png");
	topSmallGearSprite.setTexture(smallGearTexture);
	topSmallGearSprite.setOrigin(topSmallGearSprite.getGlobalBounds().width / GET_HALF, topSmallGearSprite.getGlobalBounds().height / GET_HALF);
	topSmallGearSprite.rotate(CORRECTION_ANGLE);
	topSmallGearSpeed = 0;
	topSmallGearSprite.setPosition(DEFAULT_WINDOW_SIZE.x / GET_HALF + topSmallGearSprite.getGlobalBounds().width / GET_HALF, DEFAULT_WINDOW_SIZE.y / GET_HALF - topSmallGearSprite.getGlobalBounds().height / GET_HALF - CORRECTION_UNIT / GET_HALF);
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
	if (topSmallGearSpeed > 0) {
		pendulumSpeed = PENDULUM_SPEED;
	}
	else if (topSmallGearSpeed < 0) {
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
			botSmallGearSpeed = 0;
	}
	else if ((pendulumSprite.getRotation() < PENDULUM_MAX_RESET_SPEED_RIGHT.x) && (pendulumSprite.getRotation() > PENDULUM_MAX_RESET_SPEED_RIGHT.y) && (pendulumSpeed < 0)) {
			pendulumSpeed = -PENDULUM_MAX_RESET_SPEED;
			botSmallGearSpeed = 0;
	}
	if ((pendulumSprite.getRotation() < PENDULUM_POINTS_ROTATION_STOP_LEFT.x) && (pendulumSprite.getRotation() > PENDULUM_POINTS_ROTATION_STOP_LEFT.y) && (pendulumSpeed > 0)) {
		pendulumSpeed = 0;
	}
	else if ((pendulumSprite.getRotation() < PENDULUM_POINTS_ROTATION_STOP_RIGHT.x) && (pendulumSprite.getRotation() > PENDULUM_POINTS_ROTATION_STOP_RIGHT.y) && (pendulumSpeed < 0)) {
		pendulumSpeed = 0;
	}
	pendulumSprite.rotate(pendulumSpeed * time);
}

void Pendulum::RotateTopSmallGear(float &time) {
	if (!smallGearToRotate) {
		if ((bigGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_TORIGHT.x) && (bigGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_TORIGHT.y) && (bigGearSpeed < 0)) {
			topSmallGearSpeed = SMALL_GEAR_SPEED;
			smallGearToRotate = true;
		}
		else if ((bigGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_TOLEFT.x) && (bigGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_TOLEFT.y) && (bigGearSpeed > 0)) {
			topSmallGearSpeed = -SMALL_GEAR_SPEED;
			smallGearToRotate = true;
		}
	}
	else {
		if (((topSmallGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_STOP_LEFT.x) && (topSmallGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_STOP_LEFT.y) && (bigGearSpeed < 0)) || ((topSmallGearSprite.getRotation() < SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT.x) && (topSmallGearSprite.getRotation() > SMALL_GEAR_POINTS_ROTATION_STOP_RIGHT.y) && (bigGearSpeed > 0))){
			topSmallGearSpeed = 0;
		}
		topSmallGearSprite.rotate(topSmallGearSpeed * time);
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

void Pendulum::RotateBotSmallGears(float &time) {
	botSmallGearSpeed = -bigGearSpeed / 5;
	leftBotSmallGearSprite.rotate(botSmallGearSpeed);
	rightBotSmallGearSprite.rotate(botSmallGearSpeed);
	left2BotSmallGearSprite.rotate(botSmallGearSpeed);
	right2BotSmallGearSprite.rotate(botSmallGearSpeed);
}