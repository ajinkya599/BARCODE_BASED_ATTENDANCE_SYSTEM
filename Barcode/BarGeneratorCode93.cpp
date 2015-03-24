// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorCode93.h"
#include <sstream>

int CBarGeneratorCode93::CheckDigit(Code93 code93, Code93CheckDigit mode)
{
	int sum=0;
	int weight=1;
	for (int i=strlen(code93)-1;i>=0;i--) {
		sum+=code93[i]*weight;
		++weight;
		if (weight>mode)
			weight=1;
	}
	sum%=47;
	return sum;
}

std::string CBarGeneratorCode93::LogicToBinary(const char* logic)
{
	std::string ret="";

	char p='1';
	for (size_t i=0;i<strlen(logic);i++) {
		for (int j=0;j<logic[i]-'0';j++)
			ret=ret+p;

		p=p=='1' ? '0' : '1';
	}

	return ret;
}

std::string CBarGeneratorCode93::EncodeChar(char ch)
{
	const char* bpWeights;
	switch (ch) {
		case 0:	 bpWeights="131112"; break;
		case 1:  bpWeights="111213"; break;
		case 2:  bpWeights="111312"; break;
		case 3:  bpWeights="111411"; break;
		case 4:  bpWeights="121113"; break;
		case 5:  bpWeights="121212"; break;
		case 6:  bpWeights="121311"; break;
		case 7:  bpWeights="111114"; break;
		case 8:  bpWeights="131211"; break;
		case 9:  bpWeights="141111"; break;
		case 10: bpWeights="211113"; break;
		case 11: bpWeights="211212"; break;
		case 12: bpWeights="211311"; break;
		case 13: bpWeights="221112"; break;
		case 14: bpWeights="221211"; break;
		case 15: bpWeights="231111"; break;
		case 16: bpWeights="112113"; break;
		case 17: bpWeights="112212"; break;
		case 18: bpWeights="112311"; break;
		case 19: bpWeights="122112"; break;
		case 20: bpWeights="132111"; break;
		case 21: bpWeights="111123"; break;
		case 22: bpWeights="111222"; break;
		case 23: bpWeights="111321"; break;
		case 24: bpWeights="121122"; break;
		case 25: bpWeights="131121"; break;
		case 26: bpWeights="212112"; break;
		case 27: bpWeights="212211"; break;
		case 28: bpWeights="211122"; break;
		case 29: bpWeights="211221"; break;
		case 30: bpWeights="221121"; break;
		case 31: bpWeights="222111"; break;
		case 32: bpWeights="112122"; break;
		case 33: bpWeights="112221"; break;
		case 34: bpWeights="122121"; break;
		case 35: bpWeights="123111"; break;
		case 36: bpWeights="121131"; break;
		case 37: bpWeights="311112"; break;
		case 38: bpWeights="311211"; break;
		case 39: bpWeights="321111"; break;
		case 40: bpWeights="112131"; break;
		case 41: bpWeights="113121"; break;
		case 42: bpWeights="211131"; break;
		case 43: bpWeights="121221"; break;
		case 44: bpWeights="312111"; break;
		case 45: bpWeights="311121"; break;
		case 46: bpWeights="122211"; break;
		case Code93StartStop: bpWeights="111141"; break;
		default:
			throw CBarGeneratorException("Character not supported");
	}

	return LogicToBinary(bpWeights);
}

std::string CBarGeneratorCode93::EncodeChars(Code93 code93, size_t size)
{
	std::string part, binary;

	binary+=EncodeChar(Code93StartStop);
	for (size_t i=0;i<size;i++)
		binary+=EncodeChar(code93[i]);
	binary+=EncodeChar(Code93StartStop);
	binary+='1';
	
	return binary;
}

void CBarGeneratorCode93::DrawBars(std::string binary)
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

void CBarGeneratorCode93::DrawChars(std::string human)
{
	const int top=105;
	int left=49;
	
	for (size_t i=0;i<human.length();i++) {
		m_bmp->DrawChar(left, top, human[i]);
		left+=18;
	}
}

void CBarGeneratorCode93::PreCode(Code93 code93)
{
	for (size_t i=0;i<strlen(code93);i++) {
		if (code93[i]>='0' && code93[i]<='9')
			code93[i]-='0';
		else if (code93[i]>='A' && code93[i]<='Z')
			code93[i]-='A'-10;
		else
			throw CBarGeneratorException("Character not supported");
	}
}

void CBarGeneratorCode93::Generate(void* data)
{
	Code93 code93=(Code93)data;
	std::string human((char*)data);
	PreCode(code93);

	int code93CKSize=strlen(code93)+3;
	Code93 code93CK=new char[code93CKSize];
	memset(code93CK, 0, code93CKSize);
	strcpy_s(code93CK, strlen(code93)+1, code93);
	code93CK[code93CKSize-3]=CheckDigit(code93CK, Code93CheckDigitA);
	code93CK[code93CKSize-2]=CheckDigit(code93CK, Code93CheckDigitB);

	try {
		std::string binary;
		binary=EncodeChars(code93CK, code93CKSize-1);
		DrawBars(binary);
		DrawChars(human);
	}
	catch(CBarGeneratorException exp) {
		delete[] code93CK;
		throw CBarGeneratorException(exp.what());
	}
}
