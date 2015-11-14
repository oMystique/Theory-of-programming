#pragma once

#include "main.h"

float GetFileSize(string &path);

bool IsImage(string fileName);

Files GetFileList(string const &currentPath);

void InitializePicture(Vector2u &windowSize, Files &files, Picture &pic, char direction);

void ResizePicture(Vector2u &windowSize, Picture &picture);
