// bba_project.cpp : main project file.
#include "stdafx.h"
#include "login.h"

using namespace bba_project;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew login());
	return 0;
}
