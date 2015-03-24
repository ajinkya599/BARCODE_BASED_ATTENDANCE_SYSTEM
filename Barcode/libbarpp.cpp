// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#include <Windows.h>
#include "BarBitmapWin32.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{	 
   switch (fdwReason) {
      case DLL_PROCESS_ATTACH:
		  CBarBitmapWin32::hinstDLL = (HINSTANCE)hinstDLL;
   }
   return TRUE;
}
