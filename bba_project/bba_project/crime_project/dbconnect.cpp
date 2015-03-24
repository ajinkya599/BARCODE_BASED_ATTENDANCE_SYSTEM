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
		if(con->State==ConnectionState::Closed)
			con->Open();
		//MessageBox::Show("Connected!");
	}
	catch(Exception^ e)
	{
		MessageBox::Show("Couldn't Connect!" + e->ToString());// if connection fails
	}
}

//Search takes query and field, what to search and where to search.
//Returns dataset of search results.
//Resistant to SQL injection attacks.
String^ dbconnect::total(String^ sub)
{
	MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `Total` FROM bba."+sub+" WHERE `Roll` = '1'", con);//accessing the cell value which contains the roll number .
	DataSet^ ds = gcnew DataSet();
	da->Fill(ds);
	//reading internal XML to get the cell value
	System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
	reader->LoadXml(ds->GetXml());
	System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);
	return val->InnerText;
}
DataSet^ dbconnect::sub(String^ sub)
{
	auto da = gcnew MySqlDataAdapter("Select `Roll`, `2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total` from bba."+sub+" ", con);
	auto ds = gcnew DataSet;
	da->Fill(ds, "std");
	return ds;
}
String^ dbconnect::studtotal(String^ sub, String^ uname)
{
	try{

		MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `Roll` FROM bba.login WHERE `User Id` = \'" + uname + "\'", con);//accessing the cell value which contains the roll number .
		DataSet^ ds = gcnew DataSet();
		da->Fill(ds);
		//reading internal XML to get the cell value
		System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
		reader->LoadXml(ds->GetXml());
		System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);
		MySqlDataAdapter^ daa = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + sub + " WHERE `Roll` = \'" + val->InnerText + "\'", con);//accessing the cell value which contains total for that value and subject
		DataSet^ dss = gcnew DataSet();
		daa->Fill(dss);
		//reading internal XML to get the cell value
		System::Xml::XmlDocument^ readers = gcnew System::Xml::XmlDocument();
		readers->LoadXml(dss->GetXml());
		System::Xml::XmlNode^ vals = readers->GetElementsByTagName("Table")->Item(0);
		return vals->InnerText;
	}
	
	catch (Exception^ e)
	{
		MessageBox::Show("Sorry you are not registered for this course. Click OK to view the total attendance");

	}
	
}
String^ dbconnect::roll(String^ uname)// to return roll number whenever required by user
{
	MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `Roll` FROM bba.login WHERE `User Id` = \'" + uname + "\'", con);//accessing the cell value which contains the roll number .
	DataSet^ ds = gcnew DataSet();
	da->Fill(ds);
	//reading internal XML to get the cell value
	System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
	reader->LoadXml(ds->GetXml());
	System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);
	return val->InnerText;
}
DataSet^ dbconnect::searchstudrecord(String^ sub, String^uname)// to show the student his attendance in particular subject
{
	MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `Roll` FROM bba.login WHERE `User Id` = \'" + uname + "\'", con);//accessing the cell value which contains the roll number .
	DataSet^ ds = gcnew DataSet();
	da->Fill(ds);
	//reading internal XML to get the cell value
	System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
	reader->LoadXml(ds->GetXml());
	System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);
	auto daa = gcnew MySqlDataAdapter("Select `2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total` from bba." + sub + " Where `Roll` = \'" + val->InnerText + "\' or `Roll` = '1'", con);
	auto dss = gcnew DataSet;
	daa->Fill(dss, "std");
	return dss;//dss contains the complete table here
	
}
DataSet^ dbconnect::search(String^ query,String^ field)
{
	//Declarations
	MySqlDataAdapter^ da;
	auto ds=gcnew DataSet;
	
	//Check for valid query 
	if(query->IndexOf('\'')!=-1) {MessageBox::Show("Invalid Query");da=gcnew MySqlDataAdapter("Select * from crimetable where 1=0",con);da->Fill(ds,"std");return ds;}
	
	//There might be problems with sql query, use try
	try{
		//Users are in different table
		//Hence use condition
		if(field!="Users")
			da=gcnew MySqlDataAdapter("Select * from crimetable where "+field+" like \'%"+query+"%\'",con);
		else
			da=gcnew MySqlDataAdapter("Select `Station ID`,`User ID`,`User Type` from usertable where `User ID` like \'%"+query+"%\'",con);
	
		//fill retrieved results into dataset. 
		da->Fill(ds,"std");
	}
	catch(Exception^ e)
	{
		MessageBox::Show("Invalid Query");
	}
	//Return the built dataset.
	return ds;
}

//viewall()-> View All Records.
//Returns dataset.
DataSet^ dbconnect::viewall()
{
	auto da = gcnew MySqlDataAdapter("Select `Roll`, `User Id`,`User Type` from bba.login ", con);
	auto ds = gcnew DataSet;
	da->Fill(ds, "std");
	return ds;
}

// a=subject b=date
Void dbconnect::give_all(String^a, String^b)
{
	int i = 1;

	while (1){
		try{
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `serial` = \'" + i + "\'", con);//accessing the cell value.
			DataSet^ ds = gcnew DataSet();
			da->Fill(ds);
			//reading internal XML to get the cell value
			System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
			reader->LoadXml(ds->GetXml());
			System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);

			if (System::Convert::ToInt32(val->InnerText) == 0)
			{

				String^ query = "UPDATE bba." + a + " SET `" + b + "`=\'1\' WHERE `serial`=\'" + i + "\'";
			//	String^ query = "UPDATE bba." + val->InnerText + " SET `" + c + "`=\'1\' WHERE `Roll`=\'" + a + "\'";// Updating attendance in respective course table and also updating total no of classes by updating pseudo user

				MySqlDataAdapter^ totalda = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + a + " WHERE `serial` =\'" + i + "\'", con);
				DataSet^ totalds = gcnew DataSet();
				totalda->Fill(totalds);
				System::Xml::XmlDocument^ totalreader = gcnew System::Xml::XmlDocument();
				totalreader->LoadXml(totalds->GetXml());
				System::Xml::XmlNode^ totalval = totalreader->GetElementsByTagName("Table")->Item(0);
				String^ s = totalval->InnerText;

				int d = System::Convert::ToInt32(s);
				int e = d + 1;
				String^ query1 = "UPDATE bba." + a + " SET `Total`=\'" + e + "\' WHERE `serial`=\'" + i + "\'";// Updating total


				MySqlDataAdapter^ currentda = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `serial` =\'" + i + "\'", con);
				DataSet^ currentds = gcnew DataSet();
				currentda->Fill(currentds);
				System::Xml::XmlDocument^ currentreader = gcnew System::Xml::XmlDocument();
				currentreader->LoadXml(currentds->GetXml());
				System::Xml::XmlNode^ currentval = currentreader->GetElementsByTagName("Table")->Item(0);
				String^ s1 = currentval->InnerText;

				int current_atd = System::Convert::ToInt32(s1);


				MySqlDataAdapter^ pseudo_da = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `Roll` ='1'", con);
				DataSet^ pseudo_ds = gcnew DataSet();
				pseudo_da->Fill(pseudo_ds);
				System::Xml::XmlDocument^ pseudo_reader = gcnew System::Xml::XmlDocument();
				pseudo_reader->LoadXml(pseudo_ds->GetXml());
				System::Xml::XmlNode^ pseudo_val = pseudo_reader->GetElementsByTagName("Table")->Item(0);
				String^ pseudo_s = pseudo_val->InnerText;

				int pseudo_atd = System::Convert::ToInt32(pseudo_s);

				String^ update_pseudo = "UPDATE bba." + a + " SET `" + b + "`=\'1\' WHERE `Roll`='1'";//updating pseudo user 

				MySqlDataAdapter^ pseudot_da = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + a + " WHERE `Roll` ='1'", con);
				DataSet^ pseudot_ds = gcnew DataSet();
				pseudot_da->Fill(pseudot_ds);
				System::Xml::XmlDocument^ pseudot_reader = gcnew System::Xml::XmlDocument();
				pseudot_reader->LoadXml(pseudot_ds->GetXml());
				System::Xml::XmlNode^ pseudot_val = pseudot_reader->GetElementsByTagName("Table")->Item(0);
				String^ pseudot_s = pseudot_val->InnerText;

				int pseudo_total = System::Convert::ToInt32(pseudot_s);
				pseudo_total = pseudo_total + 1;
				String^ update_pseudo_total = "UPDATE bba." + a + " SET `Total`=\'" + pseudo_total + "\' WHERE `Roll`='1'";//updating total attendance of pseudo user

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
			}

			i++;
		}

		catch (Exception^ e)
		{
			if (i>1)
			MessageBox::Show("Request Processed\n");

			else
				MessageBox::Show("Invalid Request\n");
			return;
		}

	}
	
}


Void dbconnect::give_none(String^a, String^b)
{
	int i = 1;

	while (1){
		try{
			MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `serial` = \'" + i + "\'", con);//accessing the cell value.
			DataSet^ ds = gcnew DataSet();
			da->Fill(ds);
			//reading internal XML to get the cell value
			System::Xml::XmlDocument^ reader = gcnew System::Xml::XmlDocument();
			reader->LoadXml(ds->GetXml());
			System::Xml::XmlNode^ val = reader->GetElementsByTagName("Table")->Item(0);

			if (System::Convert::ToInt32(val->InnerText) == 1)
			{

				String^ query = "UPDATE bba." + a + " SET `" + b + "`=\'0\' WHERE `serial`=\'" + i + "\'";
				//	String^ query = "UPDATE bba." + val->InnerText + " SET `" + c + "`=\'1\' WHERE `Roll`=\'" + a + "\'";// Updating attendance in respective course table and also updating total no of classes by updating pseudo user

				MySqlDataAdapter^ totalda = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + a + " WHERE `serial` =\'" + i + "\'", con);
				DataSet^ totalds = gcnew DataSet();
				totalda->Fill(totalds);
				System::Xml::XmlDocument^ totalreader = gcnew System::Xml::XmlDocument();
				totalreader->LoadXml(totalds->GetXml());
				System::Xml::XmlNode^ totalval = totalreader->GetElementsByTagName("Table")->Item(0);
				String^ s = totalval->InnerText;

				int d = System::Convert::ToInt32(s);
				int e = d - 1;
				String^ query1 = "UPDATE bba." + a + " SET `Total`=\'" + e + "\' WHERE `serial`=\'" + i + "\'";// Updating total


				MySqlDataAdapter^ currentda = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `serial` =\'" + i + "\'", con);
				DataSet^ currentds = gcnew DataSet();
				currentda->Fill(currentds);
				System::Xml::XmlDocument^ currentreader = gcnew System::Xml::XmlDocument();
				currentreader->LoadXml(currentds->GetXml());
				System::Xml::XmlNode^ currentval = currentreader->GetElementsByTagName("Table")->Item(0);
				String^ s1 = currentval->InnerText;

				int current_atd = System::Convert::ToInt32(s1);


				MySqlDataAdapter^ pseudo_da = gcnew MySqlDataAdapter("SELECT `" + b + "` FROM bba." + a + " WHERE `Roll` ='1'", con);
				DataSet^ pseudo_ds = gcnew DataSet();
				pseudo_da->Fill(pseudo_ds);
				System::Xml::XmlDocument^ pseudo_reader = gcnew System::Xml::XmlDocument();
				pseudo_reader->LoadXml(pseudo_ds->GetXml());
				System::Xml::XmlNode^ pseudo_val = pseudo_reader->GetElementsByTagName("Table")->Item(0);
				String^ pseudo_s = pseudo_val->InnerText;

				int pseudo_atd = System::Convert::ToInt32(pseudo_s);

				String^ update_pseudo = "UPDATE bba." + a + " SET `" + b + "`=\'0\' WHERE `Roll`='1'";//updating pseudo user 

				MySqlDataAdapter^ pseudot_da = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + a + " WHERE `Roll` ='1'", con);
				DataSet^ pseudot_ds = gcnew DataSet();
				pseudot_da->Fill(pseudot_ds);
				System::Xml::XmlDocument^ pseudot_reader = gcnew System::Xml::XmlDocument();
				pseudot_reader->LoadXml(pseudot_ds->GetXml());
				System::Xml::XmlNode^ pseudot_val = pseudot_reader->GetElementsByTagName("Table")->Item(0);
				String^ pseudot_s = pseudot_val->InnerText;

				int pseudo_total = System::Convert::ToInt32(pseudot_s);
				pseudo_total = pseudo_total - 1;
				String^ update_pseudo_total = "UPDATE bba." + a + " SET `Total`=\'" + pseudo_total + "\' WHERE `Roll`='1'";//updating total attendance of pseudo user

				MySqlCommand^ cmd = gcnew MySqlCommand;
				cmd->Connection = con;
				cmd->CommandText = query;
				cmd->ExecuteNonQuery();


				MySqlCommand^ cmd1 = gcnew MySqlCommand;
				cmd1->Connection = con;
				cmd1->CommandText = query1;
				if (current_atd == 1)					//decrement total attendance of the student only if this attendance was registered before.
					cmd1->ExecuteNonQuery();


				MySqlCommand^ cmd2 = gcnew MySqlCommand;
				cmd2->Connection = con;
				cmd2->CommandText = update_pseudo;
				cmd2->ExecuteNonQuery();

				MySqlCommand^ cmd3 = gcnew MySqlCommand;
				cmd3->Connection = con;
				cmd3->CommandText = update_pseudo_total;
				if (pseudo_atd == 1)					//decrement total attendance of the pseudo only if this attendance was registered before.
					cmd3->ExecuteNonQuery();
			}

			i++;
		}

		catch (Exception^ e)
		{
			if (i>1)
				MessageBox::Show("Request Processed\n");

			else
				MessageBox::Show("Invalid Request\n");
			return;
		}

	}

}


// a=roll  b=time c=date
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

		String^ update_pseudo = "UPDATE bba." + val->InnerText + " SET `" + c + "`=\'1\' WHERE `Roll`='1'";//updating pseudo user attendance

		MySqlDataAdapter^ pseudot_da = gcnew MySqlDataAdapter("SELECT `Total` FROM bba." + val->InnerText + " WHERE `Roll` ='1'", con);
		DataSet^ pseudot_ds = gcnew DataSet();
		pseudot_da->Fill(pseudot_ds);
		System::Xml::XmlDocument^ pseudot_reader = gcnew System::Xml::XmlDocument();
		pseudot_reader->LoadXml(pseudot_ds->GetXml());
		System::Xml::XmlNode^ pseudot_val = pseudot_reader->GetElementsByTagName("Table")->Item(0);
		String^ pseudot_s = pseudot_val->InnerText;

		int pseudo_total = System::Convert::ToInt32(pseudot_s);
		pseudo_total = pseudo_total + 1;
		String^ update_pseudo_total = "UPDATE bba." + val->InnerText + " SET `Total`=\'" + pseudo_total + "\' WHERE `Roll`='1'";//updating total attendance of pseudo user

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
//View all Users.
//Returns dataset.
DataSet^ dbconnect::viewalluser()
{
	auto da=gcnew MySqlDataAdapter("Select `Roll`, `User Id`,`User Type` from bba.login ",con);
	auto ds=gcnew DataSet;
	da->Fill(ds,"std");
	return ds;
}

//Add Records.
//Takes the fields as input.
//Runs SQL query using ExecuteNonQuery.
void dbconnect::update(String^ date,String^roll)
{
	String^ query = "UPDATE bba.2_2 SET `2/17/2015`=\'" +date+ "\' WHERE `Roll`=\'" +roll+ "\'";
	//String^ query = "INSERT INTO bba.2_5 (`Roll`, `2/14/2015`) VALUES ( \'" +roll+ "\', \'" +date+ "\')";
	MySqlCommand^ cmd = gcnew MySqlCommand;
	cmd->Connection = con;
	cmd->CommandText = query;
	cmd->ExecuteNonQuery();
	//MessageBox::Show(query);
	/*try{
		cmd->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Unable to take attendance.Try Again\n");
		e->ToString();
		return;
	} */ //Left to Handle Exception If roll number doesnot exist.
	MessageBox::Show("Attendance successfully recorded\n");
}
void dbconnect::add(String^ cat, String^ date,String^ time, String^ loc, String^ des,String^ evi,String^ susp)
{
	String^ query="INSERT INTO crimetable (`Category`, `Date`, `Time`, `Location`, `Description`, `Evidence`, `Suspects`) VALUES ( \'"+cat+"\', \'"+date+"\', \'"+time+"\', \'"+loc+"\', \'"+des+"\', \'"+evi+"\', \'"+susp+"\')";
	MySqlCommand^ cmd = gcnew MySqlCommand;
	cmd->Connection = con;
    cmd->CommandText = query;
	//MessageBox::Show(query);
	cmd->ExecuteNonQuery();
}

//Add Records.
//Takes the fields as input.
//Runs SQL query using ExecuteNonQuery.
//new
void dbconnect::add_user(String^ utype, String^ userid, String^ pass, String^ roll, String^algo, String^coa, String^flat, String^soft, String^data)
{
	String^ query;
	String^ query1;
	//MessageBox::Show("INSERT INTO bba.login (`User Type`, `User ID`, `Password`) VALUES (\'"+utype+"\', \'"+stationid+"\', \'"+userid+"\', aes_encrypt\(\'"+pass+"\',\'crime\'\))");
	if (utype == "Student")
	{

		query = "INSERT INTO bba.login (`User Type`, `User Id`, `Password`, `Roll`) VALUES (\'" + utype + "\',  \'" + userid + "\', \'" + pass + "\',\'" + roll + "\')";


		if (algo != "null")
		{
			query1 = "INSERT INTO bba.2_1(`Roll`,`2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total`) VALUES(\'" + roll + "\','0','0','0','0','0','0','0','0')";
			MySqlCommand^cmd = gcnew MySqlCommand;
			cmd->Connection = con;
			cmd->CommandText = query1;

			//Try to Add User.
			//If the User Already Exists, Show Error
			try{
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Unable to add User\n");
				e->ToString();
				return;
			}
		}

		if (coa != "null")
		{
			query1 = "INSERT INTO bba.2_2(`Roll`,`2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total`) VALUES(\'" + roll + "\','0','0','0','0','0','0','0','0')";
			MySqlCommand^cmd = gcnew MySqlCommand;
			cmd->Connection = con;
			cmd->CommandText = query1;

			//Try to Add User.
			//If the User Already Exists, Show Error
			try{
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Unable to add User\n");
				e->ToString();
				return;
			}
		}

		if (flat != "null")
		{
			query1 = "INSERT INTO bba.2_3(`Roll`,`2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total`) VALUES(\'" + roll + "\','0','0','0','0','0','0','0','0')";
			MySqlCommand^cmd = gcnew MySqlCommand;
			cmd->Connection = con;
			cmd->CommandText = query1;

			//Try to Add User.
			//If the User Already Exists, Show Error
			try{
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Unable to add User\n");
				e->ToString();
				return;
			}
		}

		if (soft != "null")
		{
			query1 = "INSERT INTO bba.2_4(`Roll`,`2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total`) VALUES(\'" + roll + "\','0','0','0','0','0','0','0','0')";
			MySqlCommand^cmd = gcnew MySqlCommand;
			cmd->Connection = con;
			cmd->CommandText = query1;

			//Try to Add User.
			//If the User Already Exists, Show Error
			try{
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Unable to add User\n");
				e->ToString();
				return;
			}
		}

		if (data != "null")
		{
			query1 = "INSERT INTO bba.2_5(`Roll`,`2/14/2015`,`2/15/2015`,`2/16/2015`,`2/17/2015`,`2/18/2015`,`2/19/2015`,`2/20/2015`,`Total`) VALUES(\'" + roll + "\','0','0','0','0','0','0','0','0')";
			MySqlCommand^cmd = gcnew MySqlCommand;
			cmd->Connection = con;
			cmd->CommandText = query1;

			//Try to Add User.
			//If the User Already Exists, Show Error
			try{
				cmd->ExecuteNonQuery();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Unable to add User\n");
				e->ToString();
				return;
			}
		}
	}
	if (utype != "Student")
	{
		query = "INSERT INTO bba.login (`User Type`, `User Id`, `Password`, `Roll`) VALUES (\'" + utype + "\',  \'" + userid + "\', \'" + pass + "\',\'" + roll + "\')";
	}

	//Make Query/
	MySqlCommand^cmd = gcnew MySqlCommand;
	cmd->Connection = con;
	cmd->CommandText = query;

	//Try to Add User.
	//If the User Already Exists, Show Error
	try{
		cmd->ExecuteNonQuery();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Unable to add User\n");
		e->ToString();
		return;
	}
	MessageBox::Show("User Added Successfully into the database.", "Admin", MessageBoxButtons::OK);
}
//Add Records.
//Takes the fields as input.
//Runs SQL query using ExecuteNonQuery.
void dbconnect::del_user(String^ user_id,String^ utype,String^ roll)
{
	String^ query = "DELETE FROM bba.login WHERE `Roll`=\'" + roll + "\' AND `User Type`=\'" + utype + "\';DELETE FROM bba.2_1 WHERE `Roll`=\'" + roll + "\';DELETE FROM bba.2_2 WHERE `Roll`=\'" + roll + "\';DELETE FROM bba.2_3 WHERE `Roll`=\'" + roll + "\';DELETE FROM bba.2_4 WHERE `Roll`=\'" + roll + "\';DELETE FROM bba.2_5 WHERE `Roll`=\'" + roll + "\'";

	MySqlCommand^ cmd = gcnew MySqlCommand;
	//MessageBox::Show(query);
	cmd->Connection = con;
    cmd->CommandText = query;
	
	//If the user does not exist, show error.
	if(cmd->ExecuteNonQuery()) MessageBox::Show("User Deleted Successfully from the database.","Admin", MessageBoxButtons::OK);
	else MessageBox::Show("Error Deleting Specified User.");
}

//Verify whether correct User Login received.
//Uses SQL Result>0 for verification
//Returns boolean to indicate success.
bool dbconnect::verify_user(String^ utype, String^ userid, String^ password)
{
	if(userid->IndexOf('\'')!=-1 || password->IndexOf('\'')!=-1) {MessageBox::Show("Invalid Query");return 0;}
	String^ query="SELECT * FROM bba.login WHERE `User Type`=\'"+utype+"\' AND `User ID`=\'"+userid+"\'" ;
	MySqlCommand^ cmd = gcnew MySqlCommand;
	cmd->Connection = con;
    cmd->CommandText = query;
	//MessageBox::Show(query);
	if(cmd->ExecuteNonQuery()) return 1;
	else return 0;
}