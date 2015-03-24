#pragma once
#include "StdAfx.h"
#include "string"
ref class dbconnect
{
public:
	MySqlConnection ^con;
	dbconnect(void);
	void course(String^a, String^b, String^c);
};

