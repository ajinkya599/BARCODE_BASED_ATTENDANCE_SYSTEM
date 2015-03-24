// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarBitmapWin32.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "resource.h"

HINSTANCE CBarBitmapWin32::hinstDLL=0;

CBarBitmapWin32::CBarBitmapWin32()
{
	m_bmp=new BMP;
	m_bmp->SetBitDepth(24);
}


CBarBitmapWin32::~CBarBitmapWin32(void)
{
	delete m_bmp;
}

void CBarBitmapWin32::Load(char* fileName)
{
	if (!m_bmp->ReadFromFile(fileName))
		throw CBarBitmapException("Error while loading bitmap");
}

void CBarBitmapWin32::Save(char* fileName)
{
	if (!m_bmp->WriteToFile(fileName))
		throw CBarBitmapException("Error while writing bitmap");
}

void CBarBitmapWin32::SetSize(int width, int height)
{
	m_bmp->SetSize(width, height);
}

void CBarBitmapWin32::LoadFont(WORD id, BMP& bmp)
{
	HDC dc=CreateCompatibleDC(NULL);
	if (dc==NULL)
		throw CBarBitmapException("HDC creation error");

	if (hinstDLL==0)
		hinstDLL=GetModuleHandle(NULL);
	std::string str;
	str.resize(256);
	GetModuleFileName(hinstDLL, const_cast<LPSTR>(str.c_str()), str.size());
	HBITMAP hBmp=LoadBitmap(GetModuleHandle(str.c_str()),
		MAKEINTRESOURCE(id));
	if (hBmp==NULL) {
		DeleteDC(dc);
		throw CBarBitmapException("Font loading error");
	}
	
	HBITMAPtoBMP(dc, hBmp, bmp);
	DeleteDC(dc);
	DeleteObject(hBmp);
}

void CBarBitmapWin32::DrawDigit(int left, int top,
	char num)
{
	BMP eBmp;
	LoadFont(IDB_FONT_NUM, eBmp);

	int leftMargin=8*(num-'0');

	for (int i=0;i<8;i++)
		for (int j=0;j<12;j++)
			m_bmp->SetPixel(left+i, 
			top+j, 
			eBmp.GetPixel(leftMargin+i, j));
}

void CBarBitmapWin32::DrawLetter(int left, int top,
	char ch)
{
	if (ch==' ')
		return;

	BMP eBmp;
	int topMargin;
	int width=0;

	if (ch>='A' && ch<='Z') {
		LoadFont(IDB_FONT_UPPER, eBmp);
		topMargin=(ch-'A')*13;

		switch (ch) {
			case 69: width=10; break;
			case 70: width=9; break;
			case 73: width=6; break;
			case 74: width=8; break;
			case 76: width=10; break;
			case 77: width=16; break;
			case 80: width=9; break;
			case 83: width=9; break;
			case 84: width=10; break;
			case 87: width=15; break;
			case 89: width=10; break;
			case 90: width=9; break;
			default:
				width=12;
		}
	}
	else if (ch>='a' && ch<='z') {
		LoadFont(IDB_FONT_LOWER, eBmp);
		topMargin=(ch-'a')*13;

		switch (ch) {
			case 102: width=5; break;
			case 105: width=4; break;
			case 106: width=4; break;
			case 107: width=9; break;
			case 108: width=4; break;
			case 109: width=12; break;
			case 114: width=6; break;
			case 115: width=7; break;
			case 116: width=5; break;
			case 119: width=10; break;
			case 122: width=6; break;
			default:
				width=8;
		}
	}
	else
		throw CBarBitmapException("Letter not supported");

	for (int i=0;i<width;i++)
		for (int j=0;j<13;j++)
			m_bmp->SetPixel(left+i, 
			top+j, 
			eBmp.GetPixel(i, topMargin+j));
}

void CBarBitmapWin32::DrawChar(int left, int top,
	char ch)
{
	if (ch>='0' && ch<='9')
		DrawDigit(left, top, ch);
	else if ((ch>='A' && ch<='Z') ||
			 (ch>='a' && ch<='z'))
		DrawLetter(left, top, ch);
}

void CBarBitmapWin32::DrawBar(int width, int height, 
	int left, int top)
{
	RGBApixel pixel;
	memset(&pixel, 0, sizeof(RGBApixel));
	for (int i=left;i<left+width;i++)
		for (int j=top;j<top+height;j++)
			m_bmp->SetPixel(i, j, pixel);
}

int CBarBitmapWin32::GetWidth()
{
	return m_bmp->TellWidth();
}

int CBarBitmapWin32::GetHeight()
{
	return m_bmp->TellHeight();
}

void CBarBitmapWin32::GetPixel(int i, int j, void* buff)
{
	RGBApixel* pixel=static_cast<RGBApixel*>(buff);
	*pixel=m_bmp->GetPixel(i, j);
}

void CBarBitmapWin32::SetPixel(int i, int j, void* buff)
{
	RGBApixel* pixel=static_cast<RGBApixel*>(buff);
	m_bmp->SetPixel(i, j, *pixel);
}
