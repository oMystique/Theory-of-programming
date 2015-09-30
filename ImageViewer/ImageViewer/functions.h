#pragma once

#include "main.h"

float getFileSize(string &path);

bool isImage(string fileName);

Files getFileList(string &currentPath);

void initializePicture(Vector2u windowSize, Files files, Picture *pic, char diraction);

void resizePicture(Vector2u windowSize, Picture & picture);
