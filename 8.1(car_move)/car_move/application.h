#pragma once
#include "resources.h"
#include "car.h"
#include "world.h"

struct Application {
	Application();

	void Run();
	void ProcessEvents();
	void CreateObjects();
	void DrawObjects();

	Clock clock;
	ContextSettings settings;
	RenderWindow window;
	Car car;
	World world;
};