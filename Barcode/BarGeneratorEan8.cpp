// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorEan8.h"
#include <sstream>

int CBarGeneratorEan8::DigitLen(EAN8 ean)
{
	std::stringstream ss;
	ss << ean;
	int len=ss.str().length();
	ss.clear();
	return len;
}

int CBarGeneratorEan8::CheckDigit(EAN8 ean)
{
	int digit=0;
	int waga=3;
	int sum=0;

	int len=DigitLen(ean);
	if (len!=8 && len!=7)
		throw CBarGeneratorException("Length of EAN8 error");

	if (len==8)
		ean/=10;
	for (int i=0;i<7;i++) {
		digit=static_cast<int>(ean-((ean/10)*10));

		sum+=digit*waga;

		waga=waga==3 ? waga=1 : waga=3;
		ean/=10;
	}

	int checkdigit=0;
	while (sum%10!=0) {
		sum++;
		checkdigit++;
	}
	return checkdigit;
}

std::string CBarGeneratorEan8::EncodeDigit(int digit,
	int pos)
{
	std::string ret="";

	if (pos>4) {
		switch (digit) {
		case 0: ret="1110010"; break;
		case 1: ret="1100110"; break;
		case 2: ret="1101100"; break;
		case 3: ret="1000010"; break;
		case 4: ret="1011100"; break;
		case 5: ret="1001110"; break;
		case 6: ret="1010000"; break;
		case 7: ret="1000100"; break;
		case 8: ret="1001000"; break;
		case 9: ret="1110100"; break;
		}
	}
	else {
		switch (digit) {
		case 0: ret="0001101"; break;
		case 1: ret="0011001"; break;
		case 2: ret="0010011"; break;
		case 3: ret="0111101"; break;
		case 4: ret="0100011"; break;
		case 5: ret="0110001"; break;
		case 6: ret="0101111"; break;
		case 7: ret="0111011"; break;
		case 8: ret="0110111"; break;
		case 9: ret="0001011"; break;
		}
	}

	if (ret.length()!=7)
		throw CBarGeneratorException("Length of bin num error");

	return ret;
}

std::string CBarGeneratorEan8::EncodeDigits(EAN8 ean8)
{
	std::string part, binary;
	int digit, pos=8;
	binary="101";
	while (pos>0) {
		digit=(int)(ean8-(ean8/10*10));

		part=EncodeDigit((int)digit, pos);
		binary=part+binary;

		if (pos==5)
			binary="01010"+binary;

		ean8/=10;
		--pos;
	}
	binary="101"+binary;
	return binary;
}

void CBarGeneratorEan8::DrawBars(std::string binary)
{
	const int top=10;
	int left=22;
	m_bmp->SetSize(178, 120);
	for (size_t i=0;i<binary.length();i++) {
		if (binary[i]=='1') {
			if (i<3 ||
				(i>30 && i<36) ||
				i>63)
				m_bmp->DrawBar(2, 96, left, top);
			else
				m_bmp->DrawBar(2, 81, left, top);
		}

		left+=2;
	}
}

void CBarGeneratorEan8::DrawDigits(EAN8 ean8)
{
	std::stringstream ss;
	ss << ean8;
	std::string num=ss.str();

	const int top=96;
	int left=30;
	
	for (int i=0;i<4;i++) {
		m_bmp->DrawDigit(left, top, num[i]);
		left+=14;
	}

	left=95;
	for (int i=4;i<8;i++) {
		m_bmp->DrawDigit(left, top, num[i]);
		left+=14;
	}
}

void CBarGeneratorEan8::Generate(void* data)
{
	EAN8* p;
	EAN8 ean8;
	p=reinterpret_cast<EAN8*>(data);
	ean8=*p;

	int digit=CheckDigit(ean8);
	if (DigitLen(ean8)==7) {
		ean8*=10;
		ean8+=digit;
	}
	else if (DigitLen(ean8)==8) {
		EAN8 lastDigit;
		lastDigit=ean8-(EAN8)((EAN8)(ean8/10)*10);
		if (lastDigit!=digit)
			throw CBarGeneratorException("Check digit error");
	}

	if (DigitLen(ean8)!=8)
		throw CBarGeneratorException("Length of EAN8 error");

	std::string binary;
	binary=EncodeDigits(ean8);

	if (binary.length()!=67)
		throw CBarGeneratorException("Binary length error");

	DrawBars(binary);
	DrawDigits(ean8);
}
