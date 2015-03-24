// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include "BarReader.h"
#include <xstring>

#pragma once

class BARAPI CBarReaderEan13 : public CBarReader
{
public:
	CBarReaderEan13(CBarBitmap* bmp);
	virtual ~CBarReaderEan13(void);

	int DecodeDigit(std::string code,
		   		    int firstDigit,
					int pos);
	std::string manage(std::string& bin, int npos);
	std::string read(int firstDigit);
	void check(std::string code);
};
