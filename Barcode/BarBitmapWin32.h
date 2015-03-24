// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include "EasyBMP\EasyBMP.h"
#include <Windows.h>

#pragma once

class BARAPI CBarBitmapWin32 : public CBarBitmap
{
	BMP* m_bmp;
	void LoadFont(WORD id, BMP& bmp);
public:
	static HINSTANCE hinstDLL;

	CBarBitmapWin32();
	virtual ~CBarBitmapWin32(void);

	void SetSize(int width, int height);
	void DrawBar(int width, int height, int left, int top);
	void DrawDigit(int left, int top,
		char num);
	void DrawLetter(int left, int top,
		char ch);
	void DrawChar(int left, int top,
		char ch);
	void Load(char* fileName);
	void Save(char* fileName);

	int GetWidth();
	int GetHeight();

	void GetPixel(int i, int j, void* buff);
	void SetPixel(int i, int j, void* buff);
};

