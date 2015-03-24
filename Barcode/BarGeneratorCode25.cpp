// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorCode25.h"
#include <sstream>

char CBarGeneratorCode25::CheckDigit(Code25 code25)
{
	int sum=0;
	char w=3;
	for (size_t i=0;i<strlen(code25);i++) {
		if (code25[i]<'0' || code25[i]>'9')
			throw new CBarGeneratorException("Character not supported");

		sum+=(code25[i]-'0')*w;
		w=w==3 ? 1 : 3;
	}
	sum%=10;
	sum=10-sum;
	sum%=10;
	sum+='0';
	return sum;
}

std::string CBarGeneratorCode25::EncodeChar(char ch)
{
	const char* bin;
	switch (ch) {
		case '0' :		  bin="10101110111010"; break;
		case '1' :		  bin="11101010101110"; break;
		case '2' :		  bin="10111010101110"; break;
		case '3' :		  bin="11101110101010"; break;
		case '4' :		  bin="10101110101110"; break;
		case '5' :		  bin="11101011101010"; break;
		case '6' :		  bin="10111011101010"; break;
		case '7' :		  bin="10101011101110"; break;
		case '8' :		  bin="11101010111010"; break;
		case '9' :		  bin="10111010111010"; break;
		case Code25Start: bin="11011010"; break;
		case Code25Stop:  bin="11010110"; break;
		default:
			throw CBarGeneratorException("Character not supported");
	}

	return std::string(bin);
}

std::string CBarGeneratorCode25::EncodeChars(Code25 code25)
{
	std::string part, binary;

	binary=EncodeChar(Code25Start);
	for (size_t i=0;i<strlen(code25);i++)
		binary+=EncodeChar(code25[i]);
	binary+=EncodeChar(Code25Stop);
	
	return binary;
}

void CBarGeneratorCode25::DrawBars(std::string binary)
{
	const int top=10;
	int left=22;
	m_bmp->SetSize(left*2+binary.length(), 120);
	for (size_t i=0;i<binary.length();i++) {
		if (binary[i]=='1')
			m_bmp->DrawBar(1, 91, left, top);

		++left;
	}
}

void CBarGeneratorCode25::DrawChars(std::string human)
{
	const int top=105;
	int left=37;
	
	for (size_t i=0;i<human.length();i++) {
		m_bmp->DrawChar(left, top, human[i]);
		left+=14;
	}
}

void CBarGeneratorCode25::Generate(void* data)
{
	Code25 code25=(Code25)data;
	std::string human((char*)data);

	int code25CKSize=strlen(code25)+2;
	Code25 code25CK=new char[code25CKSize];
	memset(code25CK, 0, code25CKSize);
	strcpy_s(code25CK, strlen(code25)+1, code25);
	code25CK[code25CKSize-2]=CheckDigit(code25CK);
	
	try {
		std::string binary;
		binary=EncodeChars(code25CK);
		DrawBars(binary);
		DrawChars(human);
	}
	catch(CBarGeneratorException exp) {
		delete[] code25CK;
		throw CBarGeneratorException(exp.what());
	}
}
