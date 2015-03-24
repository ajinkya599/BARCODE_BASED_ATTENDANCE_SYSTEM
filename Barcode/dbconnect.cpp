#include "StdAfx.h"
#include "dbconnect.h"
#include "stdlib.h"
#include "String"


/*	This file is base for all database connections and methods.
Constructor establishes the connection to databse server.
*/
using namespace std;
dbconnect::dbconnect(void)
{
	con = gcnew MySqlConnection("");
	try
	{
		con->ConnectionString = "server=localhost;port=3307;username=root;password=password";
		if (con->State == ConnectionState::Closed)
			con->Open();
		//MessageBox::Show("Connected!");
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Couldn't Connect!" + e->ToString());// if connection fails
	}
}
//->InnerText;

Void dbconnect::course(String^a, String^b, String^c)//for getting the course name from date and time when the barcode was scanned.
{

	try{
		MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba.csett WHERE `Date` = \'" + c + "\'", con);//accessing the cell value which contains the subject name .
		DataSet^ ds = gcnew DataSet();
		da->Fill(ds);

		//reading internal XML to get the cell value
		System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
		reader->LoadXml(ds->GetXml());
		System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);

		//MessageBox::Show(val->InnerText); //for debugging
		String^ query = "UPDATE bba." + val->InnerText + " SET `" + c + "`=\'1\' WHERE `Roll`=\'" + a + "\'";// Updating attendance in respective course table and also updating total no of classes by updating pseudo user

		MySqlDataAdapter^ totalda = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + val->InnerText + " WHERE `Roll` =\'" + a + "\'", con);
		DataSet^ totalds = gcnew DataSet();
		totalda->Fill(totalds);
		System::Xml::XmlDocument^ totalreader = gcnew System::Xml::XmlDocument();
		totalreader->LoadXml(totalds->GetXml());
		System::Xml::XmlNode^ totalval = totalreader->GetElementsByTagName("Table")->Item(0);
		String^ s = totalval->InnerText;

		int d = System::Convert::ToInt32(s);
		int e = d + 1;
		String^ query1 = "UPDATE bba." + val->InnerText + " SET `Total`=\'" + e + "\' WHERE `Roll`=\'" + a + "\'";// Updating total


		MySqlDataAdapter^ currentda = gcnew MySqlDataAdapter("SELECT `" + c + "` FROM bba." + val->InnerText + " WHERE `Roll` =\'" + a + "\'", con);
		DataSet^ currentds = gcnew DataSet();
		currentda->Fill(currentds);
		System::Xml::XmlDocument^ currentreader = gcnew System::Xml::XmlDocument();
		currentreader->LoadXml(currentds->GetXml());
		System::Xml::XmlNode^ currentval = currentreader->GetElementsByTagName("Table")->Item(0);
		String^ s1 = currentval->InnerText;

		int current_atd = System::Convert::ToInt32(s1);


		MySqlDataAdapter^ pseudo_da = gcnew MySqlDataAdapter("SELECT `" + c + "` FROM bba." + val->InnerText + " WHERE `Roll` ='1'", con);
		DataSet^ pseudo_ds = gcnew DataSet();
		pseudo_da->Fill(pseudo_ds);
		System::Xml::XmlDocument^ pseudo_reader = gcnew System::Xml::XmlDocument();
		pseudo_reader->LoadXml(pseudo_ds->GetXml());
		System::Xml::XmlNode^ pseudo_val = pseudo_reader->GetElementsByTagName("Table")->Item(0);
		String^ pseudo_s = pseudo_val->InnerText;

		int pseudo_atd = System::Convert::ToInt32(pseudo_s);

		String^ update_pseudo = "UPDATE bba." + val->InnerText + " SET `" + c + "`=\'1\' WHERE `Roll`='1'";

		MySqlDataAdapter^ pseudot_da = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + val->InnerText + " WHERE `Roll` ='1'", con);
		DataSet^ pseudot_ds = gcnew DataSet();
		pseudot_da->Fill(pseudot_ds);
		System::Xml::XmlDocument^ pseudot_reader = gcnew System::Xml::XmlDocument();
		pseudot_reader->LoadXml(pseudot_ds->GetXml());
		System::Xml::XmlNode^ pseudot_val = pseudot_reader->GetElementsByTagName("Table")->Item(0);
		String^ pseudot_s = pseudot_val->InnerText;

		int pseudo_total = System::Convert::ToInt32(pseudot_s);
		pseudo_total = pseudo_total + 1;
		String^ update_pseudo_total = "UPDATE bba." + val->InnerText + " SET `Total`=\'" + pseudo_total + "\' WHERE `Roll`='1'";

		MySqlCommand^ cmd = gcnew MySqlCommand;
		cmd->Connection = con;
		cmd->CommandText = query;
		cmd->ExecuteNonQuery();


		MySqlCommand^ cmd1 = gcnew MySqlCommand;
		cmd1->Connection = con;
		cmd1->CommandText = query1;
		if (current_atd == 0)					//increment total attendance of the student only if this attendance was not registered before.
			cmd1->ExecuteNonQuery();


		MySqlCommand^ cmd2 = gcnew MySqlCommand;
		cmd2->Connection = con;
		cmd2->CommandText = update_pseudo;
		cmd2->ExecuteNonQuery();

		MySqlCommand^ cmd3 = gcnew MySqlCommand;
		cmd3->Connection = con;
		cmd3->CommandText = update_pseudo_total;
		if (pseudo_atd == 0)
			cmd3->ExecuteNonQuery();
		MessageBox::Show("Your Attendance has been recorded");

	}

	catch (Exception^ e)
	{
		MessageBox::Show("Invalid Query");
	}


}


