// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarGeneratorCode128.h"
#include <sstream>

int CBarGeneratorCode128::CheckDigit(Code128 code128)
{
	int sum=0;
	if (this->mode==ModeB)
		sum+=StartB;
	else
		throw CBarGeneratorException("Mode not supported");
	for (size_t i=0;i<strlen(code128);i++)
		sum+=code128[i]*(i+1);
	sum%=103;
	return sum;
}

std::string CBarGeneratorCode128::LogicToBinary(const char* logic)
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

std::string CBarGeneratorCode128::EncodeModeB(char ch)
{
	const char* bpWeights;
	switch (ch) {
		case 0:   bpWeights="212222\0"; break;
		case 1:   bpWeights="222122\0"; break;
		case 2:   bpWeights="222221\0"; break;
		case 3:   bpWeights="121223\0"; break;
		case 4:   bpWeights="121322\0"; break;
		case 5:   bpWeights="131222\0"; break;
		case 6:   bpWeights="122213\0"; break;
		case 7:   bpWeights="122312\0"; break;
		case 8:   bpWeights="132212\0"; break;
		case 9:   bpWeights="221213\0"; break;
		case 10:  bpWeights="221312\0"; break;
		case 11:  bpWeights="231212\0"; break;
		case 12:  bpWeights="112232\0"; break;
		case 13:  bpWeights="122132\0"; break;
		case 14:  bpWeights="122231\0"; break;
		case 15:  bpWeights="113222\0"; break;
		case 16:  bpWeights="123122\0"; break;
		case 17:  bpWeights="123221\0"; break;
		case 18:  bpWeights="223211\0"; break;
		case 19:  bpWeights="221132\0"; break;
		case 20:  bpWeights="221231\0"; break;
		case 21:  bpWeights="213212\0"; break;
		case 22:  bpWeights="223112\0"; break;
		case 23:  bpWeights="312131\0"; break;
		case 24:  bpWeights="311222\0"; break;
		case 25:  bpWeights="321122\0"; break;
		case 26:  bpWeights="321221\0"; break;
		case 27:  bpWeights="312212\0"; break;
		case 28:  bpWeights="322112\0"; break;
		case 29:  bpWeights="322211\0"; break;
		case 30:  bpWeights="212123\0"; break;
		case 31:  bpWeights="212321\0"; break;
		case 32:  bpWeights="232121\0"; break;
		case 33:  bpWeights="111323\0"; break;
		case 34:  bpWeights="131123\0"; break;
		case 35:  bpWeights="131321\0"; break;
		case 36:  bpWeights="112313\0"; break;
		case 37:  bpWeights="132113\0"; break;
		case 38:  bpWeights="132311\0"; break;
		case 39:  bpWeights="211313\0"; break;
		case 40:  bpWeights="231113\0"; break;
		case 41:  bpWeights="231311\0"; break;
		case 42:  bpWeights="112133\0"; break;
		case 43:  bpWeights="112331\0"; break;
		case 44:  bpWeights="132131\0"; break;
		case 45:  bpWeights="113123\0"; break;
		case 46:  bpWeights="113321\0"; break;
		case 47:  bpWeights="133121\0"; break;
		case 48:  bpWeights="313121\0"; break;
		case 49:  bpWeights="211331\0"; break;
		case 50:  bpWeights="231131\0"; break;
		case 51:  bpWeights="213113\0"; break;
		case 52:  bpWeights="213311\0"; break;
		case 53:  bpWeights="213131\0"; break;
		case 54:  bpWeights="311123\0"; break;
		case 55:  bpWeights="311321\0"; break;
		case 56:  bpWeights="331121\0"; break;
		case 57:  bpWeights="312113\0"; break;
		case 58:  bpWeights="312311\0"; break;
		case 59:  bpWeights="332111\0"; break;
		case 60:  bpWeights="314111\0"; break;
		case 61:  bpWeights="221411\0"; break;
		case 62:  bpWeights="431111\0"; break;
		case 63:  bpWeights="111224\0"; break;
		case 64:  bpWeights="111422\0"; break;
		case 65:  bpWeights="121124\0"; break;
		case 66:  bpWeights="121421\0"; break;
		case 67:  bpWeights="141122\0"; break;
		case 68:  bpWeights="141221\0"; break;
		case 69:  bpWeights="112214\0"; break;
		case 70:  bpWeights="112412\0"; break;
		case 71:  bpWeights="122114\0"; break;
		case 72:  bpWeights="122411\0"; break;
		case 73:  bpWeights="142112\0"; break;
		case 74:  bpWeights="142211\0"; break;
		case 75:  bpWeights="241211\0"; break;
		case 76:  bpWeights="221114\0"; break;
		case 77:  bpWeights="413111\0"; break;
		case 78:  bpWeights="241112\0"; break;
		case 79:  bpWeights="134111\0"; break;
		case 80:  bpWeights="111242\0"; break;
		case 81:  bpWeights="121142\0"; break;
		case 82:  bpWeights="121241\0"; break;
		case 83:  bpWeights="114212\0"; break;
		case 84:  bpWeights="124112\0"; break;
		case 85:  bpWeights="124211\0"; break;
		case 86:  bpWeights="411212\0"; break;
		case 87:  bpWeights="421112\0"; break;
		case 88:  bpWeights="421211\0"; break;
		case 89:  bpWeights="212141\0"; break;
		case 90:  bpWeights="214121\0"; break;
		case 91:  bpWeights="412121\0"; break;
		case 92:  bpWeights="111143\0"; break;
		case 93:  bpWeights="111341\0"; break;
		case 94:  bpWeights="131141\0"; break;
		case 95:  bpWeights="114113\0"; break;
		case 96:  bpWeights="114311\0"; break;
		case 97:  bpWeights="411113\0"; break;
		case 98:  bpWeights="411311\0"; break;
		case 99:  bpWeights="113141\0"; break;
		case 100: bpWeights="114131\0"; break;
		case 101: bpWeights="311141\0"; break;
		case 102: bpWeights="411131\0"; break;
		case 103: bpWeights="211412\0"; break;
		case 104: bpWeights="211214\0"; break;
		case 105: bpWeights="211232\0"; break;
		case 106: bpWeights="2331112\0"; break;
	}

	return LogicToBinary(bpWeights);
}

std::string CBarGeneratorCode128::EncodeDigits(Code128 code128)
{
	std::string part, binary;

	binary+=EncodeModeB(StartB);
	for (size_t i=0;i<strlen(code128);i++) {
		if (this->mode=ModeB)
			binary+=EncodeModeB(code128[i]);
	}
	binary+=EncodeModeB(CheckDigit(code128));
	binary+=EncodeModeB(Stop);
	
	return binary;
}

void CBarGeneratorCode128::DrawBars(std::string binary)
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

void CBarGeneratorCode128::DrawChars(std::string human)
{
	const int top=105;
	int left=48;
	
	for (size_t i=0;i<human.length();i++) {
		m_bmp->DrawChar(left, top, human[i]);
		left+=22;
	}
}

void CBarGeneratorCode128::PreCode(Code128 code128)
{
	if (this->mode==ModeB) {
		for (size_t i=0;i<strlen(code128);i++)
				code128[i]-=32;
	}
}

void CBarGeneratorCode128::Generate(void* data)
{
	if (this->mode!=ModeB)
		throw CBarGeneratorException("Chosen mode not implemented yet");

	Code128 code128=(Code128)data;
	std::string human((char*)data);
	PreCode(code128);
	
	std::string binary;
	binary=EncodeDigits(code128);
	DrawBars(binary);
	DrawChars(human);
}

CBarGeneratorCode128::CBarGeneratorCode128(CBarBitmap* bmp, Code128Mode mode) : CBarGenerator(bmp)
{
	this->mode=mode;
}
