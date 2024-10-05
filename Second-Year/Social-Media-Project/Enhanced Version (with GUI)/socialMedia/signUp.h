#pragma once
#include "MyForm.h"
#include "createUser.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include "data.h"
#include "Browse.h"
#include <fstream>
#include "hashtag.h"
#include "viewProfile.h"
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
namespace socialMedia {

	public delegate void DataSentHandler(std::string msg);

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for signUp
	/// </summary>
	public ref class signUp : public System::Windows::Forms::Form
	{
	public:
		//event DataSentHandler Datasend;
		signUp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Browse* br = new Browse();


		User* b = new User();
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	public: System::Windows::Forms::TextBox^ profileusername;
	private:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	public:

	public:
		data* dt = new data();


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~signUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ Hashtag;

	private: System::Windows::Forms::Label^ testss;



	public:
	private:

	public:


	private:

	public:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(signUp::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Hashtag = (gcnew System::Windows::Forms::Button());
			this->testss = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->profileusername = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(222, 529);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 42);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &signUp::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DodgerBlue;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(73, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 42);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Sign in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &signUp::button1_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SteelBlue;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(73, 181);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(158, 42);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Sign up";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &signUp::button3_Click);
			// 
			// Hashtag
			// 
			this->Hashtag->BackColor = System::Drawing::Color::RoyalBlue;
			this->Hashtag->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->Hashtag->FlatAppearance->BorderSize = 0;
			this->Hashtag->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Hashtag->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->Hashtag->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Hashtag->Location = System::Drawing::Point(73, 349);
			this->Hashtag->Name = L"Hashtag";
			this->Hashtag->Size = System::Drawing::Size(271, 42);
			this->Hashtag->TabIndex = 10;
			this->Hashtag->Text = L"#Hashtag";
			this->Hashtag->UseVisualStyleBackColor = false;
			this->Hashtag->Click += gcnew System::EventHandler(this, &signUp::button4_Click);
			// 
			// testss
			// 
			this->testss->AutoSize = true;
			this->testss->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->testss->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->testss->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->testss->Location = System::Drawing::Point(147, 9);
			this->testss->Name = L"testss";
			this->testss->Size = System::Drawing::Size(127, 37);
			this->testss->TabIndex = 27;
			this->testss->Text = L"Welcome";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::SteelBlue;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button6->Location = System::Drawing::Point(237, 181);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(107, 42);
			this->button6->TabIndex = 35;
			this->button6->Text = L"Confirm";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &signUp::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button7->Location = System::Drawing::Point(73, 122);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(158, 42);
			this->button7->TabIndex = 36;
			this->button7->Text = L"log into account";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &signUp::button7_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Location = System::Drawing::Point(237, 122);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(107, 42);
			this->button5->TabIndex = 37;
			this->button5->Text = L"Save";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &signUp::button5_Click_1);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Teal;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button8->Location = System::Drawing::Point(73, 408);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(271, 42);
			this->button8->TabIndex = 38;
			this->button8->Text = L"Print All Users Statistics  in Console";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &signUp::button8_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(73, 170);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(271, 5);
			this->panel1->TabIndex = 39;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(73, 229);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(271, 5);
			this->panel2->TabIndex = 40;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::RoyalBlue;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button9->Location = System::Drawing::Point(73, 301);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(82, 42);
			this->button9->TabIndex = 41;
			this->button9->Text = L"Profile";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &signUp::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Teal;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button10->Location = System::Drawing::Point(73, 456);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(271, 42);
			this->button10->TabIndex = 42;
			this->button10->Text = L"Print All Users in Console";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &signUp::button10_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(73, 397);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(271, 5);
			this->panel3->TabIndex = 43;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(73, 291);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(271, 3);
			this->panel4->TabIndex = 46;
			// 
			// profileusername
			// 
			this->profileusername->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->profileusername->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->profileusername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->profileusername->ForeColor = System::Drawing::SystemColors::Menu;
			this->profileusername->Location = System::Drawing::Point(73, 263);
			this->profileusername->Name = L"profileusername";
			this->profileusername->Size = System::Drawing::Size(271, 22);
			this->profileusername->TabIndex = 45;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(69, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 21);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Enter Username to View:";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::RoyalBlue;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(161, 301);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 42);
			this->button4->TabIndex = 47;
			this->button4->Text = L"Statistics";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &signUp::button4_Click_1);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::RoyalBlue;
			this->button11->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button11->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button11->Location = System::Drawing::Point(256, 301);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(88, 42);
			this->button11->TabIndex = 48;
			this->button11->Text = L" Activities";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &signUp::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::IndianRed;
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button12->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button12->Location = System::Drawing::Point(73, 529);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(125, 42);
			this->button12->TabIndex = 49;
			this->button12->Text = L"Clear Console";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &signUp::button12_Click);
			// 
			// signUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(431, 583);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->profileusername);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->testss);
			this->Controls->Add(this->Hashtag);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"signUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"signUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm11 = gcnew MyForm;
		frm11->Show();

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		createUser^ frm22 = gcnew createUser;
		frm22->Show();

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

		   bool compareSecond(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
			   return a.second > b.second; // Change to '<' for ascending order
		   }

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	hashtag^ frm = gcnew hashtag;
	std::vector<std::string> hashtags;
	hashtags=br->print_Treding();
	int num = hashtags.size();
	int cnt = 0;
	if (num==1) {
		frm->hash1->Text = toSystemString("1- "+ hashtags[0]);
		frm->hash1->Visible = true;
	}
	else if (num == 2) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
	}
	else if (num == 3) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
	}
	else if (num == 4) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
	}
	else if (num == 5) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;

	}
	else if (num == 6) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;
		frm->hash6->Text = toSystemString("6- " + hashtags[5]);
		frm->hash6->Visible = true;
	}
	else if (num == 7) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;
		frm->hash6->Text = toSystemString("6- " + hashtags[5]);
		frm->hash6->Visible = true;
		frm->hash7->Text = toSystemString("7- " + hashtags[6]);
		frm->hash7->Visible = true;

	}
	else if (num == 8) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;
		frm->hash6->Text = toSystemString("6- " + hashtags[5]);
		frm->hash6->Visible = true;
		frm->hash7->Text = toSystemString("7- " + hashtags[6]);
		frm->hash7->Visible = true;
		frm->hash8->Text = toSystemString("8- " + hashtags[7]);
		frm->hash8->Visible = true;
	}
	else if (num == 9) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;
		frm->hash6->Text = toSystemString("6- " + hashtags[5]);
		frm->hash6->Visible = true;
		frm->hash7->Text = toSystemString("7- " + hashtags[6]);
		frm->hash7->Visible = true;
		frm->hash8->Text = toSystemString("8- " + hashtags[7]);
		frm->hash8->Visible = true;
		frm->hash9->Text = toSystemString("9- " + hashtags[8]);
		frm->hash9->Visible = true;
		}
	else if (num == 9) {
		frm->hash1->Text = toSystemString("1- " + hashtags[0]);
		frm->hash1->Visible = true;
		frm->hash2->Text = toSystemString("2- " + hashtags[1]);
		frm->hash2->Visible = true;
		frm->hash3->Text = toSystemString("3- " + hashtags[2]);
		frm->hash3->Visible = true;
		frm->hash4->Text = toSystemString("4- " + hashtags[3]);
		frm->hash4->Visible = true;
		frm->hash5->Text = toSystemString("5- " + hashtags[4]);
		frm->hash5->Visible = true;
		frm->hash6->Text = toSystemString("6- " + hashtags[5]);
		frm->hash6->Visible = true;
		frm->hash7->Text = toSystemString("7- " + hashtags[6]);
		frm->hash7->Visible = true;
		frm->hash8->Text = toSystemString("8- " + hashtags[7]);
		frm->hash8->Visible = true;
		frm->hash9->Text = toSystemString("9- " + hashtags[8]);
		frm->hash9->Visible = true;
		frm->hash10->Text = toSystemString("10- " + hashtags[9]);
		frm->hash10->Visible = true;
	}

	frm->Show();
}
private: System::Void labelinfo_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string username, email, birth, gender, phone, pass;

		std::ifstream file("registeredUsers.txt");
		std::string line;

		getline(file, username);
		getline(file, pass);
		getline(file, email);
		getline(file, birth);
		getline(file, gender);
		getline(file, phone);

		file.close();

		int code = br->get_reference_manger()->at->hashCode(username);

		if (!br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT()) && username != "") {
			MessageBox::Show("User Added successfully!", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else if (username == "") {
			MessageBox::Show("Please add the username first!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("username is already taken!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		AVLNode* an = new AVLNode();

		an->hashValue = code;
		an->user->setUserName(username);
		an->user->setEmail(email);
		an->user->setGender(gender);
		an->user->setBirth(birth);
		an->user->setPhoneNumber(phone);
		an->user->setPassword(pass);

		br->get_reference_manger()->at->Insert(an);
		std::cout << username << "\n" << pass << "\n" << email << "\n" << birth << "\n" << gender << "\n" << phone;
	}
		   std::string intToString(int number) {
			   std::stringstream ss;
			   ss << number;
			   return ss.str();
		   }
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream file("loginUsers.txt");
	std::string username, pass;

	getline(file, username);
	getline(file, pass);

	file.close();
	std::cout << username << "\n" << pass ;

	int code = br->get_reference_manger()->at->hashCode(username);

	if (username == "") {
		MessageBox::Show("Please Sign in first!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT()) ) {

		if (br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getPassword() != pass) {
			MessageBox::Show("Incorrect Password!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			userPage^ frm33 = gcnew userPage();
			frm33->label1->Text= toSystemString(username);
			//std::cout<<
			std::string num = intToString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->Followers);
			frm33->label6->Text = toSystemString(num+" "+" Followers");
			frm33->email->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getEmail());
			frm33->genderi->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getGender());
			frm33->birthi->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getBirth());
			frm33->phonei->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getPhoneNumber());
			frm33->datei->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->get_dateRegistration());
			frm33->password->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getPassword());

			frm33->Show();
		}
	}
	else {
		MessageBox::Show("No users found With this username!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

}
	private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {

		std::ifstream dfile("Deletion.txt");
		if (dfile.is_open()) {
			MessageBox::Show("User Deleted Successfully", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

		std::string username;
		getline(dfile, username);
		int code = br->get_reference_manger()->at->hashCode(username);
		br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user;
		br->get_reference_manger()->at->Delete(code);
		dfile.close();
		remove("Deletion.txt");
		return;
		}






		std::ifstream efile("edit.txt");
		if (efile.is_open()) {
			MessageBox::Show("User Updated Successfully", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		std::string username, email, birth, gender, phone, pass;
		getline(efile, username);
		getline(efile, pass);
		getline(efile, email);
		getline(efile, birth);
		getline(efile, gender);
		getline(efile, phone);
			int code = br->get_reference_manger()->at->hashCode(username);
			br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->setGender(gender);
			br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->setEmail(email);
			br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->setBirth(birth);
			br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->setPhoneNumber(phone);
			br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->setPassword(pass);
			efile.close();
			remove("edit.txt");
			return;
		}


		std::ifstream file("activity.txt");
		if (file.is_open()) {
			MessageBox::Show("Saved Successfully", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		else {
			MessageBox::Show("Nothing to Save!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		std::string line;
		while ( getline(file, line))
		{
			std::cout << "========================="<<line<<std::endl;

			if (line == "startactiv")
			{
	std::string username, type, desc, hashtag;

	getline(file, username);
	getline(file, type);
	getline(file, desc);
	getline(file, hashtag);
	std::cout << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	int code = br->get_reference_manger()->at->hashCode(username);
	if (type == "LIKE") {
	br->LIKE(code, type, desc, hashtag);
	}
	else if (type == "FOLLOW") {
		br->FOLLOW(code, type, desc, hashtag);
	}
	else if (type == "COMMENT") {
		br->COMMENT(code, type, desc, hashtag);
	}
	else if (type =="SHARE")
	{
		br->SHARE(code, type, desc, hashtag);
	}
	else if (type == "POST") {
		br->CREATE_POST(code, type, desc, hashtag);
	}
			}
		}
	file.close();
	br->get_reference_manger()->at->print();
	remove("activity.txt");
	//std::cout<< br->get_reference_manger()->at->r
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (br->get_reference_manger()->at->isEmpty())
	{
		MessageBox::Show("No users in the system!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	br->get_reference_manger()->at->print_Statistics();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username = toStandardString(profileusername->Text);

	viewProfile^ frm33 = gcnew viewProfile();
	int code = br->get_reference_manger()->at->hashCode(username);

	if (username == "") {
		MessageBox::Show("Please write username first!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())) {

			frm33->username->Text = toSystemString(username);
			std::string num = intToString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->Followers);
			frm33->followers->Text = toSystemString(num + " " + " Followers");
			frm33->email->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getEmail());
			frm33->genderi->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getGender());
			frm33->birthi->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getBirth());
			frm33->phonei->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->getPhoneNumber());
			frm33->datei->Text = toSystemString(br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->user->get_dateRegistration());
			frm33->Show();
		
	}
	else {
		MessageBox::Show("No users found With this username!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}


}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	std::string username = toStandardString(profileusername->Text);

	int code = br->get_reference_manger()->at->hashCode(username);

	if (username == "") {
		MessageBox::Show("Please write username first!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())) {

		br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())->act.print_statistics_activity();
	}
	else {
		MessageBox::Show("No users found With this username!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username = toStandardString(profileusername->Text);

	int code = br->get_reference_manger()->at->hashCode(username);

	if (username == "") {
		MessageBox::Show("Please write username first!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT())) {

		br->get_reference_manger()->at->printNodeWithValue(code, br->get_reference_manger()->at->search(code, br->get_reference_manger()->at->ROOT()));
	}
	else {
		MessageBox::Show("No users found With this username!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	system("cls");
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (br->get_reference_manger()->at->isEmpty())
	{
		MessageBox::Show("No users in the system!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	br->get_reference_manger()->at->print();
}
};
}
