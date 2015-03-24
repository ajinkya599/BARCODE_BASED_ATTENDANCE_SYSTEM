#include "StdAfx.h"
#include "Form_admin.h"
#include "Form_users.h"
#include "login.h"

#include "Form_records.h"
#include "Form_viewall.h"
#include "Form_attd.h"

using namespace bba_project;

void Form_admin::take_attd_Click(System::Object^  sender, System::EventArgs^  e){
	MyForm^ Form_attd = gcnew MyForm();
	Form_attd->ShowDialog();
}

Void Form_admin::Form_admin_Load(System::Object^  sender, System::EventArgs^  e) {
	label_welcomeadmin->Text = "Welcome: "+ login::username;
}

Void Form_admin::button_adsearch_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ sub;

	if (comboBox_searchadmin->Text == "")
	{
		label_adwarn->Visible = true;
	}
	else{


		if (comboBox_searchadmin->Text == "ALGORITHMS")
			sub = "2_1";
		if (comboBox_searchadmin->Text == "COA")
			sub = "2_2";

		if (comboBox_searchadmin->Text == "FLAT")
			sub = "2_3";

		if (comboBox_searchadmin->Text == "S/W ENGG")
			sub = "2_4";

		if (comboBox_searchadmin->Text == "DATA STRUCTURES")
			sub = "2_5";

		Form_viewall^ f2 = gcnew Form_viewall(sub, login::username, "not required");
		f2->ShowDialog();

	}
}



//to logout from current session
Void Form_admin::button_adlogout_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->Close();	//close Form_admin
	login^ f1 = gcnew login();
	f1->ShowDialog();							//show login form
}

Void Form_admin::button_aduser_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Form_users^ f2 = gcnew Form_users();
	f2->ShowDialog();							//show Form_users
}

Void Form_admin::button_adrecord_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Form_records^ f2 = gcnew Form_records();
	f2->ShowDialog();							//show Form_records
}
