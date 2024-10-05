#pragma once
namespace socialMedia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for hashtag
	/// </summary>
	public ref class hashtag : public System::Windows::Forms::Form
	{
	public:
		hashtag(void)
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
		~hashtag()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ testss;
	private: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ hash1;
	private:
	public: System::Windows::Forms::Label^ hash2;
	public: System::Windows::Forms::Label^ hash3;
	public: System::Windows::Forms::Label^ hash4;
	public: System::Windows::Forms::Label^ hash8;
	public: System::Windows::Forms::Label^ hash7;
	public: System::Windows::Forms::Label^ hash6;
	public: System::Windows::Forms::Label^ hash5;
	public: System::Windows::Forms::Label^ hash10;
	public: System::Windows::Forms::Label^ hash9;




















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
			this->testss = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->hash1 = (gcnew System::Windows::Forms::Label());
			this->hash2 = (gcnew System::Windows::Forms::Label());
			this->hash3 = (gcnew System::Windows::Forms::Label());
			this->hash4 = (gcnew System::Windows::Forms::Label());
			this->hash8 = (gcnew System::Windows::Forms::Label());
			this->hash7 = (gcnew System::Windows::Forms::Label());
			this->hash6 = (gcnew System::Windows::Forms::Label());
			this->hash5 = (gcnew System::Windows::Forms::Label());
			this->hash10 = (gcnew System::Windows::Forms::Label());
			this->hash9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// testss
			// 
			this->testss->AutoSize = true;
			this->testss->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->testss->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->testss->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->testss->Location = System::Drawing::Point(57, 18);
			this->testss->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->testss->Name = L"testss";
			this->testss->Size = System::Drawing::Size(165, 45);
			this->testss->TabIndex = 28;
			this->testss->Text = L"#Hashtag ";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(65, 529);
			this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(319, 42);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &hashtag::button2_Click);
			// 
			// hash1
			// 
			this->hash1->AutoSize = true;
			this->hash1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash1->Location = System::Drawing::Point(60, 99);
			this->hash1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->hash1->Name = L"hash1";
			this->hash1->Size = System::Drawing::Size(108, 30);
			this->hash1->TabIndex = 30;
			this->hash1->Text = L"#Hashtag ";
			this->hash1->Visible = false;
			this->hash1->Click += gcnew System::EventHandler(this, &hashtag::hash1_Click);
			// 
			// hash2
			// 
			this->hash2->AutoSize = true;
			this->hash2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash2->Location = System::Drawing::Point(60, 139);
			this->hash2->Name = L"hash2";
			this->hash2->Size = System::Drawing::Size(108, 30);
			this->hash2->TabIndex = 31;
			this->hash2->Text = L"#Hashtag ";
			this->hash2->Visible = false;
			// 
			// hash3
			// 
			this->hash3->AutoSize = true;
			this->hash3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash3->Location = System::Drawing::Point(60, 180);
			this->hash3->Name = L"hash3";
			this->hash3->Size = System::Drawing::Size(108, 30);
			this->hash3->TabIndex = 32;
			this->hash3->Text = L"#Hashtag ";
			this->hash3->Visible = false;
			// 
			// hash4
			// 
			this->hash4->AutoSize = true;
			this->hash4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash4->Location = System::Drawing::Point(60, 220);
			this->hash4->Name = L"hash4";
			this->hash4->Size = System::Drawing::Size(108, 30);
			this->hash4->TabIndex = 33;
			this->hash4->Text = L"#Hashtag ";
			this->hash4->Visible = false;
			// 
			// hash8
			// 
			this->hash8->AutoSize = true;
			this->hash8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash8->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash8->Location = System::Drawing::Point(60, 380);
			this->hash8->Name = L"hash8";
			this->hash8->Size = System::Drawing::Size(108, 30);
			this->hash8->TabIndex = 37;
			this->hash8->Text = L"#Hashtag ";
			this->hash8->Visible = false;
			// 
			// hash7
			// 
			this->hash7->AutoSize = true;
			this->hash7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash7->Location = System::Drawing::Point(60, 340);
			this->hash7->Name = L"hash7";
			this->hash7->Size = System::Drawing::Size(108, 30);
			this->hash7->TabIndex = 36;
			this->hash7->Text = L"#Hashtag ";
			this->hash7->Visible = false;
			// 
			// hash6
			// 
			this->hash6->AutoSize = true;
			this->hash6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash6->Location = System::Drawing::Point(60, 299);
			this->hash6->Name = L"hash6";
			this->hash6->Size = System::Drawing::Size(108, 30);
			this->hash6->TabIndex = 35;
			this->hash6->Text = L"#Hashtag ";
			this->hash6->Visible = false;
			// 
			// hash5
			// 
			this->hash5->AutoSize = true;
			this->hash5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash5->Location = System::Drawing::Point(60, 259);
			this->hash5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->hash5->Name = L"hash5";
			this->hash5->Size = System::Drawing::Size(108, 30);
			this->hash5->TabIndex = 34;
			this->hash5->Text = L"#Hashtag ";
			this->hash5->Visible = false;
			// 
			// hash10
			// 
			this->hash10->AutoSize = true;
			this->hash10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash10->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash10->Location = System::Drawing::Point(60, 467);
			this->hash10->Name = L"hash10";
			this->hash10->Size = System::Drawing::Size(108, 30);
			this->hash10->TabIndex = 39;
			this->hash10->Text = L"#Hashtag ";
			this->hash10->Visible = false;
			// 
			// hash9
			// 
			this->hash9->AutoSize = true;
			this->hash9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->hash9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hash9->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->hash9->Location = System::Drawing::Point(60, 423);
			this->hash9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->hash9->Name = L"hash9";
			this->hash9->Size = System::Drawing::Size(108, 30);
			this->hash9->TabIndex = 38;
			this->hash9->Text = L"#Hashtag ";
			this->hash9->Visible = false;
			// 
			// hashtag
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(431, 583);
			this->Controls->Add(this->hash10);
			this->Controls->Add(this->hash9);
			this->Controls->Add(this->hash8);
			this->Controls->Add(this->hash7);
			this->Controls->Add(this->hash6);
			this->Controls->Add(this->hash5);
			this->Controls->Add(this->hash4);
			this->Controls->Add(this->hash3);
			this->Controls->Add(this->hash2);
			this->Controls->Add(this->hash1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->testss);
			this->Font = (gcnew System::Drawing::Font(L"Vivaldi", 8.25F));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"hashtag";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"hashtag";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void hash1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
