#include "application.h"

Application::Application() :
	window(sf::VideoMode(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y), "Laba_7.3", Style::Close, settings)
{
	CreateObjects();
};

void Application::CreateObjects() {
	pendulum.CreateTopSmallGearWheel();
	pendulum.CreateBigGearWheel();
	pendulum.CreatePendulum();
	pendulum.CreateBotSmallGears();
	pendulum.CreateThreads();
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
	pendulum.RotateTopSmallGear(time);
	pendulum.RotatePendulum(time);
	pendulum.RotateBotSmallGears(time);
}

void Application::DrawObjects() {
	window.clear(Color::White);
	window.draw(pendulum.threadLeft);
	window.draw(pendulum.threadRight);
	window.draw(pendulum.coilLeft);
	window.draw(pendulum.coilRight);
	window.draw(pendulum.pendulumSprite);
	window.draw(pendulum.topSmallGearSprite);
	window.draw(pendulum.leftBotSmallGearSprite);
	window.draw(pendulum.rightBotSmallGearSprite);
	window.draw(pendulum.left2BotSmallGearSprite);
	window.draw(pendulum.right2BotSmallGearSprite);
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