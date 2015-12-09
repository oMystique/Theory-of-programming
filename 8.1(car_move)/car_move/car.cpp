#include "car.h"

Car::Car() {
	CreateCarElements();
}

void Car::CreateCarElements() {
	carTexture.loadFromFile("images/car.png");
	bodySprite.setTexture(carTexture);
	bodySprite.setTextureRect(IntRect(CAR_TEXTURE_RECT));
	bodySprite.setScale(SCALE_OBJECTS, SCALE_OBJECTS);
	leftWheelSprite.setTexture(carTexture);
	leftWheelSprite.setTextureRect(IntRect(WHEEL_TEXTURE_RECT));
	leftWheelSprite.setOrigin(leftWheelSprite.getGlobalBounds().width / GET_HALF, leftWheelSprite.getGlobalBounds().height / GET_HALF);
	leftWheelSprite.setScale(SCALE_OBJECTS, SCALE_OBJECTS);
	rightWheelSprite.setTexture(carTexture);
	rightWheelSprite.setTextureRect(IntRect(WHEEL_TEXTURE_RECT));
	rightWheelSprite.setOrigin(rightWheelSprite.getGlobalBounds().width / GET_HALF, rightWheelSprite.getGlobalBounds().height / GET_HALF);
	rightWheelSprite.setScale(SCALE_OBJECTS, SCALE_OBJECTS);
	SetPositionCarElements();
}

void Car::SetPositionCarElements() {
	bodySprite.setPosition(0, DEFAULT_WINDOW_SIZE.y - DEFAULT_WINDOW_SIZE.y / GET_THIRD - bodySprite.getGlobalBounds().height - rightWheelSprite.getGlobalBounds().height / BODY_CORRECTION_FOR_WHEEL);
	leftWheelSprite.setPosition(bodySprite.getPosition().x + LEFT_WHEEL_CORRECTION_FOR_BODY.x, bodySprite.getPosition().y + LEFT_WHEEL_CORRECTION_FOR_BODY.y);
	rightWheelSprite.setPosition(bodySprite.getPosition().x + RIGHT_WHEEL_CORRECTION_FOR_BODY, bodySprite.getPosition().y + LEFT_WHEEL_CORRECTION_FOR_BODY.y);
	speed = 0;
}

void Car::MoveCar(float &time) {
	if (bodySprite.getPosition().x < BORDER_UNIT) {
		if (speed < CAR_MAXIMUM_SPEED) {
			speed += CAR_MINIMUM_SPEED;
		}
	}
	else if (bodySprite.getPosition().x + bodySprite.getGlobalBounds().width > DEFAULT_WINDOW_SIZE.x - BORDER_UNIT) {
		if (speed > -CAR_MAXIMUM_SPEED) {
			speed -= CAR_MINIMUM_SPEED;
		}
	}
	bodySprite.move(speed*time, 0);
	leftWheelSprite.rotate(speed*time);
	rightWheelSprite.rotate(speed*time);
	leftWheelSprite.setPosition(bodySprite.getPosition().x + LEFT_WHEEL_CORRECTION_FOR_BODY.x, leftWheelSprite.getPosition().y);
	rightWheelSprite.setPosition(bodySprite.getPosition().x + RIGHT_WHEEL_CORRECTION_FOR_BODY, rightWheelSprite.getPosition().y);
}