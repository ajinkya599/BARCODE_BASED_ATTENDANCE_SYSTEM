#include "attendance.h"
#include "take_attd.h"
#include "examples.h"
#include <msclr\marshal_cppstd.h>
#include <String>
#include "StdAfx.h"
#include "dbconnect.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::Xml;
using namespace examples;

std::string s2;

[STAThread]
void attendance::man_attd_Click(System::Object^  sender, System::EventArgs^  e)
{
	take_attd^ f = gcnew take_attd();
	f->ShowDialog();
}

Void attendance::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	// button9->Visible = true;
	OpenFileDialog ^ o = gcnew OpenFileDialog();													//code for Open button
	o->Filter = "Cursor Files|*.bmp";										//Code for file filter
	o->Title = "Select an Image File";
	o->Multiselect = true;
	
	// Show the Dialog.
	// If the user clicked OK in the dialog and
	// a .CUR file was selected, open it.
	if (o->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Assign the cursor in the Stream to
		// the Form's Cursor property.
		// axWindowsMediaPlayer1->URL = openFileDialog1->FileName;
		// char* blaptr = &(o->FileName[0]);

		msclr::interop::marshal_context context;
		std::string s = context.marshal_as<std::string>(o->FileName);

		//std::string s1 = example_reader_code128(s);
		//String^ MyString = gcnew String(s1.c_str());
		s2 = example_reader_code128(s);
		//String^ MyString = gcnew String(s2.c_str());
		// MessageBox::Show(MyString);
		//String^ a = this->roll->Text;
		//String^b = this->time->Text;
		//String^c = this->date->Text;
		//dbconnect db;
		//db.course(MyString, b, c);
		//MessageBox::Show("something");
	}
	// else
	//	 button9->Visible = false;
	//if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	//button9->Visible = false;

}

Void attendance::store_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ MyString = gcnew String(s2.c_str());
	String^b = this->time->Text;
	String^c = this->date->Text;
	dbconnect db;
	db.course(MyString, b, c);
}