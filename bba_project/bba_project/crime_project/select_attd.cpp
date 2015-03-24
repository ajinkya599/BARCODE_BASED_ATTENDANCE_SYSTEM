#include "StdAfx.h"
#include "Form_attd.h"
#include "select_attd.h"

#pragma once
using namespace bba_project;




Void select_attd::sel_manual_Click(System::Object^  sender, System::EventArgs^  e) {

	MyForm^ Form_attd = gcnew MyForm();
	Form_attd->ShowDialog();
}