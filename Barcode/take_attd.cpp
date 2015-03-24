#include "StdAfx.h"

#include "dbconnect.h"
#include "take_attd.h"

#pragma once 

using namespace examples;




Void take_attd::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ a = this->roll->Text;
	String^b = this->time->Text;
	String^c = this->date->Text;
	dbconnect db;
	db.course(a, b, c);
//db.update(c,a);// for updating value
	
}

