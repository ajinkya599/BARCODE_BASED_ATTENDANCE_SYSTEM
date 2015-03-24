// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "BarReaderCode93.h"
#include "EasyBMP\EasyBMP_win32.h"
#include "BarGeneratorCode93.h"
#include <sstream>

CBarReaderCode93::CBarReaderCode93(CBarBitmap* bmp) : CBarReader(bmp)
{
}

CBarReaderCode93::~CBarReaderCode93(void)
{
}

std::string CBarReaderCode93::BinaryToLogic(std::string code)
{
	if (code.size()==0)
		throw CBarReaderException("Could not handle 0 length binary code");
	char bit;
	int c=1, sum=0;
	std::string ret;
	bit=code[0];
	size_t i=1;
	while (i<code.size()) {
		if (bit!=code[i]) {
			if (c>9)
				throw CBarReaderException("Internal err, c>9");
			ret+='0'+c;
			sum+=c;

			bit=code[i];
			c=0;
		}
		++c;
		++i;
	}
	if (c>0) {
		ret+='0'+c;
		sum+=c;
	}
	if (ret.size()!=6)
		throw CBarReaderException("Logic code schould be 6 chars");
	if (sum!=9)
		throw CBarReaderException("Sum of all bits in logic code schould be 9");
	return ret;
}

char CBarReaderCode93::Decode(std::string& code, bool toascii)
{
	char ch=0;
	std::string logic;
	logic=BinaryToLogic(code);

	if (logic=="131112")
		ch=0;
	else if (logic=="111213")
		ch=1;
	else if (logic=="111312")
		ch=2;
	else if (logic=="111411")
		ch=3;
	else if (logic=="121113")
		ch=4;
	else if (logic=="121212")
		ch=5;
	else if (logic=="121311")
		ch=6;
	else if (logic=="111114")
		ch=7;
	else if (logic=="131211")
		ch=8;
	else if (logic=="141111")
		ch=9;
	else if (logic=="211113")
		ch=10;
	else if (logic=="211212")
		ch=11;
	else if (logic=="211311")
		ch=12;
	else if (logic=="221112")
		ch=13;
	else if (logic=="221211")
		ch=14;
	else if (logic=="231111")
		ch=15;
	else if (logic=="112113")
		ch=16;
	else if (logic=="112212")
		ch=17;
	else if (logic=="112311")
		ch=18;
	else if (logic=="122112")
		ch=19;
	else if (logic=="132111")
		ch=20;
	else if (logic=="111123")
		ch=21;
	else if (logic=="111222")
		ch=22;
	else if (logic=="111321")
		ch=23;
	else if (logic=="121122")
		ch=24;
	else if (logic=="131121")
		ch=25;
	else if (logic=="212112")
		ch=26;
	else if (logic=="212211")
		ch=27;
	else if (logic=="211122")
		ch=28;
	else if (logic=="211221")
		ch=29;
	else if (logic=="221121")
		ch=30;
	else if (logic=="222111")
		ch=31;
	else if (logic=="112122")
		ch=32;
	else if (logic=="112221")
		ch=33;
	else if (logic=="122121")
		ch=34;
	else if (logic=="123111")
		ch=35;
	else if (logic=="121131")
		ch=36;
	else if (logic=="311112")
		ch=37;
	else if (logic=="311211")
		ch=38;
	else if (logic=="321111")
		ch=39;
	else if (logic=="112131")
		ch=40;
	else if (logic=="113121")
		ch=41;
	else if (logic=="211131")
		ch=42;
	else if (logic=="121221")
		ch=43;
	else if (logic=="312111")
		ch=44;
	else if (logic=="311121")
		ch=45;
	else if (logic=="122211")
		ch=46;
	else if (logic=="111141")
		ch=Code93StartStop;

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

std::string CBarReaderCode93::manage(std::string& bin, int npos)
{
	std::string code;
	code=bin.substr(0, npos);
	bin.erase(0, npos);
	return code;
}

std::string CBarReaderCode93::read()
{
	std::string bin, binp, code;
	std::stringstream ss;
	char cd;

	bin="";
	binp=CBarReader::read();
	for (size_t i=0;i<binp.size();i+=2)
		bin+=binp[i];

	code=manage(bin, 9); cd=Decode(code, false);
	if (cd!=Code93StartStop)
		throw CBarReaderException("Beginning of the code not StartB");

	while (bin.size()>0) {
		code=manage(bin, 9);
		cd=Decode(code, true);
		if (cd!=Code93StartStop)
			ss << cd;
		else {
			code=manage(bin, 1);
			if (code!="1")
				throw CBarReaderException("Right terminal bar not 1");
		}
	}

	return ss.str();
}

void CBarReaderCode93::check(std::string code)
{
	char* p=const_cast<char*>(code.c_str());
	CBarGeneratorCode93 gen(NULL);
	gen.PreCode(p);
	int read_check1=code[code.size()-2];
	int read_check2=code[code.size()-1];

	code=code.substr(0, code.length()-2);
	int calc_check1=gen.CheckDigit(p, Code93CheckDigitA);
	code+=calc_check1;
	int calc_check2=gen.CheckDigit(p, Code93CheckDigitB);
	if (read_check1!=calc_check1)
		throw CBarReaderException("First check digit does not match");
	if (read_check2!=calc_check2)
		throw CBarReaderException("Second check digit does not match");
}