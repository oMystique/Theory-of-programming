#include "application.h"


void GetAnimationStep(Animation &animation) {
	if (animation.step == 1) {
		animation.FirstStep();
	}
	else if (animation.step == 2) {
		animation.SecondStep();
	}
	else if (animation.step == 3) {
		animation.ThirdStep();
	}
	else if (animation.step == 4) {
		animation.FourthStep();
	}
	else if (animation.step == 5) {
		animation.FifthStep();
	}
}

Application::Application() :
	window(sf::VideoMode(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y), "Laba_7.2", Style::Close),
	animation()
	{
	animation.step = 1;
	CreateObjects();
	};

void Application::DrawObjects() {
	window.clear(Color::White);
	for (RectangleShape *currentRect : animation.rectangles.rectanglesList) {
		window.draw(*currentRect);
	}
	window.display();
}

void Application::ProcessEvents() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
	}
	GetAnimationStep(animation);
}

void Application::CreateObjects() {
	for (int i = 0; i < FIGURES_COUNT; i++) {
		animation.rectangles.rectanglesList.push_back(new RectangleShape(DEFAULT_RECTANGLE_SIZE));
	}
	int i = 1;
	for (RectangleShape *currentRect : animation.rectangles.rectanglesList) {
		currentRect->setPosition(DEFAULT_RECTANGLE_SIZE.x, DEFAULT_RECTANGLE_SIZE.x * i);
		i++;
		currentRect->setFillColor(Color::Red);
		currentRect->setOrigin((currentRect)->getSize().x / GET_HALF, (currentRect)->getSize().y / GET_HALF);
	}
}

void Application::Run() {
	while (window.isOpen()) {
		ProcessEvents();
		DrawObjects();
	}
	for (RectangleShape *currentRect : animation.rectangles.rectanglesList) {
		delete currentRect;
	}
}