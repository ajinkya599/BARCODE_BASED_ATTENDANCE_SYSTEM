// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderEan13.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorEan13.h"
#include <sstream>

CBarReaderEan13::CBarReaderEan13(CBarBitmap* bmp) : CBarReader(bmp)
{
}

CBarReaderEan13::~CBarReaderEan13(void)
{
}

std::string CBarReaderEan13::manage(std::string& bin, int npos)
{
	std::string code;
	code=bin.substr(0, npos);
	bin.erase(0, npos);
	return code;
}

int CBarReaderEan13::DecodeDigit(std::string code,
								 int firstDigit,
								 int pos)
{
	if (pos>0 && pos>7) {
		if (!code.compare("1110010"))
			return 0;
		else if (!code.compare("1100110"))
			return 1;
		else if (!code.compare("1101100"))
			return 2;
		else if (!code.compare("1000010"))
			return 3;
		else if (!code.compare("1011100"))
			return 4;
		else if (!code.compare("1001110"))
			return 5;
		else if (!code.compare("1010000"))
			return 6;
		else if (!code.compare("1000100"))
			return 7;
		else if (!code.compare("1001000"))
			return 8;
		else if (!code.compare("1110100"))
			return 9;
		else
			throw CBarReaderException("Unknown code");
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
			if (!code.compare("0100111"))
				return 0;
			else if (!code.compare("0110011"))
				return 1;
			else if (!code.compare("0011011"))
				return 2;
			else if (!code.compare("0100001"))
				return 3;
			else if (!code.compare("0011101"))
				return 4;
			else if (!code.compare("0111001"))
				return 5;
			else if (!code.compare("0000101"))
				return 6;
			else if (!code.compare("0010001"))
				return 7;
			else if (!code.compare("0001001"))
				return 8;
			else if (!code.compare("0010111"))
				return 9;
			else
				throw CBarReaderException("Unknown code");
		}
		else {
			if (!code.compare("0001101"))
				return 0;
			else if (!code.compare("0011001"))
				return 1;
			else if (!code.compare("0010011"))
				return 2;
			else if (!code.compare("0111101"))
				return 3;
			else if (!code.compare("0100011"))
				return 4;
			else if (!code.compare("0110001"))
				return 5;
			else if (!code.compare("0101111"))
				return 6;
			else if (!code.compare("0111011"))
				return 7;
			else if (!code.compare("0110111"))
				return 8;
			else if (!code.compare("0001011"))
				return 9;
			else
				throw CBarReaderException("Unknown code");
		}
	}
}


std::string CBarReaderEan13::read(int firstDigit)
{
	std::string bin, binp, code;
	std::stringstream ss;

	bin="";
	binp=CBarReader::read();
	for (size_t i=0;i<binp.length();i+=2)
		bin+=binp[i];

	code=manage(bin, 3);
	if (code.compare("101")>0)
		throw CBarReaderException("Beginning of the code not 101");

	ss << firstDigit;
	code=manage(bin, 7);
	ss << DecodeDigit(code, firstDigit, -1);
	for (int i=3;i<=13;i++) {
		code=manage(bin, 7);
		ss << DecodeDigit(code, firstDigit, i);

		if (i==7) {
			code=manage(bin, 5);
			if (code.compare("01010")>0)
				throw CBarReaderException("No 01010 mark");
		}
	}

	code=manage(bin, 3);
	if (code.compare("101")>0)
		throw CBarReaderException("End of the code not 101");

	return ss.str();
}

void CBarReaderEan13::check(std::string code)
{
	EAN13 ean13;
	char ch;
	ean13=0;
	for (int i=0;i<13;i++) {
		ch=code[i];
		ean13+=atoi(&ch);
		ean13*=10;
	}
	ean13/=10;

	CBarGeneratorEan13 gen(NULL);
	int checkDigit=gen.CheckDigit(ean13);
	if (code[12]!=checkDigit+'0')
		throw CBarReaderException("Check digits does not match");
}