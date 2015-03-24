// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"

#pragma once

class BARAPI CBarGeneratorException : public std::exception {
public:
	CBarGeneratorException(const char* msg) : std::exception(msg){}
};

class BARAPI CBarGenerator
{
protected:
	CBarBitmap* m_bmp;
public:
	CBarGenerator(CBarBitmap* bmp);
	virtual ~CBarGenerator(void);

	virtual void Generate(void* data) = 0;
};
