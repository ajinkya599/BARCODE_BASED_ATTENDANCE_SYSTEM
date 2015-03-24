#include "StdAfx.h"
#include "dbconnect.h"
#include "Form1.h"
#include "Form_viewall.h"
#include "login.h" 
#include "Form_prof2.h"

using namespace bba_project;

Void Form_prof::button_logout_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->Close();	//close Form_prof
	login^ f1 = gcnew login();
	f1->ShowDialog();							//show login form
}
Void Form_prof::Form_prof_Load(System::Object^  sender, System::EventArgs^  e){
	user->Text = login::username; //displaying users name

}

Void Form_prof::comboBox_action_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (comboBox_action->Text == "VIEW ATTENDANCE")
	{
		ldate->Visible = false;
		date_box->Visible = false;
	}

	else
	{
		ldate->Visible = true;
		date_box->Visible = true;
	}

}

Void Form_prof::button_search_Click(System::Object^  sender, System::EventArgs^  e) {
	//search function yet to be defined

	String^ sub;
	
	if (comboBox_searchby->Text == "" || comboBox_action->Text == "" || (comboBox_action->Text == "GIVE ALL" && date_box->Text == "") || (comboBox_action->Text == "GIVE NONE" && date_box->Text == ""))
	{
		label_adwarn->Visible = true;
	}

	else{

		label_adwarn->Visible = false;

		if (comboBox_searchby->Text == "ALGORITHMS")
			sub = "2_1";
		if (comboBox_searchby->Text == "COA")
			sub = "2_2";

		if (comboBox_searchby->Text == "FLAT")
			sub = "2_3";

		if (comboBox_searchby->Text == "S/W ENGG")
			sub = "2_4";

		if (comboBox_searchby->Text == "DATA STRUCTURES")
			sub = "2_5";
		
		if (comboBox_action->Text == "VIEW ATTENDANCE")
		{
			Form_viewall^ f2 = gcnew Form_viewall(sub, login::username, "not required");
			f2->ShowDialog();
		}

		else if (comboBox_action->Text == "GIVE ALL")
		{
			dbconnect db;
			db.give_all(sub,date_box->Text);
			//String^ date = this->roll->Text;
		}

		else if (comboBox_action->Text == "GIVE NONE")
		{
			dbconnect db;
			db.give_none(sub, date_box->Text);
		}
	}
}

