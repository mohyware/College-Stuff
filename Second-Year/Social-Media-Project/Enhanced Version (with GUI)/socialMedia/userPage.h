#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "edit.h"
namespace socialMedia {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for userPage
	/// </summary>
	public ref class userPage : public System::Windows::Forms::Form
	{
	public:
		userPage(void)
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
		~userPage()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public: System::Windows::Forms::Label^ label1;
	private:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button10;


	private: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::TextBox^ likeDesc;
	private:

	private:

	private:

	private:
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::Panel^ panel2;
	public: System::Windows::Forms::TextBox^ alldesc;
	private:

	private:
	private: System::Windows::Forms::Label^ label3;
	public:
	private: System::Windows::Forms::Panel^ panel3;
	public: System::Windows::Forms::TextBox^ allhashtag;
	private:

	private:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel4;
	public: System::Windows::Forms::TextBox^ textBox4;
	private:
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::Label^ email;

	public: System::Windows::Forms::Label^ birh;
	public: System::Windows::Forms::Label^ phone;
	public: System::Windows::Forms::Label^ date;
	public: System::Windows::Forms::Label^ gender;
	public: System::Windows::Forms::Label^ genderi;
	public: System::Windows::Forms::Label^ datei;
	public: System::Windows::Forms::Label^ phonei;
	public: System::Windows::Forms::Label^ birthi;
	public: System::Windows::Forms::Label^ password;


	private:
	public:
	public:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userPage::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->likeDesc = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->alldesc = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->allhashtag = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->birh = (gcnew System::Windows::Forms::Label());
			this->phone = (gcnew System::Windows::Forms::Label());
			this->date = (gcnew System::Windows::Forms::Label());
			this->gender = (gcnew System::Windows::Forms::Label());
			this->genderi = (gcnew System::Windows::Forms::Label());
			this->datei = (gcnew System::Windows::Forms::Label());
			this->phonei = (gcnew System::Windows::Forms::Label());
			this->birthi = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(16, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(41, 43);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::InfoText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(76, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 21);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Username";
			this->label1->Click += gcnew System::EventHandler(this, &userPage::label1_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(506, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 42);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Edit Account";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &userPage::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::PaleVioletRed;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(506, 35);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 42);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Delete Account";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &userPage::button3_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button7->Location = System::Drawing::Point(16, 248);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(155, 42);
			this->button7->TabIndex = 16;
			this->button7->Text = L"Like";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &userPage::button7_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DodgerBlue;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(16, 471);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(155, 42);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Comment";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &userPage::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Location = System::Drawing::Point(236, 248);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(155, 42);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Follow";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &userPage::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::DodgerBlue;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button6->Location = System::Drawing::Point(16, 529);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(155, 42);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Share";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &userPage::button6_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::DodgerBlue;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button8->Location = System::Drawing::Point(236, 529);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(155, 42);
			this->button8->TabIndex = 20;
			this->button8->Text = L"Post";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &userPage::button8_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::DodgerBlue;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->button10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button10->Location = System::Drawing::Point(506, 529);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(140, 42);
			this->button10->TabIndex = 22;
			this->button10->Text = L"Log out";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &userPage::button10_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(16, 215);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(179, 3);
			this->panel1->TabIndex = 27;
			// 
			// likeDesc
			// 
			this->likeDesc->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->likeDesc->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->likeDesc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->likeDesc->ForeColor = System::Drawing::SystemColors::Menu;
			this->likeDesc->Location = System::Drawing::Point(16, 187);
			this->likeDesc->Name = L"likeDesc";
			this->likeDesc->Size = System::Drawing::Size(179, 22);
			this->likeDesc->TabIndex = 26;
			this->likeDesc->TextChanged += gcnew System::EventHandler(this, &userPage::likeDesc_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(12, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 21);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Description";
			this->label2->Click += gcnew System::EventHandler(this, &userPage::label2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(16, 370);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(375, 3);
			this->panel2->TabIndex = 30;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &userPage::panel2_Paint);
			// 
			// alldesc
			// 
			this->alldesc->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->alldesc->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->alldesc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->alldesc->ForeColor = System::Drawing::SystemColors::Menu;
			this->alldesc->Location = System::Drawing::Point(16, 342);
			this->alldesc->Name = L"alldesc";
			this->alldesc->Size = System::Drawing::Size(375, 22);
			this->alldesc->TabIndex = 29;
			this->alldesc->TextChanged += gcnew System::EventHandler(this, &userPage::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(12, 318);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 21);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Description";
			this->label3->Click += gcnew System::EventHandler(this, &userPage::label3_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(16, 438);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(375, 3);
			this->panel3->TabIndex = 33;
			// 
			// allhashtag
			// 
			this->allhashtag->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->allhashtag->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->allhashtag->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->allhashtag->ForeColor = System::Drawing::SystemColors::Menu;
			this->allhashtag->Location = System::Drawing::Point(16, 410);
			this->allhashtag->Name = L"allhashtag";
			this->allhashtag->Size = System::Drawing::Size(375, 22);
			this->allhashtag->TabIndex = 32;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->Location = System::Drawing::Point(12, 386);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 21);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Hashtag";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(236, 215);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(179, 3);
			this->panel4->TabIndex = 36;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox4->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox4->Location = System::Drawing::Point(236, 187);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(179, 22);
			this->textBox4->TabIndex = 35;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Black;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label5.Image")));
			this->label5->Location = System::Drawing::Point(232, 163);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 21);
			this->label5->TabIndex = 34;
			this->label5->Text = L"Username";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::InfoText;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(189, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 21);
			this->label6->TabIndex = 37;
			this->label6->Text = L"Followers";
			this->label6->Click += gcnew System::EventHandler(this, &userPage::label6_Click);
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->BackColor = System::Drawing::SystemColors::InfoText;
			this->email->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->email->Location = System::Drawing::Point(76, 19);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(48, 21);
			this->email->TabIndex = 38;
			this->email->Text = L"email";
			// 
			// birh
			// 
			this->birh->AutoSize = true;
			this->birh->BackColor = System::Drawing::SystemColors::InfoText;
			this->birh->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birh->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->birh->Location = System::Drawing::Point(445, 269);
			this->birh->Name = L"birh";
			this->birh->Size = System::Drawing::Size(71, 21);
			this->birh->TabIndex = 40;
			this->birh->Text = L"Birthday:";
			// 
			// phone
			// 
			this->phone->AutoSize = true;
			this->phone->BackColor = System::Drawing::SystemColors::InfoText;
			this->phone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phone->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->phone->Location = System::Drawing::Point(445, 339);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(57, 21);
			this->phone->TabIndex = 41;
			this->phone->Text = L"Phone:";
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->BackColor = System::Drawing::SystemColors::InfoText;
			this->date->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->date->Location = System::Drawing::Point(445, 408);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(141, 21);
			this->date->TabIndex = 42;
			this->date->Text = L" Registration Date :";
			// 
			// gender
			// 
			this->gender->AutoSize = true;
			this->gender->BackColor = System::Drawing::SystemColors::InfoText;
			this->gender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gender->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->gender->Location = System::Drawing::Point(445, 197);
			this->gender->Name = L"gender";
			this->gender->Size = System::Drawing::Size(64, 21);
			this->gender->TabIndex = 39;
			this->gender->Text = L"Gender:";
			// 
			// genderi
			// 
			this->genderi->AutoSize = true;
			this->genderi->BackColor = System::Drawing::SystemColors::InfoText;
			this->genderi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genderi->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->genderi->Location = System::Drawing::Point(448, 228);
			this->genderi->Name = L"genderi";
			this->genderi->Size = System::Drawing::Size(52, 21);
			this->genderi->TabIndex = 43;
			this->genderi->Text = L"label7";
			// 
			// datei
			// 
			this->datei->AutoSize = true;
			this->datei->BackColor = System::Drawing::SystemColors::InfoText;
			this->datei->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datei->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->datei->Location = System::Drawing::Point(450, 447);
			this->datei->Name = L"datei";
			this->datei->Size = System::Drawing::Size(52, 21);
			this->datei->TabIndex = 46;
			this->datei->Text = L"label7";
			// 
			// phonei
			// 
			this->phonei->AutoSize = true;
			this->phonei->BackColor = System::Drawing::SystemColors::InfoText;
			this->phonei->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phonei->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->phonei->Location = System::Drawing::Point(450, 370);
			this->phonei->Name = L"phonei";
			this->phonei->Size = System::Drawing::Size(52, 21);
			this->phonei->TabIndex = 45;
			this->phonei->Text = L"label8";
			// 
			// birthi
			// 
			this->birthi->AutoSize = true;
			this->birthi->BackColor = System::Drawing::SystemColors::InfoText;
			this->birthi->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->birthi->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->birthi->Location = System::Drawing::Point(448, 299);
			this->birthi->Name = L"birthi";
			this->birthi->Size = System::Drawing::Size(43, 21);
			this->birthi->TabIndex = 44;
			this->birthi->Text = L"birth";
			// 
			// password
			// 
			this->password->AutoSize = true;
			this->password->BackColor = System::Drawing::SystemColors::InfoText;
			this->password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->password->Location = System::Drawing::Point(450, 482);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(52, 21);
			this->password->TabIndex = 47;
			this->password->Text = L"label7";
			this->password->Visible = false;
			// 
			// userPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(687, 583);
			this->Controls->Add(this->password);
			this->Controls->Add(this->datei);
			this->Controls->Add(this->phonei);
			this->Controls->Add(this->birthi);
			this->Controls->Add(this->genderi);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->birh);
			this->Controls->Add(this->gender);
			this->Controls->Add(this->email);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->allhashtag);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->alldesc);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->likeDesc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"userPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"userPage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username, type, desc, hashtag;
	username = toStandardString(label1->Text);
	type = "COMMENT";
	desc = toStandardString(alldesc->Text);
	hashtag = toStandardString(allhashtag->Text);;
	std::ofstream myFIle("activity.txt");
	myFIle << "startactiv" << "\n" << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	myFIle.close();
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username,type, desc,hashtag;
	username = toStandardString(label1->Text);
	type = "LIKE";
	desc = toStandardString(likeDesc->Text);
	hashtag = "-";
	std::ofstream myFIle("activity.txt");
	myFIle << "startactiv"<<"\n" << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	myFIle.close();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username, type, desc, hashtag;
	username = toStandardString(label1->Text);
	type = "FOLLOW";
	desc = toStandardString(textBox4->Text);
	hashtag = "-";
	std::ofstream myFIle("activity.txt");
	myFIle <<"startactiv"<<"\n" << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	myFIle.close();
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username, type, desc, hashtag;
	username = toStandardString(label1->Text);
	type = "SHARE";
	desc = toStandardString(alldesc->Text);
	hashtag = toStandardString(allhashtag->Text);;
	std::ofstream myFIle("activity.txt");
	myFIle << "startactiv" << "\n" << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	myFIle.close();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username, type, desc, hashtag;
	username = toStandardString(label1->Text);
	type = "POST";
	desc = toStandardString(alldesc->Text);
	hashtag = toStandardString(allhashtag->Text);;
	std::ofstream myFIle("activity.txt");
	myFIle << "startactiv" << "\n" << username << "\n" << type << "\n" << desc << "\n" << hashtag;
	myFIle.close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username;
	username = toStandardString(label1->Text);
	std::ofstream myFIle("Deletion.txt");
	myFIle << username ;
	myFIle.close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	edit^ frm11 = gcnew edit;
	frm11->usernameInfo->Text=label1->Text;
	frm11->passInfo->Text = password->Text;
	frm11->birthdayInfo->Text = birthi->Text;
	frm11->phoneNumberInfo->Text = phonei->Text;
	frm11->genderInfo->Text = genderi->Text;
	frm11->emailInfo->Text = email->Text;
	frm11->Show();
}
private: System::Void likeDesc_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
