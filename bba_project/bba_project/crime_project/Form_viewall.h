#pragma once

namespace bba_project {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_viewall
	/// </summary>
	public ref class Form_viewall : public System::Windows::Forms::Form
	{
	public: static bool^ boo1=false;
	public:
		Form_viewall(String^);
		Form_viewall(String^, String^);
		Form_viewall(String^,String^, String^);
	private: System::Windows::Forms::Label^  label_uname;
	public:
	private: System::Windows::Forms::Label^  label_roll;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label_percnt;
			 String^ use_type;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_viewall()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label_allrecords;
	private: System::Windows::Forms::DataGridView^  dataGridView_records;
	private: System::Windows::Forms::Label^  label_recsearchedby;
	private: System::Windows::Forms::Label^  label_sub;

	private: System::Windows::Forms::Label^  label_searchkeyword;

	private: System::Windows::Forms::Panel^  panel_viewall;

	private: 


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_viewall::typeid));
			this->label_allrecords = (gcnew System::Windows::Forms::Label());
			this->dataGridView_records = (gcnew System::Windows::Forms::DataGridView());
			this->label_recsearchedby = (gcnew System::Windows::Forms::Label());
			this->label_sub = (gcnew System::Windows::Forms::Label());
			this->label_searchkeyword = (gcnew System::Windows::Forms::Label());
			this->panel_viewall = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_percnt = (gcnew System::Windows::Forms::Label());
			this->label_uname = (gcnew System::Windows::Forms::Label());
			this->label_roll = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_records))->BeginInit();
			this->panel_viewall->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_allrecords
			// 
			this->label_allrecords->AutoSize = true;
			this->label_allrecords->BackColor = System::Drawing::Color::Transparent;
			this->label_allrecords->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_allrecords->ForeColor = System::Drawing::Color::Black;
			this->label_allrecords->Location = System::Drawing::Point(55, 14);
			this->label_allrecords->Name = L"label_allrecords";
			this->label_allrecords->Size = System::Drawing::Size(98, 35);
			this->label_allrecords->TabIndex = 7;
			this->label_allrecords->Text = L"Name:";
			// 
			// dataGridView_records
			// 
			this->dataGridView_records->AllowUserToAddRows = false;
			this->dataGridView_records->AllowUserToDeleteRows = false;
			this->dataGridView_records->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView_records->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_records->Location = System::Drawing::Point(18, 144);
			this->dataGridView_records->Name = L"dataGridView_records";
			this->dataGridView_records->ReadOnly = true;
			this->dataGridView_records->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView_records->Size = System::Drawing::Size(833, 291);
			this->dataGridView_records->TabIndex = 8;
			this->dataGridView_records->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form_viewall::dataGridView1_CellContentClick);
			// 
			// label_recsearchedby
			// 
			this->label_recsearchedby->AutoSize = true;
			this->label_recsearchedby->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_recsearchedby->Location = System::Drawing::Point(23, 11);
			this->label_recsearchedby->Name = L"label_recsearchedby";
			this->label_recsearchedby->Size = System::Drawing::Size(100, 29);
			this->label_recsearchedby->TabIndex = 9;
			this->label_recsearchedby->Text = L"Subject:";
			// 
			// label_sub
			// 
			this->label_sub->AutoSize = true;
			this->label_sub->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_sub->Location = System::Drawing::Point(142, 11);
			this->label_sub->Name = L"label_sub";
			this->label_sub->Size = System::Drawing::Size(113, 29);
			this->label_sub->TabIndex = 10;
			this->label_sub->Text = L"abcdefgh";
			// 
			// label_searchkeyword
			// 
			this->label_searchkeyword->AutoSize = true;
			this->label_searchkeyword->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_searchkeyword->Location = System::Drawing::Point(357, 11);
			this->label_searchkeyword->Name = L"label_searchkeyword";
			this->label_searchkeyword->Size = System::Drawing::Size(0, 20);
			this->label_searchkeyword->TabIndex = 11;
			// 
			// panel_viewall
			// 
			this->panel_viewall->Controls->Add(this->label3);
			this->panel_viewall->Controls->Add(this->label_recsearchedby);
			this->panel_viewall->Controls->Add(this->label_percnt);
			this->panel_viewall->Controls->Add(this->label_sub);
			this->panel_viewall->Controls->Add(this->label_searchkeyword);
			this->panel_viewall->Location = System::Drawing::Point(18, 65);
			this->panel_viewall->Name = L"panel_viewall";
			this->panel_viewall->Size = System::Drawing::Size(833, 59);
			this->panel_viewall->TabIndex = 13;
			this->panel_viewall->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(342, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(301, 29);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Percentage Attendance(%)";
			// 
			// label_percnt
			// 
			this->label_percnt->AutoSize = true;
			this->label_percnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_percnt->Location = System::Drawing::Point(658, 11);
			this->label_percnt->Name = L"label_percnt";
			this->label_percnt->Size = System::Drawing::Size(113, 29);
			this->label_percnt->TabIndex = 10;
			this->label_percnt->Text = L"abcdefgh";
			// 
			// label_uname
			// 
			this->label_uname->AutoSize = true;
			this->label_uname->BackColor = System::Drawing::Color::Transparent;
			this->label_uname->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_uname->ForeColor = System::Drawing::Color::Black;
			this->label_uname->Location = System::Drawing::Point(159, 14);
			this->label_uname->Name = L"label_uname";
			this->label_uname->Size = System::Drawing::Size(98, 35);
			this->label_uname->TabIndex = 14;
			this->label_uname->Text = L"Name:";
			// 
			// label_roll
			// 
			this->label_roll->AutoSize = true;
			this->label_roll->BackColor = System::Drawing::Color::Transparent;
			this->label_roll->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_roll->ForeColor = System::Drawing::Color::Black;
			this->label_roll->Location = System::Drawing::Point(491, 14);
			this->label_roll->Name = L"label_roll";
			this->label_roll->Size = System::Drawing::Size(63, 35);
			this->label_roll->TabIndex = 16;
			this->label_roll->Text = L"Roll";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(416, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 35);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Roll:";
			// 
			// Form_viewall
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::ScrollBar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->Controls->Add(this->label_roll);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label_uname);
			this->Controls->Add(this->panel_viewall);
			this->Controls->Add(this->dataGridView_records);
			this->Controls->Add(this->label_allrecords);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form_viewall";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Your Performance";
			this->Load += gcnew System::EventHandler(this, &Form_viewall::Form_viewall_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_records))->EndInit();
			this->panel_viewall->ResumeLayout(false);
			this->panel_viewall->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//defined in Form_viewall.cpp
    
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		 }
private: System::Void Form_viewall_Load(System::Object^  sender, System::EventArgs^  e);
};
}
