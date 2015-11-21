#include "program.h"

void PollEvent(Program &program, Event &event) {
	while (program.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			program.window.close();
	}
}

void CalculateDivisionPos(float rotation, ClockElements &clock) {
	double x = clock.hourHand.getPosition().x + (RADIUS_CLOCK_FACE - 3.5)*cos(rotation * 3.14159265 / 180);
	double y = clock.hourHand.getPosition().y + (RADIUS_CLOCK_FACE - 3.5)*sin(rotation * 3.14159265 / 180);
	clock.hourDivision.setPosition(float(x), float(y));
}

void DrawObjects(Program &program, ClockElements &clock) {
	program.window.clear(Color::White);
	program.window.draw(clock.clockFace);
	program.window.draw(clock.hourHand);
	program.window.draw(clock.minuteHand);
	program.window.draw(clock.secondHand);

	//std::cout << sin(30 * 3.14 / 180);
	for (float angle = 0; angle < 360; angle += 30) {
		CalculateDivisionPos(angle, clock);
		program.window.draw(clock.hourDivision);
	}

	program.window.display();
}

void CreateObjects(Program &program, ClockElements &clock){
	program.window.create(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Sorry, but while you can't check the current time. :c");
	clock.clockFace.setRadius(RADIUS_CLOCK_FACE);
	clock.clockFace.setFillColor(Color::White);
	clock.clockFace.setOutlineThickness(2);
	clock.clockFace.setOutlineColor(Color::Black);
	clock.hourHand.setSize(Vector2f(WIDTH_HOUR_HAND, HEIGHT_HOUR_HAND));
	clock.hourHand.setFillColor(Color::Black);
	clock.hourHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.minuteHand.setSize(Vector2f(WIDTH_MINUTE_HAND, HEIGHT_MINUTE_HAND));
	clock.minuteHand.setFillColor(Color::Black);
	clock.minuteHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.minuteHand.setRotation(30); //TODO
	clock.secondHand.setSize(Vector2f(WIDTH_SECOND_HAND, HEIGHT_SECOND_HAND));
	clock.secondHand.setFillColor(Color::Red);
	clock.secondHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.secondHand.setRotation(60); //TODO
	clock.hourDivision.setRadius(RADIUS_HOUR_DIVISION);
	clock.hourDivision.setFillColor(Color::Black);
	clock.hourDivision.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y);
}


void IsOpen(Program &program, ClockElements &clock) {
	while (program.window.isOpen())
	{
		Event event;
		PollEvent(program, event);
		DrawObjects(program, clock);
	}
}

void ActionProgram(Program &program, ClockElements &clock) {
	CreateObjects(program, clock);
	IsOpen(program, clock);
}