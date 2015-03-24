// The file that is used to scan and identify the barcode images
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include "examples.h" 
#include "attendance.h"
#include "BarBitmapWin32.h"      // These are the various header files used to decode the barcode
#include "BarGeneratorEan8.h"
#include "BarGeneratorEan13.h"
#include "BarGeneratorCode25.h"
#include "BarGeneratorCode39.h"
#include "BarGeneratorCode93.h"
#include "BarGeneratorCode128.h"
#include "BarNoise.h"
#include "BarReader.h"
#include "BarReaderEan8.h"
#include "BarReaderEan13.h"
#include "BarReaderCode128.h"
#include "BarReaderCode39.h"
#include "BarReaderCode93.h"
#include "BarReaderCode25.h"

//#include "system.h"

#pragma once
 using namespace examples;





#include <iostream>
#include <string>



void example_code128()         //This function can be used to generate barcodes of ean 128 type
{
	CBarBitmap* bmp = new CBarBitmapWin32;
	CBarGenerator* gen = new CBarGeneratorCode128(bmp);
	Code128 code128 = new char[32];
	sprintf_s(code128, 32, "130101048");

	try {
		gen->Generate(code128);
		bmp->Save("130101048.bmp");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	delete[] code128;
	delete gen;
	delete bmp;
}

std::string  example_reader_code128(std::string s1)
{
	CBarBitmap* bmp = new CBarBitmapWin32;
	CBarReaderCode128* reader = new CBarReaderCode128(bmp);
	try {
		char* s = &s1[0];
		bmp->Load(s);
		std::string code = reader->read();
		reader->check(code);
		std::string  ret = code.substr(0, code.length() - 1);
		return ret;
	}
	catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
		return "-1";
	}

	delete reader;
	delete bmp;
}

[STAThread]
int main()
{

	attendance^ f = gcnew attendance();
	 f->ShowDialog();
	//example_reader_code128();                           // Calling the function to decode barcode
	//std:: string detail = example_reader_code128();
	/*if (strcmp(detail.c_str(), "-1") == 0)               // Condition when you encounter with a error
		//std::cout << "Scan Again"<< std::endl;
	else
		std:: cout << detail <<std:: endl;
	std:: cout << "Press any key...";
	std:: cin.get();*/
	//return 0;
}

