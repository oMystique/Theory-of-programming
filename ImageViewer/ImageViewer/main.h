#include "functions.h"

const float SIZE_STORAGE_UNIT = 1024.0;
const float DEVIDE_INTO_TWO = 2;
const double MAX_FILE_SIZE = 100.0;
const double MAX_TEXTURE_SIZE = 16000.0;
const float WIDTH_ARROW_SPRITE = 75;
const int DEFAULT_WINDOW_WIDTH = 800;
const int DEFAULT_WINDOW_HEIGHT = 600;

using namespace sf;
using namespace std;


struct Files {
	string *files;
	unsigned int nameSize;
	unsigned int arrSize;
	string path;
};


struct Picture {
	string title;
	double left;
	double top;
	Texture *texture = new Texture();
	Texture *pTexture = new Texture();
	Texture *nTexture = new Texture();
	bool error;
	Sprite *sprite = new Sprite();
	unsigned int num;
};