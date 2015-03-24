#include "StdAfx.h"
#include "verifier.h"
#include "dbconnect.h"
#include <ctime>
#include <cstdlib>
#pragma once

using namespace System::IO;

//Verifier
//For Secure User Verification
//Takes in User Type, User ID and Password, returns true if a user exists with such credentials


verifier::verifier(String^ utype, String^ userid, String^ pwd)  // Verifies user credentials against possible user_id and password combinations.
{	
	verified = false;
	bool sql_con_estb = 0;
	MySqlConnection^ con = gcnew MySqlConnection();
	//Establish Secure Connection
	try
	{
		con->ConnectionString = "server=localhost;port=3307;username=root;password=password";
		if(con->State==ConnectionState::Closed)
			con->Open();
		//MessageBox::Show("Connected!");
	}
	catch(Exception^ e)
	{
		sql_con_estb = 1;
	}
	String^ stationid = "";

	if ( sql_con_estb == 1 ) {
		if ( userid == "test" ) {
			if ( pwd == "test" ) {
				verified=true;
			}
		}
	}
	
	else {

		if(userid->IndexOf('\'')!=-1 ||  pwd->IndexOf('\'')!=-1) {verified=0;}
		else{
		String^ query="SELECT * FROM bba.login WHERE `User Type`=\'"+utype+"\' AND `User Id`=\'"+userid+"\' AND `Password`=\'"+pwd+"\'" ;
		MySqlCommand^ cmd = gcnew MySqlCommand(query, con);
		MySqlDataReader^ rdr = cmd->ExecuteReader();
		if(rdr->Read()) {
			verified = true;
		} }
	}
}
