// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef char* Code25;

enum Code25FNC {
	Code25Start=100,
	Code25Stop=101
};

class BARAPI CBarGeneratorCode25 : public CBarGenerator
{
	std::string EncodeChars(Code25 code25);
	std::string EncodeChar(char ch);
	void DrawBars(std::string binary);
	void DrawChars(std::string human);
public:
	char CheckDigit(Code25 code25);

	CBarGeneratorCode25(CBarBitmap* bmp)  : CBarGenerator(bmp) { }
	~CBarGeneratorCode25(void) { }

	void Generate(void* data);
};
