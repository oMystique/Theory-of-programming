#pragma once
#include "resources.h"
#include "rectangles.h"
#include "animation.h"

struct Application {
	Application();

	void Run();
	void ProcessEvents();
	void CreateObjects();
	void DrawObjects();

	RenderWindow window;
	Animation animation;
};