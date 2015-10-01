#pragma once

#include "main.h"

float GetFileSize(string &path);

bool IsImage(string fileName);

Files GetFileList(string &currentPath);

void InitializePicture(Vector2u windowSize, Files files, Picture *pic, char diraction);

void ResizePicture(Vector2u windowSize, Picture & picture);
