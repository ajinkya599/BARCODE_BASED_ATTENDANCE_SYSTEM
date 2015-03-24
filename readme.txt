I-The project is distributed in two parts:
	1) Barcode : which is used to read the barcode of Id card
	2) bba_project : Login and management

II-DEPENDANCIES :
	The Software requires MySql to be installed on the system for database management.
	The required tables need to be created in the database.

III-To start the software follow the following steps: 

	1) TAKING ATTENDANCE :
   	   Open the file by following the given path :  Group-No-4-1.7/Barcode/Debug/examples
	   Make sure that you open the application file.
	   For further guidelines on how to use read the user manual provided.

	2) LOGIN AND VIEW :
	   Open the file by following the given path :  Group-No-4-1.7/bba_project/bba_project/Release/bba_project
	   Make sure that you open the application file.
	   For further guidelines on how to use read the user manual provided.

IV-SETTING UP DATABASE :

	1) Create a database/schema with the name "bba"
	2) Import the database from the sql script "database.sql" which creates the database on your pc as required by the program.
	3) For using this software with database use the database settings as follows:

	server=localhost
	port=3307
	username=root
	password=password

V-OTHER IMPORTANT GUIDELINES :

	1) Wherever asked the date should be entered in the following format : mm/dd/yyyy 
	 
	   In case of single digit don't use 0 before it 
		eg.  correct way 2/16/2015
		     incorrect way 02/16/2015

	2) For testing :
			the DATE used should be in the range 2/14/2015 to 2/20/2015
			the TIME used should be entered in hours only and in the range 9 to 11

	3) The test logins that can be used are :

		STUDENT   Username : piyush
			  Password : piyush

		PROFESSOR Username : ajinkya
			  Password : ajinkya

		ADMIN     Username : nikit
			  Password : nikit