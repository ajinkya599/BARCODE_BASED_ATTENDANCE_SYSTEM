// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef char* Code39;

enum Code39FNC {
	Code39StartStop=100
};

class BARAPI CBarGeneratorCode39 : public CBarGenerator
{
	std::string LogicToBinary(const char* logic);
	std::string EncodeChars(Code39 code39);
	std::string EncodeChar(char ch);
	void DrawBars(std::string binary);
	void DrawChars(std::string human);
public:
	CBarGeneratorCode39(CBarBitmap* bmp)  : CBarGenerator(bmp) { }
	~CBarGeneratorCode39(void) { }

	void PreCode(Code39 code39);
	int CheckDigit(Code39 code39);
	void Generate(void* data);
};
