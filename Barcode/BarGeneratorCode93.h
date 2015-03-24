// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGenerator.h"
#include <xstring>

#pragma once

typedef char* Code93;

enum Code93FNC {
	Code93StartStop=100
};

enum Code93CheckDigit {
	Code93CheckDigitA=20,
	Code93CheckDigitB=15
};

class BARAPI CBarGeneratorCode93 : public CBarGenerator
{
	std::string LogicToBinary(const char* logic);
	std::string EncodeChars(Code93 code93, size_t size);
	std::string EncodeChar(char ch);
	void DrawBars(std::string binary);
	void DrawChars(std::string human);
public:
	int CheckDigit(Code93 code93, Code93CheckDigit mode);
	void PreCode(Code93 code93);

	CBarGeneratorCode93(CBarBitmap* bmp)  : CBarGenerator(bmp) { }
	~CBarGeneratorCode93(void) { }

	void Generate(void* data);
};
