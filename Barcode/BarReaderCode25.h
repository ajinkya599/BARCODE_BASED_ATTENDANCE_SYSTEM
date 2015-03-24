// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include "BarReader.h"
#include "BarGeneratorCode25.h"
#include <xstring>

#pragma once

class BARAPI CBarReaderCode25 : public CBarReader
{
	std::string BinaryToLogic(std::string code);
	char Decode(std::string& code, bool toascii=false);
public:
	CBarReaderCode25(CBarBitmap* bmp);
	virtual ~CBarReaderCode25(void);

	std::string manage(std::string& bin, int npos);
	std::string read();
	void check(std::string code);
};
