// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"
#include <xstring>

#pragma once

class BARAPI CBarReaderException : public std::exception {
public:
	CBarReaderException(const char* msg) : std::exception(msg) { }
};

class BARAPI CBarReader
{
protected:
	CBarBitmap* m_bmp;
public:
	CBarReader(CBarBitmap* bmp);
	virtual ~CBarReader(void);

	static int findTerminalBar(CBarBitmap& bmp, int sx, int vx);
	virtual std::string read(int term_left=-1, int term_right=-1, int posy=-1);
};
