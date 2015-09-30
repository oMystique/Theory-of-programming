//_author_:|IldarkinAlexey;PS-22|.

#include "program.h"

int main() {
	Program *mainProgram = new Program();
	Buttons *initButtons = new Buttons();
	startProgram(*mainProgram, *initButtons);
	return 0;
}