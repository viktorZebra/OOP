#include "ErrorsShowMessage.h"

void ErrorsShowMessage(int codeError)
{
	if (codeError == OPEN_FILE_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Файл не был загружен", "File error", System::Windows::Forms::MessageBoxButtons::OKCancel, System::Windows::Forms::MessageBoxIcon::Error);
	}
	if (codeError == INPUT_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Неверный ввод", "Input error", System::Windows::Forms::MessageBoxButtons::OKCancel, System::Windows::Forms::MessageBoxIcon::Error);
	}
	if (codeError == ALLOC_MEMORY_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Не выделилась память", "Alloc error", System::Windows::Forms::MessageBoxButtons::OKCancel, System::Windows::Forms::MessageBoxIcon::Error);
	}
}