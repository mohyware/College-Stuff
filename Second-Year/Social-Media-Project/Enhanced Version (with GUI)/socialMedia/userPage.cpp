#include "userPage.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void user(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	socialMedia::userPage form;
	Application::Run(% form);
}