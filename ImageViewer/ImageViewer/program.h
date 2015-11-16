#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include "functions.h"

struct Program {
	Vector2u windowSize;
	string path;
	Files files;
	Picture picture;
} typedef Program;

struct Buttons {
	Texture textureArrow;
	Sprite arrowLeft;
	Sprite arrowRight;

	Texture texturePlus;
	Sprite plusSprite;

	Texture textureMinus;
	Sprite minusSprite;
}; 

void StartProgram(Program &program, Buttons &buttons);