#pragma once

namespace bba_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_prof
	/// </summary>
	public ref class Form_prof : public System::Windows::Forms::Form
	{
	public:
		Form_prof(void)
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
		~Form_prof()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  user;
	protected:
	private: System::Windows::Forms::Label^  label_welcomeuser;
	private: System::Windows::Forms::Label^  label_adwarn;
	private: System::Windows::Forms::Button^  button_logout;
	private: System::Windows::Forms::ComboBox^  comboBox_searchby;
	private: System::Windows::Forms::Label^  label_searchby;
	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::ComboBox^  comboBox_action;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  date_box;

	private: System::Windows::Forms::Label^  ldate;




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
			this->user = (gcnew System::Windows::Forms::Label());
			this->label_welcomeuser = (gcnew System::Windows::Forms::Label());
			this->label_adwarn = (gcnew System::Windows::Forms::Label());
			this->button_logout = (gcnew System::Windows::Forms::Button());
			this->comboBox_searchby = (gcnew System::Windows::Forms::ComboBox());
			this->label_searchby = (gcnew System::Windows::Forms::Label());
			this->button_search = (gcnew System::Windows::Forms::Button());
			this->comboBox_action = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->date_box = (gcnew System::Windows::Forms::TextBox());
			this->ldate = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// user
			// 
			this->user->AutoSize = true;
			this->user->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user->Location = System::Drawing::Point(430, 81);
			this->user->Name = L"user";
			this->user->Size = System::Drawing::Size(102, 50);
			this->user->TabIndex = 27;
			this->user->Text = L"user";
			// 
			// label_welcomeuser
			// 
			this->label_welcomeuser->AutoSize = true;
			this->label_welcomeuser->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_welcomeuser->Location = System::Drawing::Point(228, 81);
			this->label_welcomeuser->Name = L"label_welcomeuser";
			this->label_welcomeuser->Size = System::Drawing::Size(209, 50);
			this->label_welcomeuser->TabIndex = 26;
			this->label_welcomeuser->Text = L"Welcome:";
			// 
			// label_adwarn
			// 
			this->label_adwarn->AutoSize = true;
			this->label_adwarn->BackColor = System::Drawing::Color::Red;
			this->label_adwarn->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_adwarn->Location = System::Drawing::Point(289, 193);
			this->label_adwarn->Name = L"label_adwarn";
			this->label_adwarn->Size = System::Drawing::Size(201, 20);
			this->label_adwarn->TabIndex = 25;
			this->label_adwarn->Text = L"Please fill correctly below!";
			this->label_adwarn->Visible = false;
			// 
			// button_logout
			// 
			this->button_logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_logout->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_logout->Location = System::Drawing::Point(697, 411);
			this->button_logout->Name = L"button_logout";
			this->button_logout->Size = System::Drawing::Size(103, 33);
			this->button_logout->TabIndex = 24;
			this->button_logout->Text = L"Logout";
			this->button_logout->UseVisualStyleBackColor = true;
			this->button_logout->Click += gcnew System::EventHandler(this, &Form_prof::button_logout_Click);
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
			this->comboBox_searchby->Location = System::Drawing::Point(311, 242);
			this->comboBox_searchby->Name = L"comboBox_searchby";
			this->comboBox_searchby->Size = System::Drawing::Size(179, 33);
			this->comboBox_searchby->TabIndex = 23;
			// 
			// label_searchby
			// 
			this->label_searchby->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label_searchby->AutoSize = true;
			this->label_searchby->BackColor = System::Drawing::Color::Transparent;
			this->label_searchby->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_searchby->ForeColor = System::Drawing::Color::Black;
			this->label_searchby->Location = System::Drawing::Point(197, 242);
			this->label_searchby->Name = L"label_searchby";
			this->label_searchby->Size = System::Drawing::Size(83, 24);
			this->label_searchby->TabIndex = 22;
			this->label_searchby->Text = L"Subject:";
			// 
			// button_search
			// 
			this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button_search->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_search->Location = System::Drawing::Point(311, 378);
			this->button_search->Name = L"button_search";
			this->button_search->Size = System::Drawing::Size(179, 44);
			this->button_search->TabIndex = 21;
			this->button_search->Text = L"OK";
			this->button_search->UseVisualStyleBackColor = true;
			this->button_search->Click += gcnew System::EventHandler(this, &Form_prof::button_search_Click);
			// 
			// comboBox_action
			// 
			this->comboBox_action->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->comboBox_action->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox_action->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox_action->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_action->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox_action->FormattingEnabled = true;
			this->comboBox_action->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"VIEW ATTENDANCE", L"GIVE ALL", L"GIVE NONE" });
			this->comboBox_action->Location = System::Drawing::Point(311, 300);
			this->comboBox_action->Name = L"comboBox_action";
			this->comboBox_action->Size = System::Drawing::Size(221, 33);
			this->comboBox_action->TabIndex = 28;
			this->comboBox_action->TextChanged += gcnew System::EventHandler(this, &Form_prof::comboBox_action_TextChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(155, 304);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 23);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Select Action :";
			// 
			// date_box
			// 
			this->date_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_box->Location = System::Drawing::Point(748, 304);
			this->date_box->Name = L"date_box";
			this->date_box->Size = System::Drawing::Size(95, 29);
			this->date_box->TabIndex = 30;
			this->date_box->Visible = false;
			// 
			// ldate
			// 
			this->ldate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ldate->Location = System::Drawing::Point(617, 304);
			this->ldate->Name = L"ldate";
			this->ldate->Size = System::Drawing::Size(112, 23);
			this->ldate->TabIndex = 31;
			this->ldate->Text = L"Enter Date :";
			this->ldate->Visible = false;
			// 
			// Form_prof
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->ControlBox = false;
			this->Controls->Add(this->ldate);
			this->Controls->Add(this->date_box);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox_action);
			this->Controls->Add(this->user);
			this->Controls->Add(this->label_welcomeuser);
			this->Controls->Add(this->label_adwarn);
			this->Controls->Add(this->button_logout);
			this->Controls->Add(this->comboBox_searchby);
			this->Controls->Add(this->label_searchby);
			this->Controls->Add(this->button_search);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form_prof";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Professor\'s View";
			this->Load += gcnew System::EventHandler(this, &Form_prof::Form_prof_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form_prof_Load(System::Object^  sender, System::EventArgs^  e);

private: System::Void button_logout_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button_search_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void comboBox_action_TextChanged(System::Object^  sender, System::EventArgs^  e);
};
}
