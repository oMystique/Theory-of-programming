#include "program.h"

void initProgram(Program &program) {
	program.path = "Path to images dir";
	cout << "Please, enter the absolution path to your images. Likely 'D:\\Laba5\\Screenshots\\' \n";
	cin >> program.path;
	////////////////////////////////////
	program.files = getFileList(program.path);
	cout << "Numbers of image on directory: " << program.files.arrSize << "\n";
	if (program.files.arrSize > 0) {
		initializePicture(program.windowSize, program.files, &program.picture, 0);
	}
}

void arrowButtons(Buttons &buttons, Program &program) {
	buttons.texture.loadFromFile("images/arrow.png");
	buttons.arrowRight.setTexture(buttons.texture);
	buttons.arrowLeft.setTexture(buttons.texture);
	buttons.arrowLeft.setScale(-1, 1);
}

void actionProgram(Program &program, Buttons &buttons) {
	RenderWindow window(VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "Image Viewer");
	initProgram(program);
	arrowButtons(buttons, program);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f pos = window.mapPixelToCoords(pixelPos);
			if (event.type == sf::Event::Closed) {
				delete[] program.files.files;
				window.close();
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right)) || (((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left)) && (buttons.arrowRight.getGlobalBounds().contains(pos.x, pos.y)))) {
				if (program.picture.num + 1 == program.files.arrSize) {
					program.picture.num = 0;
				}
				else {
					program.picture.num++;
				}
				initializePicture(program.windowSize, program.files, &program.picture, 2);
			}
			if (event.type == Event::Resized) {
				program.windowSize.x = event.size.width;
				program.windowSize.y = event.size.height;
				resizePicture(program.windowSize, program.picture);
				//установка камеры
				window.setView(View(FloatRect(0, 0, float(program.windowSize.x), float(program.windowSize.y))));
			}
			if ((Keyboard::isKeyPressed(Keyboard::Left)) || (((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left)) && (buttons.arrowLeft.getGlobalBounds().contains(pos.x, pos.y)))) {
				if (program.picture.num == 0) {
					program.picture.num = program.files.arrSize;
				}
				program.picture.num--;
				initializePicture(program.windowSize, program.files, &program.picture, 1);
			}
		}
		window.setTitle(program.picture.title);
		program.picture.sprite->setTexture((*program.picture.texture));
		resizePicture(program.windowSize, program.picture);
		window.clear();
		window.draw(*program.picture.sprite);
		buttons.arrowRight.setPosition(float(window.getSize().x - WIDTH_ARROW_SPRITE), float(window.getSize().y / DEVIDE_INTO_TWO));
		buttons.arrowLeft.setPosition(WIDTH_ARROW_SPRITE, float(window.getSize().y / DEVIDE_INTO_TWO));
		window.draw(buttons.arrowLeft);
		window.draw(buttons.arrowRight);
		window.display();
		program.windowSize = window.getSize();
	}
}

void startProgram(Program &program, Buttons &buttons) {
	actionProgram(program, buttons);
}