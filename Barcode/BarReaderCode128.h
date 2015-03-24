// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include "BarReader.h"
#include "BarGeneratorCode128.h"
#include <xstring>

#pragma once

class BARAPI CBarReaderCode128 : public CBarReader
{
	Code128Mode mode;

	char DecodeModeB(std::string& code, bool toascii=false);
public:
	CBarReaderCode128(CBarBitmap* bmp, Code128Mode mode=ModeB);
	virtual ~CBarReaderCode128(void);

	std::string manage(std::string& bin, int npos);
	std::string read();
	void check(std::string code);
};
