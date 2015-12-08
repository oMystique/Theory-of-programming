#include "application.h"

Application::Application() :
	window(sf::VideoMode(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y), "Laba_8.1", Style::Close, settings),
	world(),
	car() {
	Run();
};

void Application::ProcessEvents() {
	float time = float(clock.getElapsedTime().asMicroseconds());
	clock.restart();
	time = time / APP_SPEED;
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
	}
}

void Application::DrawObjects() {
	window.clear(Color::White);
	window.draw(car.bodySprite);
	window.draw(world.road);
	window.draw(car.bodySprite);
	window.draw(car.leftWheelSprite);
	window.draw(car.rightWheelSprite);
	window.display();
}

void Application::Run() {
	settings.antialiasingLevel = 8;
	while (window.isOpen()) {
		ProcessEvents();
		DrawObjects();
	}
}