#include "world.h"

World::World() {
	InitRoad();
}

void World::InitRoad() {
	road.setSize(Vector2f(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y / GET_THIRD));
	road.setFillColor(ROAD_COLOR);
	road.setPosition(0, DEFAULT_WINDOW_SIZE.y - road.getGlobalBounds().height);
}