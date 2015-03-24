// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorCode39.h"
#include <sstream>

int CBarGeneratorCode39::CheckDigit(Code39 code39)
{
	int sum=0;
	for (size_t i=0;i<strlen(code39);i++)
		sum+=code39[i];
	sum%=43;
	return sum;
}

std::string CBarGeneratorCode39::LogicToBinary(const char* logic)
{
	std::string ret="";

	char p='1';
	for (size_t i=0;i<strlen(logic);i++) {
		ret=ret+p;
		if (logic[i]=='w')
			ret=ret+p;

		p=p=='1' ? '0' : '1';
	}

	return ret;
}

std::string CBarGeneratorCode39::EncodeChar(char ch)
{
	const char* bpWeights;
	switch (ch) {
		case 0 :  bpWeights="nnnwwnwnn"; break;
		case 1 :  bpWeights="wnnwnnnnw"; break;
		case 2 :  bpWeights="nnwwnnnnw"; break;
		case 3 :  bpWeights="wnwwnnnnn"; break;
		case 4 :  bpWeights="nnnwwnnnw"; break;
		case 5 :  bpWeights="wnnwwnnnn"; break;
		case 6 :  bpWeights="nnwwwnnnn"; break;
		case 7 :  bpWeights="nnnwnnwnw"; break;
		case 8 :  bpWeights="wnnwnnwnn"; break;
		case 9 :  bpWeights="nnwwnnwnn"; break;
		case 10:  bpWeights="wnnnnwnnw"; break;
		case 11:  bpWeights="nnwnnwnnw"; break;
		case 12:  bpWeights="wnwnnwnnn"; break;
		case 13:  bpWeights="nnnnwwnnw"; break;
		case 14:  bpWeights="wnnnwwnnn"; break;
		case 15:  bpWeights="nnwnwwnnn"; break;
		case 16:  bpWeights="nnnnnwwnw"; break;
		case 17:  bpWeights="wnnnnwwnn"; break;
		case 18:  bpWeights="nnwnnwwnn"; break;
		case 19:  bpWeights="nnnnwwwnn"; break;
		case 20:  bpWeights="wnnnnnnww"; break;
		case 21:  bpWeights="nnwnnnnww"; break;
		case 22:  bpWeights="wnwnnnnwn"; break;
		case 23:  bpWeights="nnnnwnnww"; break;
		case 24:  bpWeights="wnnnwnnwn"; break;
		case 25:  bpWeights="nnwnwnnwn"; break;
		case 26:  bpWeights="nnnnnnwww"; break;
		case 27:  bpWeights="wnnnnnwwn"; break;
		case 28:  bpWeights="nnwnnnwwn"; break;
		case 29:  bpWeights="nnnnwnwwn"; break;
		case 30:  bpWeights="wwnnnnnnw"; break;
		case 31:  bpWeights="nwwnnnnnw"; break;
		case 32:  bpWeights="wwwnnnnnn"; break;
		case 33:  bpWeights="nwnnwnnnw"; break;
		case 34:  bpWeights="wwnnwnnnn"; break;
		case 35:  bpWeights="nwwnwnnnn"; break;
		case 36:  bpWeights="nwnnnnwnw"; break;
		case 37:  bpWeights="wwnnnnwnn"; break;
		case 38:  bpWeights="nwwnnnwnn"; break;
		case 39:  bpWeights="nwnwnwnnn"; break;
		case 40:  bpWeights="nwnwnnnwn"; break;
		case 41:  bpWeights="nwnnnwnwn"; break;
		case 42:  bpWeights="nnnwnwnwn"; break;
		case Code39StartStop: bpWeights="nwnnwnwnn"; break;
		default:
			throw CBarGeneratorException("Character not supported");
	}

	return LogicToBinary(bpWeights);
}

std::string CBarGeneratorCode39::EncodeChars(Code39 code39)
{
	std::string part, binary;

	binary+=EncodeChar(Code39StartStop);
	binary+='0';
	for (size_t i=0;i<strlen(code39);i++) {
		binary+=EncodeChar(code39[i]);
		binary+='0';
	}
	binary+=EncodeChar(Code39StartStop);
	
	return binary;
}

void CBarGeneratorCode39::DrawBars(std::string binary)
{
	const int top=10;
	int left=22;
	m_bmp->SetSize(left*2+(binary.length()*2), 120);
	for (size_t i=0;i<binary.length();i++) {
		if (binary[i]=='1')
			m_bmp->DrawBar(2, 91, left, top);

		left+=2;
	}
}

void CBarGeneratorCode39::DrawChars(std::string human)
{
	const int top=105;
	int left=52;
	
	for (size_t i=0;i<human.length();i++) {
		m_bmp->DrawChar(left, top, human[i]);
		left+=28;
	}
}

void CBarGeneratorCode39::PreCode(Code39 code39)
{
	for (size_t i=0;i<strlen(code39);i++) {
		if (code39[i]>='0' && code39[i]<='9')
			code39[i]-='0';
		else if (code39[i]>='A' && code39[i]<='Z')
			code39[i]-='A'-10;
		else
			throw CBarGeneratorException("Character not supported");
	}
}

void CBarGeneratorCode39::Generate(void* data)
{
	Code39 code39=(Code39)data;
	std::string human((char*)data);
	PreCode(code39);
	
	std::string binary;
	binary=EncodeChars(code39);
	DrawBars(binary);
	DrawChars(human);
}
