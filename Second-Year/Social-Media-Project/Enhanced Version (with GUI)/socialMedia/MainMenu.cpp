#include "signUp.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Browse* b = new Browse();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	socialMedia::signUp form;
	Application::Run(% form);
}