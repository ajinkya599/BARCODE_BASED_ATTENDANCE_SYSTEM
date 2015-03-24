#include "StdAfx.h"

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