// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderEan8.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorEan8.h"
#include <sstream>

CBarReaderEan8::CBarReaderEan8(CBarBitmap* bmp) : CBarReader(bmp)
{
}

CBarReaderEan8::~CBarReaderEan8(void)
{
}

std::string CBarReaderEan8::manage(std::string& bin, int npos)
{
	std::string code;
	code=bin.substr(0, npos);
	bin.erase(0, npos);
	return code;
}

int CBarReaderEan8::DecodeDigit(std::string code,
								int pos)
{
	if (pos>4) {
		if (code=="1110010")	  return 0;
		else if (code=="1100110") return 1;
		else if (code=="1101100") return 2;
		else if (code=="1000010") return 3;
		else if (code=="1011100") return 4;
		else if (code=="1001110") return 5;
		else if (code=="1010000") return 6;
		else if (code=="1000100") return 7;
		else if (code=="1001000") return 8;
		else if (code=="1110100") return 9;
		else
			throw CBarReaderException("Code not supported");
	}
	else {
		if (code=="0001101")	  return 0;
		else if (code=="0011001") return 1;
		else if (code=="0010011") return 2;
		else if (code=="0111101") return 3;
		else if (code=="0100011") return 4;
		else if (code=="0110001") return 5;
		else if (code=="0101111") return 6;
		else if (code=="0111011") return 7;
		else if (code=="0110111") return 8;
		else if (code=="0001011") return 9;
		else
			throw CBarReaderException("Code not supported");
	}
}


std::string CBarReaderEan8::read()
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

	for (int i=1;i<=8;i++) {
		code=manage(bin, 7);
		ss << DecodeDigit(code, i);

		if (i==4) {
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

void CBarReaderEan8::check(std::string code)
{
	EAN8 ean8;
	char ch;
	ean8=0;
	for (int i=0;i<8;i++) {
		ch=code[i];
		ean8+=atoi(&ch);
		ean8*=10;
	}
	ean8/=10;

	CBarGeneratorEan8 gen(NULL);
	int checkDigit=gen.CheckDigit(ean8);
	if (code[7]!=checkDigit+'0')
		throw CBarReaderException("Check digits does not match");
}