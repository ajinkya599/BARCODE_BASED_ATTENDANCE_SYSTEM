#include "StdAfx.h"

#include "Form1.h"
#include "Form_viewall.h"
#include "login.h" 
#include "Form_attd.h"
#include "Form_prof2.h"
using namespace bba_project;

/*
void Form1::take_attd_Click(System::Object^  sender, System::EventArgs^  e){
	MyForm^ Form_attd = gcnew MyForm();
	Form_attd->ShowDialog();
}
*/

Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e){
	user->Text = login::username; //displaying users name

}


//add button allows user to go to a new form- Form_Add, various crime related can be stored in that form.




//to view all records on criminal activities.




//to logout from current session
Void Form1::button_logout_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->Close();	//close Form1
	login^ f1 = gcnew login();
	f1->ShowDialog();							//show login form
}


//to search the keywords in textBox_keyword
Void Form1::button_search_Click(System::Object^  sender, System::EventArgs^  e) {
	//search function yet to be defined

	String^ sub;
	String^uname = user->Text;
	if (comboBox_searchby->Text=="")
	{
		label_adwarn->Visible = true;
	}
	else{
		
	
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
	
		Form_viewall^ f2 = gcnew Form_viewall(sub, uname);
		f2->ShowDialog();
									
	}
}

