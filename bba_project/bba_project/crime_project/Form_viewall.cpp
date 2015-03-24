#include "StdAfx.h"

#include "Form1.h"
#include "Form_viewall.h"
#include "dbconnect.h"
#include "Form_admin.h"
#pragma once
using namespace System;
using namespace bba_project;


Void Form_viewall::Form_viewall_Load(System::Object^  sender, System::EventArgs^  e){
	if (boo1=true)
	{
		Form_viewall::panel_viewall->Visible=true;
		boo1=false;
	}
	else{
		Form_viewall::panel_viewall->Visible=false;
	}
}



Form_viewall::Form_viewall(String^ sub, String^ uname){
	InitializeComponent();
	dbconnect db;
	String^ suboriginal;
	if (sub == "2_1")
		suboriginal = "ALGORITHMS";
	if (sub == "2_2")
		suboriginal = "COA";
	if (sub == "2_3")
		suboriginal = "FLAT";
	if (sub == "2_4")
		suboriginal = "S/W ENGG";
	if(sub == "2_5")
		suboriginal = "DATA STRUCTURES";

	this->label_uname->Text = uname;
	this->label_sub->Text = suboriginal;
	this->label_roll->Text = db.roll(uname);
	String^ total_string = db.total(sub);// return value of db.total is string as val->Innertext in db.total is string
	int total = System::Convert::ToInt32(total_string);
	String^ studtotal_string = db.studtotal(sub, uname);
	int studtotal = System::Convert::ToInt32(studtotal_string);
	float percnt = (((float)(studtotal)*100 )/ total);
	
	this->label_percnt->Text = System::Convert::ToString(percnt);//print final value of percnt attendance
	if (percnt < 75)
		this->label_percnt->BackColor = System::Drawing::Color::Red;

	dataGridView_records->DataSource = db.searchstudrecord(sub,uname);
	

	
	dataGridView_records->DataMember = "std";
	dataGridView_records->Refresh();
}
Form_viewall::Form_viewall(String^ user_type)
{	
	use_type = user_type;
	InitializeComponent();
	dbconnect db;
	dataGridView_records->DataSource = db.viewall();
	label_recsearchedby->Text = "";

	label_searchkeyword->Text = "";
	
	dataGridView_records->DataMember = "std";
	dataGridView_records->Refresh();
}

Form_viewall::Form_viewall(String^ sub,String^ uname, String^ user_type)
{
	
	InitializeComponent();
	dbconnect db;
	dataGridView_records->DataSource = db.sub(sub);
	
	
	dataGridView_records->DataMember = "std";
	dataGridView_records->Refresh();
	String^ suboriginal;
	if (sub == "2_1")
		suboriginal = "ALGORITHMS";
	if (sub == "2_2")
		suboriginal = "COA";
	if (sub == "2_3")
		suboriginal = "FLAT";
	if (sub == "2_4")
		suboriginal = "S/W ENGG";
	if (sub == "2_5")
		suboriginal = "DATA STRUCTURES";

	this->label_uname->Text = uname;
	this->label_sub->Text = suboriginal;
	this->label_roll->Hide();
	this->label2->Hide();
	this->label3->Hide();
	this->label_percnt->Hide();
}