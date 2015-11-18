#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include "functions.h"


float GetFileSize(string const &path, string const &name) {
	fstream fp(path + name, fstream::in);
	fp.seekp(0, ios::end);
	streamoff size = fp.tellp();
	return size / SIZE_STORAGE_UNIT / SIZE_STORAGE_UNIT;
}


bool IsImage(string fileName) {

	if (!strrchr(fileName.c_str(), '.')) {
		return false;
	}
	string extensionList[] = { 
		"jpg",
		"jpeg",
		"png",
		"gif",
		"bmp" };
	for (string &extension: extensionList) {
		if (fileName.substr(fileName.find_last_of(".") + 1) == extension)
			return true;
	}
	return false;
}


Files GetFileList(string const &currentPath) {
	string path = currentPath + string("*");
	Files files;
	files.path = currentPath;
	files.arrSize = 0;
	unsigned long i = 0; // unsigned - не отрицательное.
	WIN32_FIND_DATA fileData;
	HANDLE hFile = FindFirstFile(path.c_str(), &fileData); //поиск первого файла
	if (hFile != INVALID_HANDLE_VALUE) { //Если файл существует
		while (FindNextFile(hFile, &fileData)) {
			if (!(fileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)) { //если файл не папка
				files.arrSize++;
			}
		}
		files.files = new string[files.arrSize];
		hFile = FindFirstFile(path.c_str(), &fileData);
		while (FindNextFile(hFile, &fileData)) {
			if (!(fileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)) {
				if (IsImage(fileData.cFileName)) {
					files.files[i] = fileData.cFileName;
					i++;
				}
			}

		}
		FindClose(hFile);
	}
	files.arrSize = i;
	return files;
}


void CheckAvailability(Image &image, Picture &pic, Files &files) { 
	pic.error = false;
	if (image.getSize().x >= MAX_TEXTURE_SIZE || image.getSize().y >= MAX_TEXTURE_SIZE) {
		cout << "Image resolution is very big: " << image.getSize().x << "x" << image.getSize().y << "\n";
		pic.error = true;
	}
	else if (!(image.loadFromFile(files.path + files.files[pic.num]))) {
		cout << "Can not open file: " << files.files[pic.num] << "\n";
		pic.error = true;
	}
	else if (GetFileSize(files.path, pic.title) > MAX_FILE_SIZE) {
		cout << "File size is very big.";
		pic.error = true;
	}
}


void InitializePicture(Vector2u &windowSize, Files &files, Picture &pic, char direction) {
	pic.zoom = false;
	if (!pic.error) {
		delete(pic.sprite);
	}
	Image *image = new Image();
	string path = files.path + files.files[pic.num];
	CheckAvailability(*image, pic, files);
	delete(pic.texture);
	pic.texture = new Texture();
	pic.texture->loadFromImage(*image);
	if (pic.error){
		pic.texture->loadFromFile("./images/error.jpg");
	}
		delete(image);
		pic.sprite = new Sprite();
		pic.sprite->setPosition(0, 0);
		pic.sprite->setTexture(*(pic.texture));
		pic.sprite->setOrigin(pic.texture->getSize().x / GET_HALF, pic.texture->getSize().y / GET_HALF);
		pic.title = string(files.files[pic.num]);
	cout << "Size of " + pic.title << ": " << GetFileSize(files.path, pic.title) << " mb. \n";
}


void ZoomPicture(Picture &pic, double typeZoom) {
	pic.zoom = true;
	if (typeZoom > 0) {
		if (pic.scale <= MAX_ZOOM) {
			pic.scale += typeZoom;
		}
	}
	else {
		if (pic.scale >= MIN_ZOOM) {
			pic.scale += typeZoom;
		}
	}
}

void ResizePicture(Vector2u &windowSize, Picture &picture) {
	float scale = 1;
	float oldScale = picture.sprite->getScale().x;
	if (picture.texture->getSize().x * oldScale <= windowSize.x || picture.texture->getSize().y * oldScale) {
		if (picture.texture->getSize().x * oldScale - windowSize.x < picture.texture->getSize().y * oldScale - windowSize.y) {
			scale = float(windowSize.y) / picture.texture->getSize().y;
		}
		else {
			scale = float(windowSize.x) / picture.texture->getSize().x;
		}
	}
	if (picture.zoom) {
		scale = float(picture.scale);
	}
	picture.sprite->setScale(Vector2f(scale, scale));
	picture.scale = scale;
	picture.left = (windowSize.x) / GET_HALF;
	picture.top = (windowSize.y) / GET_HALF;
	picture.sprite->setPosition(Vector2f(float(picture.left), float(picture.top)));
	picture.texture->setSmooth(true); //сглаживание
}