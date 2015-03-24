// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderCode39.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorCode39.h"
#include <sstream>

CBarReaderCode39::CBarReaderCode39(CBarBitmap* bmp) : CBarReader(bmp)
{
}

CBarReaderCode39::~CBarReaderCode39(void)
{
}

std::string CBarReaderCode39::BinaryToLogic(std::string code)
{
	size_t i=0;
	std::string ret;
	while (i<code.size()) {
		if (i+1<code.size() &&
			code[i]==code[i+1]) {
			ret+='w';
			i+=2;
		}
		else {
			ret+='n';
			++i;
		}
	}
	if (ret.size()!=9)
		throw CBarReaderException("Logic code schould be 9 chars");
	return ret;
}

char CBarReaderCode39::Decode(std::string& code, bool toascii)
{
	char ch=0;
	std::string logic;
	logic=BinaryToLogic(code);

	if (logic=="nnnwwnwnn")
		ch=0;
	else if (logic=="wnnwnnnnw")
		ch=1;
	else if (logic=="nnwwnnnnw")
		ch=2;
	else if (logic=="wnwwnnnnn")
		ch=3;
	else if (logic=="nnnwwnnnw")
		ch=4;
	else if (logic=="wnnwwnnnn")
		ch=5;
	else if (logic=="nnwwwnnnn")
		ch=6;
	else if (logic=="nnnwnnwnw")
		ch=7;
	else if (logic=="wnnwnnwnn")
		ch=8;
	else if (logic=="nnwwnnwnn")
		ch=9;
	else if (logic=="wnnnnwnnw")
		ch=10;
	else if (logic=="nnwnnwnnw")
		ch=11;
	else if (logic=="wnwnnwnnn")
		ch=12;
	else if (logic=="nnnnwwnnw")
		ch=13;
	else if (logic=="wnnnwwnnn")
		ch=14;
	else if (logic=="nnwnwwnnn")
		ch=15;
	else if (logic=="nnnnnwwnw")
		ch=16;
	else if (logic=="wnnnnwwnn")
		ch=17;
	else if (logic=="nnwnnwwnn")
		ch=18;
	else if (logic=="nnnnwwwnn")
		ch=19;
	else if (logic=="wnnnnnnww")
		ch=20;
	else if (logic=="nnwnnnnww")
		ch=21;
	else if (logic=="wnwnnnnwn")
		ch=22;
	else if (logic=="nnnnwnnww")
		ch=23;
	else if (logic=="wnnnwnnwn")
		ch=24;
	else if (logic=="nnwnwnnwn")
		ch=25;
	else if (logic=="nnnnnnwww")
		ch=26;
	else if (logic=="wnnnnnwwn")
		ch=27;
	else if (logic=="nnwnnnwwn")
		ch=28;
	else if (logic=="nnnnwnwwn")
		ch=29;
	else if (logic=="wwnnnnnnw")
		ch=30;
	else if (logic=="nwwnnnnnw")
		ch=31;
	else if (logic=="wwwnnnnnn")
		ch=32;
	else if (logic=="nwnnwnnnw")
		ch=33;
	else if (logic=="wwnnwnnnn")
		ch=34;
	else if (logic=="nwwnwnnnn")
		ch=35;
	else if (logic=="nwnnnnwnw")
		ch=36;
	else if (logic=="wwnnnnwnn")
		ch=37;
	else if (logic=="nwwnnnwnn")
		ch=38;
	else if (logic=="nwnwnwnnn")
		ch=39;
	else if (logic=="nwnwnnnwn")
		ch=40;
	else if (logic=="nwnnnwnwn")
		ch=41;
	else if (logic=="nnnwnwnwn")
		ch=42;
	else if (logic=="nwnnwnwnn")
		ch=Code39StartStop;

	if (toascii) {
		if (ch>=0 && ch<=9)
			ch+='0';
		else if (ch>=10 && ch<=35) {
			ch-=10;
			ch+='A';
		}
		else {
			switch (ch) {
				case 36: ch='-';
				case 37: ch='.';
				case 39: ch='$';
				case 40: ch='/';
				case 41: ch='+';
				case 42: ch='%';
			}
		}
	}

	return ch;
}

std::string CBarReaderCode39::manage(std::string& bin, int npos)
{
	std::string code;
	code=bin.substr(0, npos);
	bin.erase(0, npos);
	return code;
}

std::string CBarReaderCode39::read()
{
	std::string bin, binp, code;
	std::stringstream ss;
	char cd;

	bin="";
	binp=CBarReader::read();
	for (size_t i=0;i<binp.size();i+=2)
		bin+=binp[i];

	code=manage(bin, 12); cd=Decode(code, false);
	code=manage(bin, 1);
	if (code!="0")
		throw CBarReaderException("Expected white terminal bar");
	if (cd!=Code39StartStop)
		throw CBarReaderException("Beginning of the code not StartB");

	while (bin.size()>0) {
		code=manage(bin, 12);
		cd=Decode(code, true);
		code=manage(bin, 1);
		if (cd!=Code39StartStop && code!="0")
			throw CBarReaderException("Expected white terminal bar");
		if (cd!=Code39StartStop)
			ss << cd;
	}

	return ss.str();
}

void CBarReaderCode39::check(std::string code)
{
	char* p=const_cast<char*>(code.c_str());

	// generujemy cyfre kontrolna bez sprawdzania
	// w code39 cyfra kontrolna nie jest wymagana
	CBarGeneratorCode39 gen(NULL);
	gen.PreCode(p);
	int cd=gen.CheckDigit(p);
}