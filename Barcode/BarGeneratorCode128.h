// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef char* Code128;

enum Code128Mode {
	ModeA,
	ModeB,
	ModeC
};

enum Code128ModeFNC {
	StartA=103,
	StartB=104,
	StartC=105,
	Stop=106
};

class BARAPI CBarGeneratorCode128 : public CBarGenerator
{
	Code128Mode mode;
	
	std::string LogicToBinary(const char* logic);
	std::string EncodeDigits(Code128 code128);
	std::string EncodeModeB(char ch);
	void DrawBars(std::string binary);
	void DrawChars(std::string human);
public:
	CBarGeneratorCode128(CBarBitmap* bmp, Code128Mode mode=ModeB);
	~CBarGeneratorCode128(void) { }

	void PreCode(Code128 code128);
	int CheckDigit(Code128 code128);
	void Generate(void* data);
};
