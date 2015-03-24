#pragma once

namespace bba_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_records
	/// </summary>
	public ref class Form_records : public System::Windows::Forms::Form
	{
	public: static bool^ boo = false;
	public:
		Form_records(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_records()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox_recopts;




	private: System::Windows::Forms::Button^  button_recback;
	private: System::Windows::Forms::Label^  label_allrecords;
	private: System::Windows::Forms::DataGridView^  dataGridView1;













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
			this->groupBox_recopts = (gcnew System::Windows::Forms::GroupBox());
			this->button_recback = (gcnew System::Windows::Forms::Button());
			this->label_allrecords = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_recopts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox_recopts
			// 
			this->groupBox_recopts->Controls->Add(this->button_recback);
			this->groupBox_recopts->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox_recopts->Location = System::Drawing::Point(12, 12);
			this->groupBox_recopts->Name = L"groupBox_recopts";
			this->groupBox_recopts->Size = System::Drawing::Size(850, 85);
			this->groupBox_recopts->TabIndex = 0;
			this->groupBox_recopts->TabStop = false;
			this->groupBox_recopts->Text = L"Options";
			// 
			// button_recback
			// 
			this->button_recback->Location = System::Drawing::Point(30, 41);
			this->button_recback->Name = L"button_recback";
			this->button_recback->Size = System::Drawing::Size(93, 32);
			this->button_recback->TabIndex = 0;
			this->button_recback->Text = L"Back";
			this->button_recback->UseVisualStyleBackColor = true;
			this->button_recback->Click += gcnew System::EventHandler(this, &Form_records::button_recback_Click);
			// 
			// label_allrecords
			// 
			this->label_allrecords->AutoSize = true;
			this->label_allrecords->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_allrecords->Location = System::Drawing::Point(13, 104);
			this->label_allrecords->Name = L"label_allrecords";
			this->label_allrecords->Size = System::Drawing::Size(96, 20);
			this->label_allrecords->TabIndex = 1;
			this->label_allrecords->Text = L"All Records:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 141);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(833, 334);
			this->dataGridView1->TabIndex = 9;
			// 
			// Form_records
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(889, 498);
			this->ControlBox = false;
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label_allrecords);
			this->Controls->Add(this->groupBox_recopts);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form_records";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"View Records";
			this->Load += gcnew System::EventHandler(this, &Form_records::Form_records_Load);
			this->groupBox_recopts->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_recback_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void button_editrec_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void Form_records_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
