// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarNoise.h"
#include "BarReader.h"
#include "EasyBMP\EasyBMP_win32.h"
#include <ctime>
#include <cstdlib>

CBarNoise::CBarNoise(CBarBitmap* bmp)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	m_bmp=bmp;
}

CBarNoise::~CBarNoise(void)
{
}

void CBarNoise::injectNoise(int num, int tolerance)
{
	int term_left, term_right;
	term_left=CBarReader::findTerminalBar(*m_bmp, 0, 1);
	term_right=CBarReader::findTerminalBar(*m_bmp, 
										   m_bmp->GetWidth()-1, 
										   -1);
	term_left+=tolerance;
	term_right-=tolerance;
	
	int pos;
	RGBApixel pixel;
	for (int c=0;c<num;++c) {
		pos=rand()%(term_right-term_left)+term_left;
		for (int h=0;h<m_bmp->GetHeight();++h) {
			m_bmp->GetPixel(pos, h, &pixel);
			pixel.Blue=~pixel.Blue;
			pixel.Green=~pixel.Green;
			pixel.Red=~pixel.Red;
			m_bmp->SetPixel(pos, h, &pixel);
		}
	}
}
