// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderCode128.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorCode128.h"
#include <sstream>

CBarReaderCode128::CBarReaderCode128(CBarBitmap* bmp, Code128Mode mode) : CBarReader(bmp)
{
	this->mode=mode;
}

CBarReaderCode128::~CBarReaderCode128(void)
{
}

char CBarReaderCode128::DecodeModeB(std::string& code, bool toascii)
{
	char ch=0;
	if (code=="212222")			ch=0;
	else if (code=="222122")	ch=1;
	else if (code=="222221")	ch=2;
	else if (code=="121223")	ch=3;
	else if (code=="121322")	ch=4;
	else if (code=="131222")	ch=5;
	else if (code=="122213")	ch=6;
	else if (code=="122312")	ch=7;
	else if (code=="132212")	ch=8;
	else if (code=="221213")	ch=9;
	else if (code=="221312")	ch=10;
	else if (code=="231212")	ch=11;
	else if (code=="112232")	ch=12;
	else if (code=="122132")	ch=13;
	else if (code=="122231")	ch=14;
	else if (code=="113222")	ch=15;
	else if (code=="123122")	ch=16;
	else if (code=="123221")	ch=17;
	else if (code=="223211")	ch=18;
	else if (code=="221132")	ch=19;
	else if (code=="221231")	ch=20;
	else if (code=="213212")	ch=21;
	else if (code=="223112")	ch=22;
	else if (code=="312131")	ch=23;
	else if (code=="311222")	ch=24;
	else if (code=="321122")	ch=25;
	else if (code=="321221")	ch=26;
	else if (code=="312212")	ch=27;
	else if (code=="322112")	ch=28;
	else if (code=="322211")	ch=29;
	else if (code=="212123")	ch=30;
	else if (code=="212321")	ch=31;
	else if (code=="232121")	ch=32;
	else if (code=="111323")	ch=33;
	else if (code=="131123")	ch=34;
	else if (code=="131321")	ch=35;
	else if (code=="112313")	ch=36;
	else if (code=="132113")	ch=37;
	else if (code=="132311")	ch=38;
	else if (code=="211313")	ch=39;
	else if (code=="231113")	ch=40;
	else if (code=="231311")	ch=41;
	else if (code=="112133")	ch=42;
	else if (code=="112331")	ch=43;
	else if (code=="132131")	ch=44;
	else if (code=="113123")	ch=45;
	else if (code=="113321")	ch=46;
	else if (code=="133121")	ch=47;
	else if (code=="313121")	ch=48;
	else if (code=="211331")	ch=49;
	else if (code=="231131")	ch=50;
	else if (code=="213113")	ch=51;
	else if (code=="213311")	ch=52;
	else if (code=="213131")	ch=53;
	else if (code=="311123")	ch=54;
	else if (code=="311321")	ch=55;
	else if (code=="331121")	ch=56;
	else if (code=="312113")	ch=57;
	else if (code=="312311")	ch=58;
	else if (code=="332111")	ch=59;
	else if (code=="314111")	ch=60;
	else if (code=="221411")	ch=61;
	else if (code=="431111")	ch=62;
	else if (code=="111224")	ch=63;
	else if (code=="111422")	ch=64;
	else if (code=="121124")	ch=65;
	else if (code=="121421")	ch=66;
	else if (code=="141122")	ch=67;
	else if (code=="141221")	ch=68;
	else if (code=="112214")	ch=69;
	else if (code=="112412")	ch=70;
	else if (code=="122114")	ch=71;
	else if (code=="122411")	ch=72;
	else if (code=="142112")	ch=73;
	else if (code=="142211")	ch=74;
	else if (code=="241211")	ch=75;
	else if (code=="221114")	ch=76;
	else if (code=="413111")	ch=77;
	else if (code=="241112")	ch=78;
	else if (code=="134111")	ch=79;
	else if (code=="111242")	ch=80;
	else if (code=="121142")	ch=81;
	else if (code=="121241")	ch=82;
	else if (code=="114212")	ch=83;
	else if (code=="124112")	ch=84;
	else if (code=="124211")	ch=85;
	else if (code=="411212")	ch=86;
	else if (code=="421112")	ch=87;
	else if (code=="421211")	ch=88;
	else if (code=="212141")	ch=89;
	else if (code=="214121")	ch=90;
	else if (code=="412121")	ch=91;
	else if (code=="111143")	ch=92;
	else if (code=="111341")	ch=93;
	else if (code=="131141")	ch=94;
	else if (code=="114113")	ch=95;
	else if (code=="114311")	ch=96;
	else if (code=="411113")	ch=97;
	else if (code=="411311")	ch=98;
	else if (code=="113141")	ch=99;
	else if (code=="114131")	ch=100;
	else if (code=="311141")	ch=101;
	else if (code=="411131")	ch=102;
	else if (code=="211412")	ch=103;
	else if (code=="211214")	ch=104;
	else if (code=="211232")	ch=105;
	else if (code=="2331112")	ch=106;
	else
		throw new CBarReaderException("Code not supported");

	if (toascii)
		ch+=32;

	return ch;
}

std::string CBarReaderCode128::manage(std::string& bin, int npos)
{
	std::string code, logic;
	code=bin.substr(0, npos);
	bin.erase(0, npos);

	char ch;
	int oc;
	if (code.length()>=1) {
		ch=code[0];
		oc=0;
	}
	else
		throw new CBarReaderException("Could not decode zero length code");

	for (size_t i=0;i<code.length();i++) {
		if (ch==code[i]) {
			++oc;
			continue;
		}

		if (oc>9)
			throw new CBarReaderException("Code too long");

		logic+='0'+oc;
		oc=1;
		ch=code[i];
	}

	if (oc>0)
		logic+='0'+oc;

	return logic;
}


std::string CBarReaderCode128::read()
{
	if (this->mode!=ModeB)
		throw new CBarReaderException("Mode not supported");

	std::string bin, binp, code;
	std::stringstream ss;
	char cd;

	bin="";
	binp=CBarReader::read();
	for (size_t i=0;i<binp.length();i+=2)
		bin+=binp[i];

	code=manage(bin, 11); cd=DecodeModeB(code, false);
	if (cd!=StartB)
		throw CBarReaderException("Beginning of the code not StartB");

	while (bin.length()>=11) {
		code=manage(bin, 11);
		if (code=="233111") {
			std::string pf=manage(bin, 2);
			code+=pf;
			cd=DecodeModeB(code, false);
		}
		else
			cd=DecodeModeB(code, true);
		if (cd==Stop)
			break;
		
		ss << cd;
	}

	std::string ret=ss.str();
	ret[ret.length()-1]-=32;
	return ret;
}

void CBarReaderCode128::check(std::string code)
{
	CBarGeneratorCode128 rd(0);
	int check1=code[code.length()-1];
	code.erase(code.length()-1, 1);
	char* p=const_cast<char*>(code.c_str());
	rd.PreCode(p);
	int check2=rd.CheckDigit(p);

	if (check1!=check2)
		throw CBarReaderException("Check digits does not match");
}