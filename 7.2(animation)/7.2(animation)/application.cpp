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
	for (animation.rectangles.currentRectangle = animation.rectangles.rectanglesList.begin(); animation.rectangles.currentRectangle != animation.rectangles.rectanglesList.end(); animation.rectangles.currentRectangle++) {
		window.draw(**animation.rectangles.currentRectangle);
	}
	window.display();
}

void Application::ProcessEvents() {
	Event event;
	while (window.pollEvent(event))
	{
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
	for (animation.rectangles.currentRectangle = animation.rectangles.rectanglesList.begin(); animation.rectangles.currentRectangle != animation.rectangles.rectanglesList.end(); animation.rectangles.currentRectangle++) {
		(*animation.rectangles.currentRectangle)->setPosition(DEFAULT_RECTANGLE_SIZE.x, DEFAULT_RECTANGLE_SIZE.x * i);
		i++;
		(*animation.rectangles.currentRectangle)->setFillColor(Color::Red);
		(*animation.rectangles.currentRectangle)->setOrigin((*animation.rectangles.currentRectangle)->getSize().x / GET_HALF, (*animation.rectangles.currentRectangle)->getSize().y / GET_HALF);
	}
}

void Application::Run() {
	while (window.isOpen()) {
		ProcessEvents();
		DrawObjects();
	}
	for (animation.rectangles.currentRectangle = animation.rectangles.rectanglesList.begin(); animation.rectangles.currentRectangle != animation.rectangles.rectanglesList.end(); animation.rectangles.currentRectangle++) {
		delete (*animation.rectangles.currentRectangle);
	}
}