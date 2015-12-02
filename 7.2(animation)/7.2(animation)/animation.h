#pragma once
#include "application.h"

struct Animation {
	Rectangles rectangles;
	unsigned int step;

	void FirstStep();
	void SecondStep();
	void ThirdStep();
	void FourthStep();
	void FifthStep();
};