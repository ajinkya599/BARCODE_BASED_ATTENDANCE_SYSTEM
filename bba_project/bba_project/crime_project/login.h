#pragma once
namespace bba_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public: static	String^ usertype;

	private: System::Windows::Forms::Timer^  timer1;


	public:


	public:

	public: 



	public: 
	public: static	String^ username;
	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  log_in;
	protected: 

	private: System::Windows::Forms::Label^  user_name;
	private: System::Windows::Forms::TextBox^  user_id;
	protected: 


	private: System::Windows::Forms::ComboBox^  user_type_select;

	private: System::Windows::Forms::Label^  password;
	private: System::Windows::Forms::Label^  user_type;
	private: System::Windows::Forms::TextBox^  pass;
	private: System::Windows::Forms::Label^  fail_status;

	private: System::Windows::Forms::Button^  button_exit;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox_login;
	private: System::ComponentModel::IContainer^  components;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->log_in = (gcnew System::Windows::Forms::Button());
			this->user_name = (gcnew System::Windows::Forms::Label());
			this->user_id = (gcnew System::Windows::Forms::TextBox());
			this->user_type_select = (gcnew System::Windows::Forms::ComboBox());
			this->password = (gcnew System::Windows::Forms::Label());
			this->user_type = (gcnew System::Windows::Forms::Label());
			this->pass = (gcnew System::Windows::Forms::TextBox());
			this->fail_status = (gcnew System::Windows::Forms::Label());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox_login = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox_login->SuspendLayout();
			this->SuspendLayout();
			// 
			// log_in
			// 
			this->log_in->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->log_in->Location = System::Drawing::Point(20, 224);
			this->log_in->Name = L"log_in";
			this->log_in->Size = System::Drawing::Size(121, 31);
			this->log_in->TabIndex = 4;
			this->log_in->Text = L"Log In";
			this->log_in->UseVisualStyleBackColor = true;
			this->log_in->Click += gcnew System::EventHandler(this, &login::log_in_Click);
			// 
			// user_name
			// 
			this->user_name->AutoSize = true;
			this->user_name->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_name->Location = System::Drawing::Point(82, 103);
			this->user_name->Name = L"user_name";
			this->user_name->Size = System::Drawing::Size(73, 21);
			this->user_name->TabIndex = 1;
			this->user_name->Text = L"User Id :";
			// 
			// user_id
			// 
			this->user_id->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_id->Location = System::Drawing::Point(251, 100);
			this->user_id->Name = L"user_id";
			this->user_id->Size = System::Drawing::Size(121, 28);
			this->user_id->TabIndex = 2;
			// 
			// user_type_select
			// 
			this->user_type_select->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->user_type_select->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_type_select->FormattingEnabled = true;
			this->user_type_select->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Professor", L"Admin" });
			this->user_type_select->Location = System::Drawing::Point(251, 41);
			this->user_type_select->Name = L"user_type_select";
			this->user_type_select->Size = System::Drawing::Size(121, 29);
			this->user_type_select->TabIndex = 1;
			this->user_type_select->SelectedIndexChanged += gcnew System::EventHandler(this, &login::user_type_select_SelectedIndexChanged);
			// 
			// password
			// 
			this->password->AutoSize = true;
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password->Location = System::Drawing::Point(64, 162);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(91, 21);
			this->password->TabIndex = 4;
			this->password->Text = L"Password :";
			// 
			// user_type
			// 
			this->user_type->AutoSize = true;
			this->user_type->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_type->Location = System::Drawing::Point(66, 44);
			this->user_type->Name = L"user_type";
			this->user_type->Size = System::Drawing::Size(94, 21);
			this->user_type->TabIndex = 5;
			this->user_type->Text = L"User Type :";
			// 
			// pass
			// 
			this->pass->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pass->Location = System::Drawing::Point(251, 159);
			this->pass->Name = L"pass";
			this->pass->PasswordChar = '*';
			this->pass->Size = System::Drawing::Size(121, 28);
			this->pass->TabIndex = 3;
			// 
			// fail_status
			// 
			this->fail_status->AutoSize = true;
			this->fail_status->BackColor = System::Drawing::Color::Red;
			this->fail_status->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fail_status->Location = System::Drawing::Point(300, 170);
			this->fail_status->Name = L"fail_status";
			this->fail_status->Size = System::Drawing::Size(0, 21);
			this->fail_status->TabIndex = 7;
			// 
			// button_exit
			// 
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_exit->Location = System::Drawing::Point(299, 224);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(121, 31);
			this->button_exit->TabIndex = 5;
			this->button_exit->Text = L"Exit";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &login::button_exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox_login
			// 
			this->groupBox_login->Controls->Add(this->user_type);
			this->groupBox_login->Controls->Add(this->user_name);
			this->groupBox_login->Controls->Add(this->button_exit);
			this->groupBox_login->Controls->Add(this->user_id);
			this->groupBox_login->Controls->Add(this->log_in);
			this->groupBox_login->Controls->Add(this->user_type_select);
			this->groupBox_login->Controls->Add(this->pass);
			this->groupBox_login->Controls->Add(this->password);
			this->groupBox_login->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox_login->Location = System::Drawing::Point(218, 214);
			this->groupBox_login->Name = L"groupBox_login";
			this->groupBox_login->Size = System::Drawing::Size(448, 272);
			this->groupBox_login->TabIndex = 11;
			this->groupBox_login->TabStop = false;
			this->groupBox_login->Text = L"Log in";
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox_login);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->fail_status);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &login::login_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox_login->ResumeLayout(false);
			this->groupBox_login->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void login_Load(System::Object^  sender, System::EventArgs^  e) {
	user_type_select->Focus();		
	user_id->Focus();
}
private: System::Void log_in_Click(System::Object^  sender, System::EventArgs^  e);
			  

private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void softname_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void pictureBox_welcom_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void user_type_select_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
		 }




private: System::Void Attendance_Click(System::Object^  sender, System::EventArgs^  e);
};
}
