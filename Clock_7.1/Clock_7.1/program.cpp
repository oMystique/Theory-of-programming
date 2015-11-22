#include "program.h"

void RotationHands(ClockElements &clock) {
	clock.secondHand.setRotation(DEGREES_IN_CIRCLE / COUNT_TIME_UNITS * float(clock.time.systemTime.wSecond) - 90);
	clock.minuteHand.setRotation((DEGREES_IN_CIRCLE / COUNT_TIME_UNITS * float(clock.time.systemTime.wSecond) / COUNT_TIME_UNITS) + float(clock.time.systemTime.wMinute) * DEGREES_IN_CIRCLE / COUNT_TIME_UNITS - DEGREES_IN_CIRCLE / 4);
	clock.hourHand.setRotation(DEGREES_IN_CIRCLE / COUNT_TIME_UNITS * COUNT_TIME_UNITS / CORRECTION_UNIT * float(clock.time.systemTime.wMinute) / COUNT_TIME_UNITS + float(clock.time.systemTime.wHour) * DEGREES_IN_CIRCLE / ELEMENTS_ON_CLOCK_FACE - DEGREES_IN_CIRCLE / 4);
}

void UpdateTime(ClockElements &clock) {
	GetLocalTime(&clock.time.systemTime);
	RotationHands(clock);
}

void CalculateElementPos(float angle, ClockElements &clock) {
	double x = clock.hourHand.getPosition().x - CORRECTION_UNIT / 2 + (RADIUS_CLOCK_FACE - CORRECTION_UNIT)*cos(angle * PI / (DEGREES_IN_CIRCLE / 2));
	double y = clock.hourHand.getPosition().y - CORRECTION_UNIT + (RADIUS_CLOCK_FACE - CORRECTION_UNIT)*sin(angle * PI / (DEGREES_IN_CIRCLE / 2));
	clock.hour.setPosition(float(x), float(y));
}

void DrawObjects(Program &program, ClockElements &clock) {
	program.window.clear(Color::White);
	program.window.draw(clock.clockFace);
	UpdateTime(clock);
	int hour = 1;
	for (float angle = 0; angle < DEGREES_IN_CIRCLE; angle += 30) {
		hour++;
		if (hour == ELEMENTS_ON_CLOCK_FACE) {
			hour = 0;
		}
		clock.hour.setString(to_string(hour + 1));
		CalculateElementPos(angle, clock);
		program.window.draw(clock.hour);
	}
	program.window.draw(clock.hourHand);
	program.window.draw(clock.minuteHand);
	program.window.draw(clock.secondHand);
	program.window.draw(clock.clockCore);
	program.window.display();
}

void CreateObjects(Program &program, ClockElements &clock) {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	program.window.create(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Now you can check the current time. c:", sf::Style::Default, settings);
	clock.clockFace.setRadius(RADIUS_CLOCK_FACE);
	clock.clockFace.setFillColor(Color::White);
	clock.clockFace.setOutlineThickness(3);
	clock.clockFace.setOutlineColor(Color::Black);
	clock.hourHand.setSize(Vector2f(WIDTH_HOUR_HAND, HEIGHT_HOUR_HAND));
	clock.hourHand.setFillColor(Color::Black);
	clock.hourHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE - HEIGHT_HOUR_HAND / 2);
	clock.minuteHand.setSize(Vector2f(WIDTH_MINUTE_HAND, HEIGHT_MINUTE_HAND));
	clock.minuteHand.setFillColor(Color::Black);
	clock.minuteHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.secondHand.setSize(Vector2f(WIDTH_SECOND_HAND, HEIGHT_SECOND_HAND));
	clock.secondHand.setFillColor(Color::Red);
	clock.secondHand.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.clockCore.setRadius(RADIUS_HOUR_CORE);
	clock.clockCore.setFillColor(Color::Black);
	clock.clockCore.setOrigin(clock.clockCore.getGlobalBounds().width / 2, clock.clockCore.getGlobalBounds().height / 2);
	clock.clockCore.setPosition(clock.clockFace.getPosition().x + RADIUS_CLOCK_FACE, clock.clockFace.getPosition().y + RADIUS_CLOCK_FACE);
	clock.font.loadFromFile("CyrilicOld.ttf");
	clock.hour.setFont(clock.font);
	clock.hour.setColor(Color::Black);
	clock.hour.setCharacterSize(FONT_SIZE);
	clock.hour.setOrigin(clock.hour.getGlobalBounds().width / 2, clock.hour.getGlobalBounds().height / 2);
}

void PollEvent(Program &program, Event &event) {
	while (program.window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			program.window.close();
		}
				
	}
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