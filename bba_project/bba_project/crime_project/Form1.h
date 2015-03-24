#pragma once
#include "stdAfx.h"

#include "tchar.h"
#include "Form_viewall.h"
#include "login.h"
namespace bba_project {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^  label_welcomeuser;

	private: System::Windows::Forms::Button^  button_logout;


	private: System::Windows::Forms::ComboBox^  comboBox_searchby;
	private: System::Windows::Forms::Label^  label_searchby;



	private: System::Windows::Forms::Label^  label_adwarn;



	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::Label^  user;




	protected:

	protected:




















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label_welcomeuser = (gcnew System::Windows::Forms::Label());
			this->button_logout = (gcnew System::Windows::Forms::Button());
			this->comboBox_searchby = (gcnew System::Windows::Forms::ComboBox());
			this->label_searchby = (gcnew System::Windows::Forms::Label());
			this->label_adwarn = (gcnew System::Windows::Forms::Label());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->user = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label_welcomeuser
			// 
			this->label_welcomeuser->AutoSize = true;
			this->label_welcomeuser->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_welcomeuser->Location = System::Drawing::Point(290, 51);
			this->label_welcomeuser->Name = L"label_welcomeuser";
			this->label_welcomeuser->Size = System::Drawing::Size(209, 50);
			this->label_welcomeuser->TabIndex = 12;
			this->label_welcomeuser->Text = L"Welcome:";
			this->label_welcomeuser->Click += gcnew System::EventHandler(this, &Form1::label_welcomeuser_Click);
			// 
			// button_logout
			// 
			this->button_logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_logout->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_logout->Location = System::Drawing::Point(759, 381);
			this->button_logout->Name = L"button_logout";
			this->button_logout->Size = System::Drawing::Size(103, 33);
			this->button_logout->TabIndex = 7;
			this->button_logout->Text = L"Logout";
			this->button_logout->UseVisualStyleBackColor = true;
			this->button_logout->Click += gcnew System::EventHandler(this, &Form1::button_logout_Click);
			// 
			// comboBox_searchby
			// 
			this->comboBox_searchby->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBox_searchby->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox_searchby->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox_searchby->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_searchby->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->comboBox_searchby->FormattingEnabled = true;
			this->comboBox_searchby->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ALGORITHMS", L"COA", L"FLAT", L"S/W ENGG",
					L"DATA STRUCTURES"
			});
			this->comboBox_searchby->Location = System::Drawing::Point(373, 258);
			this->comboBox_searchby->Name = L"comboBox_searchby";
			this->comboBox_searchby->Size = System::Drawing::Size(179, 33);
			this->comboBox_searchby->TabIndex = 4;
			// 
			// label_searchby
			// 
			this->label_searchby->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_searchby->AutoSize = true;
			this->label_searchby->BackColor = System::Drawing::Color::Transparent;
			this->label_searchby->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_searchby->ForeColor = System::Drawing::Color::Black;
			this->label_searchby->Location = System::Drawing::Point(255, 262);
			this->label_searchby->Name = L"label_searchby";
			this->label_searchby->Size = System::Drawing::Size(81, 24);
			this->label_searchby->TabIndex = 3;
			this->label_searchby->Text = L"Subject:";
			// 
			// label_adwarn
			// 
			this->label_adwarn->AutoSize = true;
			this->label_adwarn->BackColor = System::Drawing::Color::Red;
			this->label_adwarn->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_adwarn->Location = System::Drawing::Point(360, 217);
			this->label_adwarn->Name = L"label_adwarn";
			this->label_adwarn->Size = System::Drawing::Size(201, 20);
			this->label_adwarn->TabIndex = 11;
			this->label_adwarn->Text = L"Please fill correctly below!";
			this->label_adwarn->Visible = false;
			// 
			// button_search
			// 
			this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_search->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_search->Location = System::Drawing::Point(373, 313);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(179, 44);
			this->button_search->TabIndex = 1;
			this->button_search->Text = L"Search";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &Form1::button_search_Click);
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user->Location = System::Drawing::Point(492, 51);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(102, 50);
			this->user->TabIndex = 13;
			this->user->Text = L"user";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->ControlBox = false;
			this->Controls->Add(this->user);
			this->Controls->Add(this->label_welcomeuser);
			this->Controls->Add(this->label_adwarn);
			this->Controls->Add(this->button_logout);
			this->Controls->Add(this->comboBox_searchby);
			this->Controls->Add(this->label_searchby);
			this->Controls->Add(this->button_search);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//All the below button events and their functions are defined in the Form1.cpp file.
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
	//add button allows user to go to a new form- Form_Add, various crime related can be stored in that form.

	private: System::Void button_logout_Click(System::Object^  sender, System::EventArgs^  e);  //to logout from the current session
	private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e); //to search the keywords in textBox_keyword

	private: System::Void label_welcomeuser_Click(System::Object^  sender, System::EventArgs^  e) {
	}


			 //private: System::Void take_attd_Click(System::Object^  sender, System::EventArgs^  e);

	};
}
/*
private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void take_attd_Click(System::Object^  sender, System::EventArgs^  e) {
}
}

*/