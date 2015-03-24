// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarAPI.h"
#include <exception>

#pragma once

class BARAPI CBarBitmapException : public std::exception {
public:
	CBarBitmapException(const char* msg) : std::exception(msg) { }
};

class BARAPI CBarBitmap
{
public:
	virtual ~CBarBitmap() { }

	virtual void SetSize(int width, int height) = 0;
	virtual void DrawDigit(int left, int top,
		char num) = 0;
	virtual void DrawLetter(int left, int top,
		char ch) = 0;
	virtual void DrawChar(int left, int top,
		char ch) = 0;
	virtual void DrawBar(int width, int height, 
		int left, int top) = 0;
	virtual void Load(char* fileName) = 0;
	virtual void Save(char* fileName) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;

	virtual void GetPixel(int i, int j, void* buff) = 0;
	virtual void SetPixel(int i, int j, void* buff) = 0;
};
