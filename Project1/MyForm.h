#pragma once
#include "Manager.h"
#define FILE_NAME "pyr.txt"

///отладка утечки///
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
///отладка утечки///

namespace Project1 
{
	using namespace System::Runtime::InteropServices;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			Graphics^ g;

			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: добавьте код конструктора
				//

				g = Panel->CreateGraphics();
			}

		protected:
			/// <summary>
			/// Освободить все используемые ресурсы.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Panel^ Panel;
		private: System::Windows::Forms::NumericUpDown^ dXNumericUpDown;
		private: System::Windows::Forms::NumericUpDown^ dYNumericUpDown;
		private: System::Windows::Forms::NumericUpDown^ dZNumericUpDown;






		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ scaleButton;
		private: System::Windows::Forms::NumericUpDown^ kZNumericUpDown;

		private: System::Windows::Forms::NumericUpDown^ kYNumericUpDown;

		private: System::Windows::Forms::NumericUpDown^ kXNumericUpDown;
		private: System::Windows::Forms::Button^ rotateButton;
		private: System::Windows::Forms::NumericUpDown^ angleZNumericUpDown;



		private: System::Windows::Forms::NumericUpDown^ angleYNumericUpDown;
		private: System::Windows::Forms::NumericUpDown^ angleXNumericUpDown;

		private: System::Windows::Forms::Button^ loadFileButton;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::Label^ label9;



		protected:

		private:
			/// <summary>
			/// Обязательная переменная конструктора.
			/// </summary>
			System::ComponentModel::Container^ components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Требуемый метод для поддержки конструктора — не изменяйте 
			/// содержимое этого метода с помощью редактора кода.
			/// </summary>
			void InitializeComponent(void)
			{
				this->Panel = (gcnew System::Windows::Forms::Panel());
				this->dXNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->dYNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->dZNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->scaleButton = (gcnew System::Windows::Forms::Button());
				this->kZNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->kYNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->kXNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->rotateButton = (gcnew System::Windows::Forms::Button());
				this->angleZNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->angleYNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->angleXNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
				this->loadFileButton = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dXNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dYNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dZNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kZNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kYNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kXNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleZNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleYNumericUpDown))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleXNumericUpDown))->BeginInit();
				this->SuspendLayout();
				// 
				// Panel
				// 
				this->Panel->BackColor = System::Drawing::SystemColors::Window;
				this->Panel->Location = System::Drawing::Point(277, 12);
				this->Panel->Name = L"Panel";
				this->Panel->Size = System::Drawing::Size(1007, 773);
				this->Panel->TabIndex = 0;
				// 
				// dXNumericUpDown
				// 
				this->dXNumericUpDown->Location = System::Drawing::Point(12, 59);
				this->dXNumericUpDown->Name = L"dXNumericUpDown";
				this->dXNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->dXNumericUpDown->TabIndex = 1;
				// 
				// dYNumericUpDown
				// 
				this->dYNumericUpDown->Location = System::Drawing::Point(79, 59);
				this->dYNumericUpDown->Name = L"dYNumericUpDown";
				this->dYNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->dYNumericUpDown->TabIndex = 2;
				// 
				// dZNumericUpDown
				// 
				this->dZNumericUpDown->Location = System::Drawing::Point(146, 59);
				this->dZNumericUpDown->Name = L"dZNumericUpDown";
				this->dZNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->dZNumericUpDown->TabIndex = 3;
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(13, 112);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(194, 32);
				this->button1->TabIndex = 4;
				this->button1->Text = L"Переместить";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				// 
				// scaleButton
				// 
				this->scaleButton->Location = System::Drawing::Point(12, 287);
				this->scaleButton->Name = L"scaleButton";
				this->scaleButton->Size = System::Drawing::Size(194, 35);
				this->scaleButton->TabIndex = 8;
				this->scaleButton->Text = L"Промасштабировать";
				this->scaleButton->UseVisualStyleBackColor = true;
				this->scaleButton->Click += gcnew System::EventHandler(this, &MyForm::scaleButton_Click);
				// 
				// kZNumericUpDown
				// 
				this->kZNumericUpDown->Location = System::Drawing::Point(145, 234);
				this->kZNumericUpDown->Name = L"kZNumericUpDown";
				this->kZNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->kZNumericUpDown->TabIndex = 7;
				// 
				// kYNumericUpDown
				// 
				this->kYNumericUpDown->Location = System::Drawing::Point(78, 234);
				this->kYNumericUpDown->Name = L"kYNumericUpDown";
				this->kYNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->kYNumericUpDown->TabIndex = 6;
				// 
				// kXNumericUpDown
				// 
				this->kXNumericUpDown->Location = System::Drawing::Point(11, 234);
				this->kXNumericUpDown->Name = L"kXNumericUpDown";
				this->kXNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->kXNumericUpDown->TabIndex = 5;
				// 
				// rotateButton
				// 
				this->rotateButton->Location = System::Drawing::Point(13, 456);
				this->rotateButton->Name = L"rotateButton";
				this->rotateButton->Size = System::Drawing::Size(194, 35);
				this->rotateButton->TabIndex = 12;
				this->rotateButton->Text = L"Повернуть";
				this->rotateButton->UseVisualStyleBackColor = true;
				this->rotateButton->Click += gcnew System::EventHandler(this, &MyForm::rotateButton_Click);
				// 
				// angleZNumericUpDown
				// 
				this->angleZNumericUpDown->Location = System::Drawing::Point(146, 403);
				this->angleZNumericUpDown->Name = L"angleZNumericUpDown";
				this->angleZNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->angleZNumericUpDown->TabIndex = 11;
				// 
				// angleYNumericUpDown
				// 
				this->angleYNumericUpDown->Location = System::Drawing::Point(79, 403);
				this->angleYNumericUpDown->Name = L"angleYNumericUpDown";
				this->angleYNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->angleYNumericUpDown->TabIndex = 10;
				// 
				// angleXNumericUpDown
				// 
				this->angleXNumericUpDown->Cursor = System::Windows::Forms::Cursors::Default;
				this->angleXNumericUpDown->Location = System::Drawing::Point(12, 403);
				this->angleXNumericUpDown->Name = L"angleXNumericUpDown";
				this->angleXNumericUpDown->Size = System::Drawing::Size(61, 26);
				this->angleXNumericUpDown->TabIndex = 9;
				// 
				// loadFileButton
				// 
				this->loadFileButton->Cursor = System::Windows::Forms::Cursors::Default;
				this->loadFileButton->ForeColor = System::Drawing::SystemColors::ControlText;
				this->loadFileButton->Location = System::Drawing::Point(13, 529);
				this->loadFileButton->Name = L"loadFileButton";
				this->loadFileButton->Size = System::Drawing::Size(194, 36);
				this->loadFileButton->TabIndex = 14;
				this->loadFileButton->Text = L"Загрузить файл";
				this->loadFileButton->UseVisualStyleBackColor = true;
				this->loadFileButton->Click += gcnew System::EventHandler(this, &MyForm::loadFileButton_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(13, 13);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(29, 20);
				this->label1->TabIndex = 15;
				this->label1->Text = L"dX";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(141, 13);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(28, 20);
				this->label2->TabIndex = 16;
				this->label2->Text = L"dZ";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(74, 13);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(29, 20);
				this->label3->TabIndex = 17;
				this->label3->Text = L"dY";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(142, 191);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(27, 20);
				this->label4->TabIndex = 19;
				this->label4->Text = L"kZ";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(75, 191);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(28, 20);
				this->label5->TabIndex = 20;
				this->label5->Text = L"kY";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(14, 191);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(28, 20);
				this->label6->TabIndex = 18;
				this->label6->Text = L"kX";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(141, 364);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(58, 20);
				this->label7->TabIndex = 19;
				this->label7->Text = L"angleZ";
				// 
				// label8
				// 
				this->label8->AutoSize = true;
				this->label8->Location = System::Drawing::Point(74, 364);
				this->label8->Name = L"label8";
				this->label8->Size = System::Drawing::Size(59, 20);
				this->label8->TabIndex = 20;
				this->label8->Text = L"angleY";
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->Location = System::Drawing::Point(13, 364);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(59, 20);
				this->label9->TabIndex = 18;
				this->label9->Text = L"angleX";
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1296, 797);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label8);
				this->Controls->Add(this->label9);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->loadFileButton);
				this->Controls->Add(this->rotateButton);
				this->Controls->Add(this->angleZNumericUpDown);
				this->Controls->Add(this->angleYNumericUpDown);
				this->Controls->Add(this->angleXNumericUpDown);
				this->Controls->Add(this->scaleButton);
				this->Controls->Add(this->kZNumericUpDown);
				this->Controls->Add(this->kYNumericUpDown);
				this->Controls->Add(this->kXNumericUpDown);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->dZNumericUpDown);
				this->Controls->Add(this->dYNumericUpDown);
				this->Controls->Add(this->dXNumericUpDown);
				this->Controls->Add(this->Panel);
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dXNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dYNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dZNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kZNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kYNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kXNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleZNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleYNumericUpDown))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->angleXNumericUpDown))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}

	#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Manager myManager;
			myManager.currentTask = MOVE;

			myManager.moveVal.dx = Convert::ToDouble(dXNumericUpDown->Value);
			myManager.moveVal.dy = Convert::ToDouble(dYNumericUpDown->Value);
			myManager.moveVal.dz = Convert::ToDouble(dZNumericUpDown->Value);

			int codeError = CallManager(myManager, Panel, g);

			if (codeError)
			{
				ErrorsShowMessage(codeError);
			}
		}

		private: System::Void scaleButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Manager myManager;
			myManager.currentTask = SCALE;

			myManager.scaleVal.kx = Convert::ToDouble(kXNumericUpDown->Value);
			myManager.scaleVal.ky = Convert::ToDouble(kYNumericUpDown->Value);
			myManager.scaleVal.kz = Convert::ToDouble(kZNumericUpDown->Value);

			int codeError = CallManager(myManager, Panel, g);

			if (codeError)
			{
				ErrorsShowMessage(codeError);
			}
		}

		private: System::Void rotateButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Manager myManager;
			myManager.currentTask = ROTATE;

			myManager.rotateVal.angleX = Convert::ToDouble(angleXNumericUpDown->Value);
			myManager.rotateVal.angleY = Convert::ToDouble(angleYNumericUpDown->Value);
			myManager.rotateVal.angleZ = Convert::ToDouble(angleZNumericUpDown->Value);

			int codeError = CallManager(myManager, Panel, g);

			if (codeError)
			{
				ErrorsShowMessage(codeError);
			}
		}

		private: System::Void loadFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Manager myManager;
			myManager.currentTask = LOAD_FILE;
			myManager.fileName = FILE_NAME;

			int codeError = CallManager(myManager, Panel, g);

			if (codeError)
			{
				ErrorsShowMessage(codeError);
			}
		}

		private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
		{
			if (CloceQuestion())
			{
				Manager myManager;
				myManager.currentTask = FREE;

				TaskManager(myManager, Panel, g);

				///отладка утечки///
				_CrtDumpMemoryLeaks();
				///отладка утечки///

				e->Cancel = false;
			}
			else
			{
				e->Cancel = true;
			}
		}

		private: int CallManager(Manager &myManager, System::Windows::Forms::Panel^ Panel, System::Drawing::Graphics^ g)
		{
			int codeError = TaskManager(myManager, Panel, g);

			if (!codeError)
				codeError = DrawAction(myManager, Panel, g);

			return codeError;
		} 

		private: int DrawAction(Manager& myManager, System::Windows::Forms::Panel^ Panel, System::Drawing::Graphics^ g)
		{
			myManager.currentTask = DRAW;
			int codeError = TaskManager(myManager, Panel, g);

			return codeError;
		}

		private: bool CloceQuestion()
		{
			return (MessageBox::Show("Вы уверены, что хотите выйти?", "Выход",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes);
		}
};
};
