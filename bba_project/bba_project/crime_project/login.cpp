#include "StdAfx.h"
#include "login.h"
#include "verifier.h"
#include "Form1.h"
#include "Form_admin.h"
#include "Form_attd.h"
#include "Form_prof2.h"
#include "select_attd.h"

#pragma once
using namespace bba_project;




Void login::Attendance_Click(System::Object^  sender, System::EventArgs^  e) {

	select_attd^ f = gcnew select_attd();
	f->ShowDialog();
}
Void login::log_in_Click(System::Object^  sender, System::EventArgs^  e) {
				 
	String^ a = this->user_type_select->Text;  // Store text from all boxes in variables a, b and c.
	String^ b = this->user_id->Text;
	usertype = a;
	username = b;
	String^ c = this->pass->Text;
	if (user_type_select->Text == "Student")
	{
		user_type_select->Text == "";
		verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
		if (vf->verified == true) {
			this->Visible = false;					// Hide login form
			Form1^ form1  = gcnew Form1();			// New instance of Form1
			form1->ShowDialog();					// Show new Form1
		}
		else {
			this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
			this->user_id->Text = "";
			this->pass->Text = "";
		}
	}
	
	else if (user_type_select->Text == "Professor")
	{
		user_type_select->Text == "";
		verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
		if (vf->verified == true) {
			//MessageBox::Show(vf->verified + "");
			this->Visible = false;					// Hide login form
			Form_prof^ form1 = gcnew Form_prof();			// New instance of Form_prof
			form1->ShowDialog();					// Show new Form1
		}
		else {
			this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
			this->user_id->Text = "";
			this->pass->Text = "";
		}
	}
	else if(user_type_select->Text == "Admin")
	{
		user_type_select->Text == "";
		verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
		if (vf->verified == true) {
			this->Visible = false;					// Hide login form
			Form_admin^ form1  = gcnew Form_admin();			// New instance of Form1
			form1->ShowDialog();					// Show new Form1
	}
		/*else if (user_type_select->Text == "Professor")
		{
			user_type_select->Text == "";
			verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
			if (vf->verified == true) {
				this->Visible = false;					// Hide login form
				Form_admin^ form1 = gcnew Form_admin();			// New instance of Form1
				form1->ShowDialog();					// Show new Form1
			}*/
		else {
			this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
			this->user_id->Text = "";
			this->pass->Text = "";
		}
	}
	else{
		this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
		this->user_id->Text = "";
		this->pass->Text = "";
	}
				 
}



Void login::button_exit_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}

//Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			//to display the name
//}

//Void Form_admin::Form_admin_Load(System::Object^  sender, System::EventArgs^  e) {
	//to display the name
//}

/*Void login::pass_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if ( e->KeyChar == '\r' ) {
		String^ a = this->user_type_select->Text;  // Store text from all boxes in variables a, b and c.
		String^ b = this->user_id->Text;
		usertype = a;
		username = b;
		String^ c = this->pass->Text;
		if (user_type_select->Text == "Student")
		{
			user_type_select->Text == "";
			verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
			if (vf->verified == true) {
				this->Visible = false;					// Hide login form
				Form1^ form1  = gcnew Form1();			// New instance of Form1
				form1->ShowDialog();					// Show new Form1
			}
			else {
				this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
				this->user_id->Text = "";
				this->pass->Text = "";
			}
		}
		
			else if (user_type_select->Text == "Admin")
			{
				user_type_select->Text == "";
				verifier^ vf = gcnew verifier(a, b, c);    // Create vf object of class verifier to verify against user credentials from database.
				if (vf->verified == true) {
					this->Visible = false;					// Hide login form
					Form_admin^ form1 = gcnew Form_admin();			// New instance of Form1
					form1->ShowDialog();					// Show new Form1
				}

			else {
				this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
				this->user_id->Text = "";
				this->pass->Text = "";
			}
		}
		/*else{
			this->fail_status->Text = "Incorrect User Credentials! Please Login Again.";
			this->user_id->Text = "";
			this->pass->Text = "";
		}
	}
}
*/