#pragma once
#include "resources.h"
#include "pendulum.h"

struct Application {
	Application();

	void Run();
	void ProcessEvents();
	void CreateObjects();
	void DrawObjects();

	Clock clock;
	ContextSettings settings;
	RenderWindow window;
	Pendulum pendulum;
};