#include "application.h"

Application::Application() :
	window(sf::VideoMode(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y), "Laba_7.3", Style::Close, settings)
{
	CreateObjects();
};

void Application::CreateObjects() {
	pendulum.CreateSmallGearWheel();
	pendulum.CreateBigGearWheel();
	pendulum.CreatePendulum();
}

void Application::ProcessEvents() {
	float time = float(clock.getElapsedTime().asMicroseconds());
	clock.restart();
	time = time / APP_SPEED;
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
	}
	pendulum.RotateBigGear(time);
	pendulum.RotateSmallGear(time);
	pendulum.RotatePendulum(time);
}

void Application::DrawObjects() {
	window.clear(Color::White);
	window.draw(pendulum.pendulumSprite);
	window.draw(pendulum.smallGearSprite);
	window.draw(pendulum.bigGearSprite);
	window.display();
}

void Application::Run() {
	settings.antialiasingLevel = 8;
	while (window.isOpen()) {
		ProcessEvents();
		DrawObjects();
	}
}