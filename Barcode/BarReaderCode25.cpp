// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderCode25.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorCode25.h"
#include <sstream>

CBarReaderCode25::CBarReaderCode25(CBarBitmap* bmp) : CBarReader(bmp)
{
}

CBarReaderCode25::~CBarReaderCode25(void)
{
}

std::string CBarReaderCode25::BinaryToLogic(std::string code)
{
	if (code.size()==0)
		throw CBarReaderException("Could not handle 0 length binary code");
	if (code.size()!=14)
		throw CBarReaderException("Expected 14 length binary code");
	if (code[0]!='1')
		throw CBarReaderException("Expected bit 1 on zero position");
	size_t i=0, c=0;
	std::string logic;
	while (i<code.size()) {
		while (i<code.size() && code[i]!='0') {
			++i;
			++c;
		}
		if (c==1)
			logic+='N';
		else if (c==3)
			logic+='W';
		else
			throw CBarReaderException("Code not N or W");
		++i;
		c=0;
	}
	return logic;
}

char CBarReaderCode25::Decode(std::string& code, bool toascii)
{
	if (code=="11011010")
		return Code25Start;
	else if (code=="11010110")
		return Code25Start;
	char ch=0;
	std::string logic;
	logic=BinaryToLogic(code);

	if (logic=="NNWWN")
		ch=0;
	else if (logic=="WNNNW")
		ch=1;
	else if (logic=="NWNNW")
		ch=2;
	else if (logic=="WWNNN")
		ch=3;
	else if (logic=="NNWNW")
		ch=4;
	else if (logic=="WNWNN")
		ch=5;
	else if (logic=="NWWNN")
		ch=6;
	else if (logic=="NNNWW")
		ch=7;
	else if (logic=="WNNWN")
		ch=8;
	else if (logic=="NWNWN")
		ch=9;

	if (toascii)
		ch+='0';

	return ch;
}

std::string CBarReaderCode25::manage(std::string& bin, int npos)
{
	std::string code;
	code=bin.substr(0, npos);
	bin.erase(0, npos);
	return code;
}

std::string CBarReaderCode25::read()
{
	std::string bin, code;
	std::stringstream ss;
	char cd;

	bin=CBarReader::read();

	code=manage(bin, 8); cd=Decode(code, false);
	if (cd!=Code25Start)
		throw CBarReaderException("Beginning of the code not Start");

	while (bin.size()>0) {
		code=manage(bin, 8);
		if (code=="1101011")
			continue;
		code+=manage(bin, 6);
		cd=Decode(code, true);
		ss << cd;
	}

	return ss.str();
}

void CBarReaderCode25::check(std::string code)
{
	char cd1=code[code.size()-1];
	code=code.substr(0, code.size()-1);
	char* p=const_cast<char*>(code.c_str());
	CBarGeneratorCode25 gen(NULL);
	char cd2=gen.CheckDigit(p);
	if (cd1!=cd2)
		throw CBarReaderException("Check digit does not match");
}