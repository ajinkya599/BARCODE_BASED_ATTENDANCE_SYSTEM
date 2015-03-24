// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include "BarReader.h"
#include <xstring>

#pragma once

class BARAPI CBarReaderEan8 : public CBarReader
{
public:
	CBarReaderEan8(CBarBitmap* bmp);
	virtual ~CBarReaderEan8(void);

	int CBarReaderEan8::DecodeDigit(std::string code,
									int pos);
	std::string manage(std::string& bin, int npos);
	std::string read();
	void check(std::string code);
};
