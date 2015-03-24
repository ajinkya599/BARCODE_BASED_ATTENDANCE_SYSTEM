#include "StdAfx.h"
#include "Form_admin.h"
#include "Form_records.h"

#include "dbconnect.h"
#include "Form_attd.h"

#pragma once 

using namespace bba_project;




Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ a = this->roll->Text;
	String^b = this->time->Text;
	String^c = this->date->Text;
	dbconnect db;
	db.course(a, b, c);
//db.update(c,a);// for updating value
	
}

