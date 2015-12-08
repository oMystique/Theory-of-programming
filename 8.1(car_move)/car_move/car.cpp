#include "car.h"

Car::Car() {
	CreateCarElements();
}

void Car::CreateCarElements() {
	carTexture.loadFromFile("images/car.png");
	bodySprite.setTexture(carTexture);
	bodySprite.setTextureRect(IntRect(43, 5, 829, 233));
	bodySprite.setScale(0.5, 0.5);
	leftWheelSprite.setTexture(carTexture);
	leftWheelSprite.setTextureRect(IntRect(142, 304, 132, 132));
	leftWheelSprite.setScale(0.5, 0.5);
	rightWheelSprite.setTexture(carTexture);
	rightWheelSprite.setTextureRect(IntRect(142, 304, 132, 132));
	rightWheelSprite.setScale(0.5, 0.5);
	SetPositionCarElements();
	leftWheelSprite.setOrigin(leftWheelSprite.getGlobalBounds().width / 2, leftWheelSprite.getGlobalBounds().height / 2);
	rightWheelSprite.setOrigin(rightWheelSprite.getGlobalBounds().width / 2, rightWheelSprite.getGlobalBounds().height / 2);
}

void Car::SetPositionCarElements() {
	bodySprite.setPosition(0, DEFAULT_WINDOW_SIZE.y - DEFAULT_WINDOW_SIZE.y / 3 - bodySprite.getGlobalBounds().height - 14);
	leftWheelSprite.setPosition(bodySprite.getPosition().x + 73.5f, bodySprite.getPosition().y + 81.f);
	rightWheelSprite.setPosition(bodySprite.getPosition().x + 323.5f, bodySprite.getPosition().y + 82.f);
}

void Car::MoveCar(float &time) {

}