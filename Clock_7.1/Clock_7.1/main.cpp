#include "program.h"

int main()
{
	Program *initProgram = new Program();
	ClockElements *newClock = new ClockElements();
	ActionProgram(*initProgram, *newClock);
	delete initProgram;
	delete newClock;
	return 0;
}