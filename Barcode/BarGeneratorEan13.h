// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef unsigned long long int EAN13;

class BARAPI CBarGeneratorEan13 : public CBarGenerator
{
	int DigitLen(EAN13 ean);
	std::string EncodeDigits(EAN13 ean);
	std::string EncodeDigit(int digit,
							int firstDigit,
							int pos);
	void DrawBars(std::string binary);
	void DrawDigits(EAN13 ean13);
public:
	CBarGeneratorEan13(CBarBitmap* bmp) : CBarGenerator(bmp) { }
	~CBarGeneratorEan13(void) { }

	int CheckDigit(EAN13 ean);
	void Generate(void* data);
};
