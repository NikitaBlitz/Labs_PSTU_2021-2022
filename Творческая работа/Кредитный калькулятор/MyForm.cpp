#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ProjectName - name of your project
    // NameForm - name of the form to run
    Кредитныйкалькулятор::MyForm form;
    Application::Run(% form);
}
