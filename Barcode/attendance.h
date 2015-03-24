#include "examples.h"
#include "take_attd.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#pragma once

namespace examples {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Xml;
	//using namespace System::File

	/// <summary>
	/// Summary for attendance
	/// </summary>
	public ref class attendance : public System::Windows::Forms::Form
	{
	public:
		attendance(void)
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
		~attendance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  ok;

	private: System::Windows::Forms::Button^  man_attd;
	private: System::Windows::Forms::TextBox^  date;
	private: System::Windows::Forms::TextBox^  time;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  store;

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
			this->ok = (gcnew System::Windows::Forms::Button());
			this->man_attd = (gcnew System::Windows::Forms::Button());
			this->date = (gcnew System::Windows::Forms::TextBox());
			this->time = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->store = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ok
			// 
			this->ok->Location = System::Drawing::Point(249, 166);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(99, 23);
			this->ok->TabIndex = 0;
			this->ok->Text = L"Browse Barcode";
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &attendance::button1_Click);
			// 
			// man_attd
			// 
			this->man_attd->Location = System::Drawing::Point(428, 138);
			this->man_attd->Name = L"man_attd";
			this->man_attd->Size = System::Drawing::Size(79, 48);
			this->man_attd->TabIndex = 1;
			this->man_attd->Text = L"Manual Attendance";
			this->man_attd->UseVisualStyleBackColor = true;
			this->man_attd->Click += gcnew System::EventHandler(this, &attendance::man_attd_Click);
			// 
			// date
			// 
			this->date->Location = System::Drawing::Point(115, 166);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(100, 20);
			this->date->TabIndex = 2;
			// 
			// time
			// 
			this->time->Location = System::Drawing::Point(115, 197);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(100, 20);
			this->time->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Date(mm/dd/yyyy)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 203);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Time(Hour)";
			// 
			// store
			// 
			this->store->Location = System::Drawing::Point(249, 195);
			this->store->Name = L"store";
			this->store->Size = System::Drawing::Size(99, 23);
			this->store->TabIndex = 6;
			this->store->Text = L"Take Attendance";
			this->store->UseVisualStyleBackColor = true;
			this->store->Click += gcnew System::EventHandler(this, &attendance::store_Click);
			// 
			// attendance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 301);
			this->Controls->Add(this->store);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->time);
			this->Controls->Add(this->date);
			this->Controls->Add(this->man_attd);
			this->Controls->Add(this->ok);
			this->Name = L"attendance";
			this->Text = L"attendance";
			this->Load += gcnew System::EventHandler(this, &attendance::attendance_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private:
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			std::cout << example_reader_code128() << std::endl;
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->ShowDialog();
		}*/

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void attendance_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void man_attd_Click(System::Object^  sender, System::EventArgs^  e);
	//private: System::Void store_Click(System::Object^  sender, System::EventArgs^  e) (
private: System::Void store_Click(System::Object^  sender, System::EventArgs^  e);
};
}
