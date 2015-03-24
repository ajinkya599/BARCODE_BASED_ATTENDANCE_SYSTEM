// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReader.h"
#include "EasyBMP\EasyBMP_win32.h"

CBarReader::CBarReader(CBarBitmap* bmp)
{
	m_bmp=bmp;
}

CBarReader::~CBarReader(void)
{
}

int CBarReader::findTerminalBar(CBarBitmap& bmp, int sx, int vx)
{
	RGBApixel pixel;
	int blackHeight;

	while (sx>=0 && sx<bmp.GetWidth()) {
		blackHeight=0;
		for (int sy=0;sy<bmp.GetHeight();++sy) {
			bmp.GetPixel(sx, sy, &pixel);
			if (pixel.Blue==0 &&
				pixel.Green==0 &&
				pixel.Red==0)
				++blackHeight;
		}
		if (blackHeight>=20)
			return sx;

		sx+=vx;
	}

	throw CBarReaderException("Terminal bar not found");
}

std::string CBarReader::read(int term_left, int term_right, int posy)
{
	std::string ret;
	if (term_left==-1)
		term_left=CBarReader::findTerminalBar(*m_bmp, 0, 1);
	if (term_right==-1)
		term_right=CBarReader::findTerminalBar(*m_bmp, 
										       m_bmp->GetWidth()-1, 
										       -1);
	if (posy==-1)
		posy=m_bmp->GetHeight()/2;

	RGBApixel pixel;
	for (int i=term_left;i<=term_right;++i) {
		m_bmp->GetPixel(i, posy, &pixel);
		if (pixel.Blue==0 &&
			pixel.Green==0 &&
			pixel.Red==0)
			ret+='1';
		else if (pixel.Blue==255 &&
				 pixel.Green==255 &&
				 pixel.Red==255)
			ret+='0';
		else
			throw CBarReaderException("Unexpected pixel while converting bitmap to binary data");
	}

	if (ret.length()==0)
		throw CBarReaderException("None data read while converting bitmap to binary data");

	return ret;
}
