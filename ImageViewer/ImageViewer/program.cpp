#include "program.h"

void InitProgram(Program &program) {
	program.path = "Path to images dir";
	cout << "Please, enter the absolution path to your images. Likely 'D:\\Laba5\\Screenshots\\' \n";
	cin >> program.path;
	program.files = GetFileList(program.path);
	cout << "Numbers of image on directory: " << program.files.arrSize << "\n";
	if (program.files.arrSize > 0) {
		InitializePicture(program.windowSize, program.files, program.picture, 0);
	}
}


void SetButtons(Buttons &buttons, Program &program) {
	buttons.textureArrow.loadFromFile("images/arrow.png");
	buttons.arrowRight.setTexture(buttons.textureArrow);
	buttons.arrowLeft.setTexture(buttons.textureArrow);
	buttons.arrowLeft.setScale(-1, 1);
	buttons.texturePlus.loadFromFile("images/plus.png");
	buttons.plusSprite.setTexture(buttons.texturePlus);
	buttons.textureMinus.loadFromFile("images/minus.png");
	buttons.minusSprite.setTexture(buttons.textureMinus);
}


void ResizedEvent(RenderWindow &window ,Event &event, Program &program) {
	program.windowSize.x = event.size.width;
	program.windowSize.y = event.size.height;
	ResizePicture(program.windowSize, program.picture);
	window.setView(View(FloatRect(0, 0, float(program.windowSize.x), float(program.windowSize.y))));
}


void MoveRightEvent(Program &program) {
	if (program.picture.num + 1 == program.files.arrSize) {
		program.picture.num = 0;
	}
	else {
		program.picture.num++;
	}
	InitializePicture(program.windowSize, program.files, program.picture, 2);
}


void MoveLeftEvent(Program &program) {
	if (program.picture.num == 0) {
		program.picture.num = program.files.arrSize;
	}
	program.picture.num--;
	InitializePicture(program.windowSize, program.files, program.picture, 1);
}


void GetEvent(Program &program, Buttons &buttons, RenderWindow &window, Event &event, Vector2f &pos) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			delete[] program.files.files;
			window.close();
		}
		if ((event.type == Event::MouseButtonPressed) && (event.key.code == Mouse::Left) && (program.picture.sprite->getGlobalBounds().contains(pos.x, pos.y)) && (!buttons.plusSprite.getGlobalBounds().contains(pos.x, pos.y)) && (!buttons.minusSprite.getGlobalBounds().contains(pos.x, pos.y))) {
			program.picture.move = true;
		}
		else if ((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left)) {
			program.picture.move = false;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left)) && (buttons.arrowRight.getGlobalBounds().contains(pos.x, pos.y)))) {
			MoveRightEvent(program);
		}
		else if ((Keyboard::isKeyPressed(Keyboard::Left)) || (((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left)) && (buttons.arrowLeft.getGlobalBounds().contains(pos.x, pos.y)))) {
			MoveLeftEvent(program);
		}
		if (((event.key.code == Mouse::Left) && (buttons.minusSprite.getGlobalBounds().contains(pos.x, pos.y))) || (((Keyboard::isKeyPressed(Keyboard::LControl)) || (Keyboard::isKeyPressed(Keyboard::RControl))) && (Keyboard::isKeyPressed(Keyboard::Subtract)))) {
			ZoomPicture(program.picture, - SIZE_ZOOM);
		}
		else if (((event.key.code == Mouse::Left) && (buttons.plusSprite.getGlobalBounds().contains(pos.x, pos.y))) || (((Keyboard::isKeyPressed(Keyboard::LControl)) || (Keyboard::isKeyPressed(Keyboard::RControl))) && (Keyboard::isKeyPressed(Keyboard::Add)))) {
			ZoomPicture(program.picture, SIZE_ZOOM);
		}
		if (event.type == Event::Resized) {
			ResizedEvent(window, event, program);
		}
	}
}


void DrawObjects(RenderWindow &window, Program &program, Buttons &buttons) {
	window.draw(*program.picture.sprite);
	buttons.arrowRight.setPosition(float(window.getSize().x - WIDTH_ARROW_SPRITE), float(window.getSize().y / GET_HALF));
	buttons.arrowLeft.setPosition(WIDTH_ARROW_SPRITE, float(window.getSize().y / GET_HALF));
	buttons.plusSprite.setPosition(float(window.getSize().x) / GET_HALF + SIZE_MINUS_PLUS_SPRITE, float(window.getSize().y) - SIZE_MINUS_PLUS_SPRITE);
	buttons.minusSprite.setPosition(float(window.getSize().x) / GET_HALF - SIZE_MINUS_PLUS_SPRITE, float(window.getSize().y) - SIZE_MINUS_PLUS_SPRITE);
	window.draw(buttons.arrowLeft);
	window.draw(buttons.arrowRight);
	window.draw(buttons.plusSprite);
	window.draw(buttons.minusSprite);
	window.display();
	program.windowSize = window.getSize();
}


void ActionProgram(Program &program, Buttons &buttons) {
	RenderWindow window(VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Image Viewer");
	InitProgram(program);
	SetButtons(buttons, program);
	while (window.isOpen()) {
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		Event event;
		GetEvent(program, buttons, window, event, pos);
		window.setTitle(program.picture.title);
		program.picture.sprite->setTexture((*program.picture.texture));
		ResizePicture(program.windowSize, program.picture);
		window.clear();
		if ((program.picture.move) && (program.picture.zoom)) {//если можем двигать
			program.picture.sprite->move(pos.x - program.picture.sprite->getPosition().x, pos.y - program.picture.sprite->getPosition().y);
		}
		DrawObjects(window, program, buttons);
	}
}


void StartProgram(Program &program, Buttons &buttons) {
	ActionProgram(program, buttons);
}