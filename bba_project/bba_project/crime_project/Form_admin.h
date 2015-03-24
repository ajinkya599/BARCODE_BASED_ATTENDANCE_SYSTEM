#pragma once

namespace bba_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_admin
	/// </summary>
	public ref class Form_admin : public System::Windows::Forms::Form
	{
	public:
		Form_admin(void)
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
		~Form_admin()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 








	private: System::Windows::Forms::Button^  button_adlogout;
	private: System::Windows::Forms::Button^  button_aduser;
	private: System::Windows::Forms::Button^  button_adrecord;

	private: System::Windows::Forms::Label^  label_welcomeadmin;
	private: System::Windows::Forms::Button^  button_adsearch;
	private: System::Windows::Forms::Label^  label_adsearchby;
	private: System::Windows::Forms::Label^  label_adwarn;
	private: System::Windows::Forms::ComboBox^  comboBox_searchadmin;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_adlogout = (gcnew System::Windows::Forms::Button());
			this->button_aduser = (gcnew System::Windows::Forms::Button());
			this->button_adrecord = (gcnew System::Windows::Forms::Button());
			this->label_welcomeadmin = (gcnew System::Windows::Forms::Label());
			this->button_adsearch = (gcnew System::Windows::Forms::Button());
			this->label_adsearchby = (gcnew System::Windows::Forms::Label());
			this->label_adwarn = (gcnew System::Windows::Forms::Label());
			this->comboBox_searchadmin = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button_adlogout
			// 
			this->button_adlogout->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_adlogout->Location = System::Drawing::Point(755, 305);
			this->button_adlogout->Name = L"button_adlogout";
			this->button_adlogout->Size = System::Drawing::Size(103, 33);
			this->button_adlogout->TabIndex = 4;
			this->button_adlogout->Text = L"Logout";
			this->button_adlogout->UseVisualStyleBackColor = true;
			this->button_adlogout->Click += gcnew System::EventHandler(this, &Form_admin::button_adlogout_Click);
			// 
			// button_aduser
			// 
			this->button_aduser->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_aduser->Location = System::Drawing::Point(755, 375);
			this->button_aduser->Name = L"button_aduser";
			this->button_aduser->Size = System::Drawing::Size(103, 33);
			this->button_aduser->TabIndex = 5;
			this->button_aduser->Text = L"Users";
			this->button_aduser->UseVisualStyleBackColor = true;
			this->button_aduser->Click += gcnew System::EventHandler(this, &Form_admin::button_aduser_Click);
			// 
			// button_adrecord
			// 
			this->button_adrecord->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_adrecord->Location = System::Drawing::Point(755, 445);
			this->button_adrecord->Name = L"button_adrecord";
			this->button_adrecord->Size = System::Drawing::Size(103, 33);
			this->button_adrecord->TabIndex = 6;
			this->button_adrecord->Text = L"Records";
			this->button_adrecord->UseVisualStyleBackColor = true;
			this->button_adrecord->Click += gcnew System::EventHandler(this, &Form_admin::button_adrecord_Click);
			// 
			// label_welcomeadmin
			// 
			this->label_welcomeadmin->AutoSize = true;
			this->label_welcomeadmin->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 30, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_welcomeadmin->Location = System::Drawing::Point(322, 139);
			this->label_welcomeadmin->Name = L"label_welcomeadmin";
			this->label_welcomeadmin->Size = System::Drawing::Size(353, 50);
			this->label_welcomeadmin->TabIndex = 11;
			this->label_welcomeadmin->Text = L"Welcome:  Admin";
			// 
			// button_adsearch
			// 
			this->button_adsearch->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_adsearch->Location = System::Drawing::Point(395, 418);
			this->button_adsearch->Name = L"button_adsearch";
			this->button_adsearch->Size = System::Drawing::Size(153, 30);
			this->button_adsearch->TabIndex = 3;
			this->button_adsearch->Text = L"Search";
			this->button_adsearch->UseVisualStyleBackColor = true;
			this->button_adsearch->Click += gcnew System::EventHandler(this, &Form_admin::button_adsearch_Click);
			// 
			// label_adsearchby
			// 
			this->label_adsearchby->AutoSize = true;
			this->label_adsearchby->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_adsearchby->Location = System::Drawing::Point(26, 423);
			this->label_adsearchby->Name = L"label_adsearchby";
			this->label_adsearchby->Size = System::Drawing::Size(81, 25);
			this->label_adsearchby->TabIndex = 2;
			this->label_adsearchby->Text = L"Subject";
			// 
			// label_adwarn
			// 
			this->label_adwarn->AutoSize = true;
			this->label_adwarn->BackColor = System::Drawing::Color::Red;
			this->label_adwarn->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_adwarn->Location = System::Drawing::Point(124, 358);
			this->label_adwarn->Name = L"label_adwarn";
			this->label_adwarn->Size = System::Drawing::Size(201, 20);
			this->label_adwarn->TabIndex = 10;
			this->label_adwarn->Text = L"Please fill correctly below!";
			this->label_adwarn->Visible = false;
			// 
			// comboBox_searchadmin
			// 
			this->comboBox_searchadmin->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_searchadmin->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->comboBox_searchadmin->FormattingEnabled = true;
			this->comboBox_searchadmin->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ALGORITHMS", L"COA", L"FLAT", L"S/W ENGG",
					L"DATA STRUCTURES"
			});
			this->comboBox_searchadmin->Location = System::Drawing::Point(184, 415);
			this->comboBox_searchadmin->Name = L"comboBox_searchadmin";
			this->comboBox_searchadmin->Size = System::Drawing::Size(179, 33);
			this->comboBox_searchadmin->TabIndex = 1;
			// 
			// Form_admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->ControlBox = false;
			this->Controls->Add(this->label_welcomeadmin);
			this->Controls->Add(this->label_adwarn);
			this->Controls->Add(this->button_adrecord);
			this->Controls->Add(this->button_aduser);
			this->Controls->Add(this->button_adlogout);
			this->Controls->Add(this->button_adsearch);
			this->Controls->Add(this->comboBox_searchadmin);
			this->Controls->Add(this->label_adsearchby);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Location = System::Drawing::Point(509, 43);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form_admin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome";
			this->Load += gcnew System::EventHandler(this, &Form_admin::Form_admin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//All the below button events and their functions are defined in the Form_admin.cpp file.
private: System::Void Form_admin_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_adlogout_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_aduser_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_adrecord_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_adsearch_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void take_attd_Click(System::Object^  sender, System::EventArgs^  e);
};
}
