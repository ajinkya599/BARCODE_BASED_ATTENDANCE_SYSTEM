// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorEan13.h"
#include <sstream>

int CBarGeneratorEan13::DigitLen(EAN13 ean)
{
	std::stringstream ss;
	ss << ean;
	int len=ss.str().length();
	ss.clear();
	return len;
}

int CBarGeneratorEan13::CheckDigit(EAN13 ean)
{
	int digit=0;
	int waga=3;
	int sum=0;

	int len=DigitLen(ean);
	if (len!=12 && len!=13)
		throw CBarGeneratorException("Length of EAN13 error");
	

	if (len==13)
		ean/=10;
	for (int i=0;i<12;i++) {
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

std::string CBarGeneratorEan13::EncodeDigit(int digit,
	int firstDigit,
	int pos)
{
	std::string ret="";

	if (pos>7) {
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
		bool partity=false;
		pos-=2;

		partity=(firstDigit==1 && (pos==2 || 
			pos==4 || 
			pos==5))||
			(firstDigit==2 && (pos==2 || 
			pos==3 || 
			pos==5))||
			(firstDigit==3 && (pos==2 || 
			pos==3 || 
			pos==4))||
			(firstDigit==4 && (pos==1 || 
			pos==4 || 
			pos==5))||
			(firstDigit==5 && (pos==1 || 
			pos==2 || 
			pos==5))||
			(firstDigit==6 && (pos==1 || 
			pos==2 || 
			pos==3))||
			(firstDigit==7 && (pos==1 || 
			pos==3 || 
			pos==5))||
			(firstDigit==8 && (pos==1 || 
			pos==3 || 
			pos==4))||
			(firstDigit==9 && (pos==1 || 
			pos==2 || 
			pos==4));

		if (partity) {
			switch (digit) {
			case 0: ret="0100111"; break;
			case 1: ret="0110011"; break;
			case 2: ret="0011011"; break;
			case 3: ret="0100001"; break;
			case 4: ret="0011101"; break;
			case 5: ret="0111001"; break;
			case 6: ret="0000101"; break;
			case 7: ret="0010001"; break;
			case 8: ret="0001001"; break;
			case 9: ret="0010111"; break;
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
	}

	if (ret.length()!=7)
		throw CBarGeneratorException("Length of bin num error");

	return ret;
}

std::string CBarGeneratorEan13::EncodeDigits(EAN13 ean13)
{
	int firstDigit;
	firstDigit=(int)(ean13/(EAN13)powf(10, 12));

	std::string part, binary;
	int digit, pos=13;
	binary="101";
	while (pos>1) {
		digit=(int)(ean13-(ean13/10*10));

		part=EncodeDigit((int)digit, firstDigit, pos);
		binary=part+binary;

		if (pos==8)
			binary="01010"+binary;

		ean13/=10;
		--pos;
	}
	binary="101"+binary;
	return binary;
}

void CBarGeneratorEan13::DrawBars(std::string binary)
{
	const int top=10;
	int left=22;
	m_bmp->SetSize(234, 120);
	for (size_t i=0;i<binary.length();i++) {
		if (binary[i]=='1') {
			if (i<3 ||
				(i>44 && i<50) ||
				i>91)
				m_bmp->DrawBar(2, 96, left, top);
			else
				m_bmp->DrawBar(2, 81, left, top);
		}

		left+=2;
	}
}

void CBarGeneratorEan13::DrawDigits(EAN13 ean13)
{
	std::stringstream ss;
	ss << ean13;
	std::string num=ss.str();

	const int top=96;
	int left=11;
	m_bmp->DrawDigit(left, top, num[0]);

	left=30;
	for (int i=1;i<=6;i++) {
		m_bmp->DrawDigit(left, top, num[i]);
		left+=13;
	}

	left=123;
	for (int i=7;i<13;i++) {
		m_bmp->DrawDigit(left, top, num[i]);
		left+=13;
	}
}

void CBarGeneratorEan13::Generate(void* data)
{
	EAN13* p;
	EAN13 ean13;
	p=reinterpret_cast<EAN13*>(data);
	ean13=*p;

	int digit=CheckDigit(ean13);
	if (DigitLen(ean13)==12) {
		ean13*=10;
		ean13+=digit;
	}
	else if (DigitLen(ean13)==13) {
		EAN13 lastDigit;
		lastDigit=ean13-(EAN13)((EAN13)(ean13/10)*10);
		if (lastDigit!=digit)
			throw CBarGeneratorException("Check digit error");
	}

	if (DigitLen(ean13)!=13)
		throw CBarGeneratorException("Length of EAN13 error");

	std::string binary;
	binary=EncodeDigits(ean13);

	if (binary.length()!=95)
		throw CBarGeneratorException("Binary length error");

	DrawBars(binary);
	DrawDigits(ean13);
}
