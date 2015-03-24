#include "StdAfx.h"
#include "Form_admin.h"
#include "Form_records.h"

#include "dbconnect.h"
#pragma once 

using namespace bba_project;

Form_records::Form_records()
{
	InitializeComponent();
	dbconnect db;
	dataGridView1->DataSource = db.viewall();
	dataGridView1->DataMember = "std";
	dataGridView1->Refresh();
}

Void Form_records::button_recback_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->Close();								//close Form_records
	Form_admin^ f1 = gcnew Form_admin();
	f1->ShowDialog();							//show login form
}




Void Form_records::button_editrec_Click(System::Object^  sender, System::EventArgs^  e) {
								//show login form
}