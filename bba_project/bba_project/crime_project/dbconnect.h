#pragma once
#include "stdafx.h"
ref class dbconnect
{
public:
	MySqlConnection ^con;
	dbconnect(void);
	DataSet^ search(String^, String^);
	DataSet^ sub(String^);
	DataSet^ viewall();
	String^ roll(String^uname);
	String^ total(String^ sub);
	String^ studtotal(String^ sub, String^ uname);
	DataSet^ searchstudrecord(String^, String^);
	void update(String^ date, String^roll);
	void add(String^ cat, String^ date,String^ time, String^ loc, String^ des,String^ evi,String^ susp);
	void add_user(String^ utype, String^ userid, String^ pass, String^ roll, String^algo, String^coa, String^flat, String^soft, String^data);
	void del_user(String^ user_id, String^ utype, String^ roll);
	bool verify_user(String^ utype, String^ userid, String^ password);
	DataSet^ viewalluser();
	void course(String^a, String^b, String^c);
	void give_all(String^a, String^b);
	void give_none(String^a, String^b);
	
};

