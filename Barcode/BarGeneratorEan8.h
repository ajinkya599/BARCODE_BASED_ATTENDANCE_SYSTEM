// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef unsigned long long int EAN8;

class BARAPI CBarGeneratorEan8 : public CBarGenerator
{
	int DigitLen(EAN8 ean);
	std::string EncodeDigits(EAN8 ean);
	std::string EncodeDigit(int digit,
							int pos);
	void DrawBars(std::string binary);
	void DrawDigits(EAN8 ean8);
public:
	CBarGeneratorEan8(CBarBitmap* bmp) : CBarGenerator(bmp) { }
	~CBarGeneratorEan8(void) { }

	int CheckDigit(EAN8 ean);
	void Generate(void* data);
};
