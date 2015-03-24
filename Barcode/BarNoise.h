// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmap.h"

#pragma once

class BARAPI CBarNoise
{
protected:
	CBarBitmap* m_bmp;
public:
	CBarNoise(CBarBitmap* bmp);
	virtual ~CBarNoise(void);

	void injectNoise(int num=5, int tolerance=6);
};
