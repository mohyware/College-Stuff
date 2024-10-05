#pragma once
#include "data.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <sstream>

#include <vector>
namespace socialMedia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createUser
	/// </summary>
	public ref class createUser : public System::Windows::Forms::Form
	{
	public:
		createUser(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		std::vector<std::string> parseCommaDelimitedstring(std::string line) {
			std::vector<std::string> result;
			std::stringstream s_stream(line);
			while (s_stream.good()) {
				std::string substr;
				getline(s_stream, substr, ',');
				result.push_back(substr);

			}
			return result;
	}

	private: System::Windows::Forms::Panel^ panel6;
	public:
	public: System::Windows::Forms::TextBox^ passInfo;
	private:
	private: System::Windows::Forms::Label^ label8;
	public:
		data* dt = new data();
		data* createUser::get_reference_User() { return dt; }


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~createUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	public: System::Windows::Forms::TextBox^ usernameInfo;
	private:
	protected:

	private:

	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::TextBox^ emailInfo;
	private:

	private:
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::Panel^ panel3;
	public: System::Windows::Forms::TextBox^ genderInfo;
	private:

	private:
	private: System::Windows::Forms::Label^ label3;
	public:
	private: System::Windows::Forms::Panel^ panel4;
	public: System::Windows::Forms::TextBox^ birthdayInfo;
	private:

	private:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel5;
	public: System::Windows::Forms::TextBox^ phoneNumberInfo;
	private:

	private:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Button^ button1;
	private:

	public:
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->usernameInfo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->emailInfo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->genderInfo = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->birthdayInfo = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->phoneNumberInfo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->passInfo = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(33, 118);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(232, 3);
			this->panel2->TabIndex = 13;
			// 
			// usernameInfo
			// 
			this->usernameInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->usernameInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->usernameInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->usernameInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->usernameInfo->Location = System::Drawing::Point(33, 90);
			this->usernameInfo->Name = L"usernameInfo";
			this->usernameInfo->Size = System::Drawing::Size(232, 22);
			this->usernameInfo->TabIndex = 12;
			this->usernameInfo->TextChanged += gcnew System::EventHandler(this, &createUser::usernameInfo_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::InfoText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(29, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 21);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Username";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(33, 185);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(232, 3);
			this->panel1->TabIndex = 16;
			// 
			// emailInfo
			// 
			this->emailInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->emailInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->emailInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->emailInfo->Location = System::Drawing::Point(33, 157);
			this->emailInfo->Name = L"emailInfo";
			this->emailInfo->Size = System::Drawing::Size(232, 22);
			this->emailInfo->TabIndex = 15;
			this->emailInfo->TextChanged += gcnew System::EventHandler(this, &createUser::emailInfo_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::InfoText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(29, 133);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 21);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Email ";
			this->label2->Click += gcnew System::EventHandler(this, &createUser::label2_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(33, 257);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(232, 3);
			this->panel3->TabIndex = 19;
			// 
			// genderInfo
			// 
			this->genderInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->genderInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->genderInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->genderInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->genderInfo->Location = System::Drawing::Point(33, 229);
			this->genderInfo->Name = L"genderInfo";
			this->genderInfo->Size = System::Drawing::Size(232, 22);
			this->genderInfo->TabIndex = 18;
			this->genderInfo->TextChanged += gcnew System::EventHandler(this, &createUser::genderInfo_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::InfoText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(29, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 21);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Gender ";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(33, 330);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(232, 3);
			this->panel4->TabIndex = 22;
			// 
			// birthdayInfo
			// 
			this->birthdayInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->birthdayInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->birthdayInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->birthdayInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->birthdayInfo->Location = System::Drawing::Point(33, 302);
			this->birthdayInfo->Name = L"birthdayInfo";
			this->birthdayInfo->Size = System::Drawing::Size(232, 22);
			this->birthdayInfo->TabIndex = 21;
			this->birthdayInfo->TextChanged += gcnew System::EventHandler(this, &createUser::birthdayInfo_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::InfoText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(29, 278);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 21);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Birthday ";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Location = System::Drawing::Point(33, 399);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(232, 3);
			this->panel5->TabIndex = 25;
			this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &createUser::panel5_Paint);
			// 
			// phoneNumberInfo
			// 
			this->phoneNumberInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->phoneNumberInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->phoneNumberInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->phoneNumberInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->phoneNumberInfo->Location = System::Drawing::Point(33, 371);
			this->phoneNumberInfo->Name = L"phoneNumberInfo";
			this->phoneNumberInfo->Size = System::Drawing::Size(232, 22);
			this->phoneNumberInfo->TabIndex = 24;
			this->phoneNumberInfo->TextChanged += gcnew System::EventHandler(this, &createUser::textBox5_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::InfoText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(29, 347);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 21);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Phone Number ";
			this->label5->Click += gcnew System::EventHandler(this, &createUser::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(26, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(111, 37);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Sign Up";
			this->label6->Click += gcnew System::EventHandler(this, &createUser::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::InfoText;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label7->Location = System::Drawing::Point(145, 547);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 21);
			this->label7->TabIndex = 30;
			this->label7->Text = L"Terms and Conditions";
			// 
			// checkBox1
			// 
			this->checkBox1->BackColor = System::Drawing::Color::Black;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->checkBox1->Location = System::Drawing::Point(33, 546);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(120, 25);
			this->checkBox1->TabIndex = 29;
			this->checkBox1->Text = L"I agree to the";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &createUser::checkBox1_CheckedChanged);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(161, 487);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 42);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &createUser::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DodgerBlue;
			this->button1->Enabled = false;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(33, 487);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 42);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Sign Up";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &createUser::button1_Click);
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(33, 464);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(232, 3);
			this->panel6->TabIndex = 33;
			// 
			// passInfo
			// 
			this->passInfo->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->passInfo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->passInfo->ForeColor = System::Drawing::SystemColors::Menu;
			this->passInfo->Location = System::Drawing::Point(33, 436);
			this->passInfo->Name = L"passInfo";
			this->passInfo->Size = System::Drawing::Size(232, 22);
			this->passInfo->TabIndex = 32;
			this->passInfo->UseSystemPasswordChar = true;
			this->passInfo->TextChanged += gcnew System::EventHandler(this, &createUser::passInfo_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::InfoText;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label8->Location = System::Drawing::Point(29, 412);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(76, 21);
			this->label8->TabIndex = 31;
			this->label8->Text = L"Password";
			// 
			// createUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(431, 583);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->passInfo);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->phoneNumberInfo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->birthdayInfo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->genderInfo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->emailInfo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->usernameInfo);
			this->Controls->Add(this->label1);
			this->Name = L"createUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"createUser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool IsNullOrWhiteSpace(const std::string& str) {
			for (char ch : str) {
				if (!std::isspace(static_cast<unsigned char>(ch))) {
					return false;
				}
			}
			return true;
		}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}
}
private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
	   static std::string toStandardString(System::String^ string)
	   {
		   using System::Runtime::InteropServices::Marshal;
		   System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		   char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		   std::string returnString(charPointer, string->Length);
		   Marshal::FreeHGlobal(pointer);

		   return returnString;
	   }

	   static System::String^ toSystemString(const std::string& str) {

		   using namespace System;
		   using namespace System::Runtime::InteropServices;
		   IntPtr pointer = Marshal::StringToHGlobalAnsi(msclr::interop::marshal_as<System::String^>(str));
		   char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		   System::String^ returnString = gcnew System::String(charPointer);
		   Marshal::FreeHGlobal(pointer);

		   return returnString;
	   }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string username,email, birth, gender, phone, pass;
	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

		std::ofstream myFIle("registeredUsers.txt");
		myFIle << username <<"\n" << pass << "\n" << email << "\n" << birth << "\n" << gender << "\n" << phone;
		myFIle.close();
	

	this->Close();

}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) {
		button1->Enabled = true;
	}
	else
	{
		button1->Enabled = false;
	}
}
private: System::Void usernameInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}
}
private: System::Void emailInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}

}
private: System::Void genderInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}

}
private: System::Void birthdayInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}

}
private: System::Void passInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string username, email, birth, gender, phone, pass;

	username = toStandardString(usernameInfo->Text);
	email = toStandardString(emailInfo->Text);
	birth = toStandardString(birthdayInfo->Text);
	gender = toStandardString(genderInfo->Text);
	phone = toStandardString(phoneNumberInfo->Text);
	pass = toStandardString(passInfo->Text);

	if (!IsNullOrWhiteSpace(username) && !IsNullOrWhiteSpace(email) && !IsNullOrWhiteSpace(birth)
		&& !IsNullOrWhiteSpace(gender) && !IsNullOrWhiteSpace(phone) && !IsNullOrWhiteSpace(pass))
	{
		button1->Enabled = true;
	}
	else {
		button1->Enabled = false;

	}

}
};
}
