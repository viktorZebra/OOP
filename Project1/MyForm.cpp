#include "MyForm.h"
#include <Windows.h>
using namespace Project1;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// creating new form
	// with default constructor
	MyForm form;

	// run application with form
	Application::Run(% form);


	// The function returns an int value. The return value is !!not!! used by the operating system.
	return 0;
}

