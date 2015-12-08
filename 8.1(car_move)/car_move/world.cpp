#include "world.h"

World::World() {
	InitRoad();
}

void World::InitRoad() {
	road.setSize(Vector2f(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y / 3));
	road.setFillColor(Color(131, 139, 139));
	road.setPosition(0, DEFAULT_WINDOW_SIZE.y - road.getGlobalBounds().height);
}