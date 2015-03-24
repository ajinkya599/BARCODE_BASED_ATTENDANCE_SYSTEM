#pragma once

namespace bba_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for select_attd
	/// </summary>
	public ref class select_attd : public System::Windows::Forms::Form
	{
	public:
		select_attd(void)
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
		~select_attd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  sel_manual;
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
			this->sel_manual = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sel_manual
			// 
			this->sel_manual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sel_manual->Location = System::Drawing::Point(718, 29);
			this->sel_manual->Name = L"sel_manual";
			this->sel_manual->Size = System::Drawing::Size(147, 80);
			this->sel_manual->TabIndex = 0;
			this->sel_manual->Text = L"Manual Attendance";
			this->sel_manual->UseVisualStyleBackColor = true;
			this->sel_manual->Click += gcnew System::EventHandler(this, &select_attd::sel_manual_Click);
			// 
			// select_attd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 502);
			this->Controls->Add(this->sel_manual);
			this->Name = L"select_attd";
			this->Text = L"select_attd";
			this->Load += gcnew System::EventHandler(this, &select_attd::select_attd_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void sel_manual_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_attd_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
