#pragma once

namespace socialMedia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for viewProfile
	/// </summary>
	public ref class viewProfile : public System::Windows::Forms::Form
	{
	public:
		viewProfile(void)
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
		~viewProfile()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	public: System::Windows::Forms::Label^ datei;
	public: System::Windows::Forms::Label^ phonei;
	public: System::Windows::Forms::Label^ birthi;
	public: System::Windows::Forms::Label^ genderi;
	public: System::Windows::Forms::Label^ date;
	public: System::Windows::Forms::Label^ phone;
	public: System::Windows::Forms::Label^ birh;
	public: System::Windows::Forms::Label^ gender;
	public: System::Windows::Forms::Label^ email;
	public: System::Windows::Forms::Label^ followers;
	public: System::Windows::Forms::Label^ username;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;

	public: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel4;




	private:

	private:


























































	private:





	public:
	private:
	public:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(viewProfile::typeid));
			this->datei = (gcnew System::Windows::Forms::Label());
			this->phonei = (gcnew System::Windows::Forms::Label());
			this->birthi = (gcnew System::Windows::Forms::Label());
			this->genderi = (gcnew System::Windows::Forms::Label());
			this->date = (gcnew System::Windows::Forms::Label());
			this->phone = (gcnew System::Windows::Forms::Label());
			this->birh = (gcnew System::Windows::Forms::Label());
			this->gender = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->followers = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// datei
			// 
			this->datei->AutoSize = true;
			this->datei->BackColor = System::Drawing::SystemColors::InfoText;
			this->datei->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datei->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->datei->Location = System::Drawing::Point(36, 428);
			this->datei->Name = L"datei";
			this->datei->Size = System::Drawing::Size(37, 21);
			this->datei->TabIndex = 55;
			this->datei->Text = L"info";
			// 
			// phonei
			// 
			this->phonei->AutoSize = true;
			this->phonei->BackColor = System::Drawing::SystemColors::InfoText;
			this->phonei->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phonei->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->phonei->Location = System::Drawing::Point(36, 351);
			this->phonei->Name = L"phonei";
			this->phonei->Size = System::Drawing::Size(37, 21);
			this->phonei->TabIndex = 54;
			this->phonei->Text = L"info";
			// 
			// birthi
			// 
			this->birthi->AutoSize = true;
			this->birthi->BackColor = System::Drawing::SystemColors::InfoText;
			this->birthi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birthi->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->birthi->Location = System::Drawing::Point(34, 280);
			this->birthi->Name = L"birthi";
			this->birthi->Size = System::Drawing::Size(37, 21);
			this->birthi->TabIndex = 53;
			this->birthi->Text = L"info";
			// 
			// genderi
			// 
			this->genderi->AutoSize = true;
			this->genderi->BackColor = System::Drawing::SystemColors::InfoText;
			this->genderi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genderi->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->genderi->Location = System::Drawing::Point(34, 209);
			this->genderi->Name = L"genderi";
			this->genderi->Size = System::Drawing::Size(37, 21);
			this->genderi->TabIndex = 52;
			this->genderi->Text = L"info";
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->BackColor = System::Drawing::SystemColors::InfoText;
			this->date->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->date->Location = System::Drawing::Point(31, 389);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(141, 21);
			this->date->TabIndex = 51;
			this->date->Text = L" Registration Date :";
			// 
			// phone
			// 
			this->phone->AutoSize = true;
			this->phone->BackColor = System::Drawing::SystemColors::InfoText;
			this->phone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phone->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->phone->Location = System::Drawing::Point(31, 320);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(57, 21);
			this->phone->TabIndex = 50;
			this->phone->Text = L"Phone:";
			// 
			// birh
			// 
			this->birh->AutoSize = true;
			this->birh->BackColor = System::Drawing::SystemColors::InfoText;
			this->birh->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birh->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->birh->Location = System::Drawing::Point(31, 250);
			this->birh->Name = L"birh";
			this->birh->Size = System::Drawing::Size(71, 21);
			this->birh->TabIndex = 49;
			this->birh->Text = L"Birthday:";
			// 
			// gender
			// 
			this->gender->AutoSize = true;
			this->gender->BackColor = System::Drawing::SystemColors::InfoText;
			this->gender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gender->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->gender->Location = System::Drawing::Point(31, 178);
			this->gender->Name = L"gender";
			this->gender->Size = System::Drawing::Size(64, 21);
			this->gender->TabIndex = 48;
			this->gender->Text = L"Gender:";
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->BackColor = System::Drawing::SystemColors::InfoText;
			this->email->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->email->Location = System::Drawing::Point(72, 29);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(48, 21);
			this->email->TabIndex = 60;
			this->email->Text = L"email";
			// 
			// followers
			// 
			this->followers->AutoSize = true;
			this->followers->BackColor = System::Drawing::SystemColors::InfoText;
			this->followers->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->followers->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->followers->Location = System::Drawing::Point(185, 67);
			this->followers->Name = L"followers";
			this->followers->Size = System::Drawing::Size(77, 21);
			this->followers->TabIndex = 59;
			this->followers->Text = L"Followers";
			// 
			// username
			// 
			this->username->AutoSize = true;
			this->username->BackColor = System::Drawing::SystemColors::InfoText;
			this->username->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->username->Location = System::Drawing::Point(72, 67);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(81, 21);
			this->username->TabIndex = 58;
			this->username->Text = L"Username";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(12, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(41, 43);
			this->pictureBox1->TabIndex = 57;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(204, 517);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 42);
			this->button2->TabIndex = 61;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &viewProfile::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::InfoText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(30, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 30);
			this->label2->TabIndex = 63;
			this->label2->Text = L"Info";
			this->label2->Click += gcnew System::EventHandler(this, &viewProfile::label2_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(35, 161);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(143, 4);
			this->panel4->TabIndex = 64;
			// 
			// viewProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(431, 583);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->email);
			this->Controls->Add(this->followers);
			this->Controls->Add(this->username);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->datei);
			this->Controls->Add(this->phonei);
			this->Controls->Add(this->birthi);
			this->Controls->Add(this->genderi);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->birh);
			this->Controls->Add(this->gender);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"viewProfile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"viewProfile";
			this->Load += gcnew System::EventHandler(this, &viewProfile::viewProfile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void viewProfile_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
