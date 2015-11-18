#pragma once

#include "functions.h"

const float SIZE_STORAGE_UNIT = 1024.0;
const float GET_HALF = 2;
const double MAX_FILE_SIZE = 100.0;
const double MAX_TEXTURE_SIZE = 16000.0;
const float WIDTH_ARROW_SPRITE = 75;
const int DEFAULT_WINDOW_WIDTH = 800;
const int DEFAULT_WINDOW_HEIGHT = 600;
const float SIZE_MINUS_PLUS_SPRITE = 48;
const double SIZE_ZOOM = 0.03;
const double MAX_ZOOM = 8;
const double MIN_ZOOM = 0.1;


using namespace sf;
using namespace std;


struct Files {
	string *files;
	unsigned int nameSize, arrSize;
	string path;
};


struct Picture {
	string title;
	double left, top, scale;
	bool zoom, move, error;
	Texture *texture;
	Sprite *sprite;
	unsigned int num;
};