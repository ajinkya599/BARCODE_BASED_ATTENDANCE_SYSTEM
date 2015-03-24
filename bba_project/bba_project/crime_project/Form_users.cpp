#include "StdAfx.h"

#include "Form1.h"
#include "Form_viewall.h"
#include "Form_admin.h"
#include "Form_users.h"
#include "dbconnect.h"

using namespace bba_project;
Void Form_users::Form_users_Load(System::Object^  sender, System::EventArgs^  e){

}
System::Void Form_users::dataGridView_users_VisibleChanged(System::Object^  sender, System::EventArgs^  e)
{
	//display the datagrid view from the database.
	dbconnect db;
	dataGridView_users->DataSource = db.viewalluser();
	dataGridView_users->DataMember = "std";
	dataGridView_users->Refresh();
}

Void Form_users::button_adback_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	this->Close();	//close Form_users
	Form_admin^ f1 = gcnew Form_admin();
	f1->ShowDialog();							//show login form
}

Void Form_users::button_adusradd_Click(System::Object^  sender, System::EventArgs^  e) {
	//clear fields
	user__id->Text = "";
	comboBox_utype->Text = "";
	textBox_password->Text = "";
	textBox_repassword->Text = "";

	//enable-disable various buttons/groupboxes
	button_adusradd->Enabled = false;
	button_adusrdel->Enabled = false;
	groupBox_allusers->Visible = false;
	groupBox_adduser->Visible = true;
}

Void Form_users::button_canceladd_Click(System::Object^  sender, System::EventArgs^  e) {
	//clear fields

	user__id->Text = "";
	comboBox_utype->Text = "";
	textBox_password->Text = "";
	textBox_repassword->Text = "";

	button_adusradd->Enabled = true;
	button_adusrdel->Enabled = true;
	groupBox_allusers->Visible = true;
	groupBox_adduser->Visible = false;
	groupBox_deleteuser->Visible = false;
}


Void Form_users::button_usraddfinal_Click(System::Object^  sender, System::EventArgs^  e) {
	//new

	if ((comboBox_utype->Text == "Student" && (check_algo->Checked == true || check_coa->Checked == true || check_data->Checked == true || check_flat->Checked == true || check_soft->Checked == true)) || (comboBox_utype->Text == "Professor") || (comboBox_utype->Text == "Admin"))
	{
		if (user__id->Text != "" && comboBox_utype->Text != "" && textBox_password->Text != "" && textBox_password->Text == textBox_repassword->Text)
		{
			if (comboBox_utype->Text != "Student")
			{

				dbconnect db;
				db.add_user(comboBox_utype->Text, user__id->Text, textBox_password->Text, roll_add->Text, "null", "null", "null", "null", "null");
				//clear fields

				user__id->Text = "";
				comboBox_utype->Text = "";
				textBox_password->Text = "";
				textBox_repassword->Text = "";
				roll_add->Text = "";
				//enable-disable various buttons/groupboxes
				button_adusradd->Enabled = true;
				button_adusrdel->Enabled = true;
				groupBox_allusers->Visible = true;
				groupBox_adduser->Visible = false;
				groupBox_deleteuser->Visible = false;
			}
			if (comboBox_utype->Text == "Student")
			{
				dbconnect db;
				String^ algo = "null";
				String^ data = "null";
				String^ coa = "null";
				String^ flat = "null";
				String^ soft = "null";
				if (check_algo->Checked == true)
					algo = "2_1";
				if (check_coa->Checked == true)
					coa = "2_2";
				if (check_flat->Checked == true)
					flat = "2_3";
				if (check_soft->Checked == true)
					soft = "2_4";
				if (check_data->Checked == true)
					data = "2_5";



				db.add_user(comboBox_utype->Text, user__id->Text, textBox_password->Text, roll_add->Text, algo, coa, flat, soft, data);
				//clear fields

				user__id->Text = "";
				comboBox_utype->Text = "";
				textBox_password->Text = "";
				textBox_repassword->Text = "";
				roll_add->Text = "";
				//enable-disable various buttons/groupboxes
				button_adusradd->Enabled = true;
				button_adusrdel->Enabled = true;
				groupBox_allusers->Visible = true;
				groupBox_adduser->Visible = false;
				groupBox_deleteuser->Visible = false;
			}
		}
		else if (textBox_password->Text != textBox_repassword->Text){
			MessageBox::Show("Passwords don't match. Please Re-enter the password", "Admin", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else{
			MessageBox::Show("Fields Not filled correctly. Please Re-enter", "Admin", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	//new
	else{
		MessageBox::Show("Please select atleast one subject", "Admin", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}

//to delete a user from the database.
Void Form_users::button_adusrdel_Click(System::Object^  sender, System::EventArgs^  e) {
	//clear fields 

	comboBox1->Text = "";
	us_id->Text = "";
	//enable-disable various buttons/group
	button_adusradd->Enabled = false;
	button_adusrdel->Enabled = false;
	groupBox_allusers->Visible = false;
	groupBox_adduser->Visible = false;
	groupBox_deleteuser->Visible = true;
}

//to finally delete user from the database

//new Author :- Nikit for adding choice of subjects
Void Form_users::comboBox_utype_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox_utype->Text == "Student")
	{
		check_algo->Visible = true;
		check_coa->Visible = true;
		check_flat->Visible = true;
		check_soft->Visible = true;
		check_data->Visible = true;
	}
	if (comboBox_utype->Text != "Student")
	{
		check_algo->Visible = false;
		check_coa->Visible = false;
		check_flat->Visible = false;
		check_soft->Visible = false;
		check_data->Visible = false;
	}
}
Void Form_users::button_userdelfinal_Click(System::Object^  sender, System::EventArgs^  e) {

	if (us_id->Text != "" && comboBox1->Text != "")
	{

		dbconnect db;
		//pass the the text to del_user() functions which will find and delte the entry from the database.
		db.del_user(us_id->Text, comboBox1->Text, roll_del->Text);
		//clear fields 

		comboBox1->Text = "";
		us_id->Text = "";
		roll_del->Text = "";
		//various buttons and groupboxes are disabled and enabled.
		button_adusradd->Enabled = true;
		button_adusrdel->Enabled = true;
		groupBox_allusers->Visible = true;
		groupBox_adduser->Visible = false;
		groupBox_deleteuser->Visible = false;
	}
	else{
		MessageBox::Show("Fields Not filled correctly. Please Re-enter", "Admin", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}

Void Form_users::button_canceldel_Click(System::Object^  sender, System::EventArgs^  e) {
	//clear fields 

	comboBox1->Text = "";
	us_id->Text = "";
	roll_del->Text = "";
	//enable-disable various buttons/groupboxes
	button_adusradd->Enabled = true;
	button_adusrdel->Enabled = true;
	groupBox_allusers->Visible = true;
	groupBox_adduser->Visible = false;
	groupBox_deleteuser->Visible = false;
}

//to help user to fill fields.
Void Form_users::button_helpadd_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("Enter data in proper fields and click on Add to add entry to database. Press Cancel to abort.");

}

//to help user to fill fields.
Void Form_users::button_helpdel_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("Enter data in proper fields and click on Delete to delete entry from database. Press Cancel to abort.");

}