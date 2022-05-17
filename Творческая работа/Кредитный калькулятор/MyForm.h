#pragma once
#include <iostream>
#include <cmath>

namespace  редитныйкалькул€тор {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;















	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(185, 22);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(198, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 67);
			this->button1->TabIndex = 1;
			this->button1->Text = L"–ешение";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 180);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(185, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(310, 28);
			this->label1->TabIndex = 3;
			this->label1->Text = L"¬ведите сумму кредита";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(458, 28);
			this->label2->TabIndex = 4;
			this->label2->Text = L"¬ведите годовую ставку по кредиту";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 259);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(185, 22);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(13, 215);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(442, 28);
			this->label3->TabIndex = 6;
			this->label3->Text = L"¬ведите срок выплаты (в мес€цах)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(689, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(338, 28);
			this->label4->TabIndex = 7;
			this->label4->Text = L"¬аш ежемес€чный платеж";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(694, 92);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(180, 22);
			this->textBox4->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(17, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 62);
			this->button2->TabIndex = 9;
			this->button2->Text = L"ќчистка";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(694, 180);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(180, 22);
			this->textBox5->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(695, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(210, 28);
			this->label5->TabIndex = 12;
			this->label5->Text = L"ќбща€ выплата";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(695, 215);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(290, 28);
			this->label6->TabIndex = 13;
			this->label6->Text = L"ѕереплата по кредиту";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(694, 259);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(211, 22);
			this->textBox6->TabIndex = 14;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Highlight;
			this->pictureBox1->Location = System::Drawing::Point(-49, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1212, 594);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1146, 411);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Check())
	{
		setlocale(LC_ALL, "Russian");
		double sum, stavka, result; // сумма кредита, годова€ ставка, результат
		int month; //срок в мес€цах 
		sum = System::Convert::ToDouble(textBox1->Text);
		stavka = System::Convert::ToDouble(textBox2->Text);
		month = System::Convert::ToInt64(textBox3->Text);
		result = Convert::ToDouble(math(sum, stavka, month));
		textBox4->Text = Convert::ToString(result);
		textBox5->Text = Convert::ToString(result * month);
		textBox6->Text = Convert::ToString(result * month - sum);
	}
	else
	{
			MessageBox::Show("Ќеправильно введенны данные", "ќшибка!!!");
	}
}
double math(double sum, double stavka, int month) // функци€ нахождени€ ежемес€чного платежа
{
	return sum * ((stavka / (12 * 100)) + (stavka / (12 * 100)) / (pow(1 + (stavka / (12 * 100)), month) - 1));
}
bool Check() // функци€ проверки
{
		   int k = 0; //счетчик зап€тых, нужно либо 0 или 1 зап€та€
		   if ((textBox1->Text->Length == 0) || (textBox2->Text->Length == 0) || (textBox3->Text->Length == 0)) { return false; } // проверка на пустоту
		   for (int i = 0; i < textBox1->Text->Length; i++) //обход по элементам
		   {
			   if (textBox1->Text[i] == ',') { k++; }
			   else if ((textBox1->Text[i] >= '0') && (textBox1->Text[i] <= '9') && (k == 0 || k == 1)) {} //допустимые элементы
			   else { return false; }
		   }
		   k = 0;
		   for (int i = 0; i < textBox2->Text->Length; i++)
		   {
			   if (textBox2->Text[i] == ',') { k++; }
			   else if ((textBox2->Text[i] >= '0') && (textBox2->Text[i] <= '9') && (k == 0 || k == 1)) {}
			   else { return false; }
		   }
		   k = 0;
		   for (int i = 0; i < textBox3->Text->Length; i++)
		   {
			   if ((textBox3->Text[i] >= '0') && (textBox3->Text[i] <= '9')) {}
			   else { return false; }
		   }
		   return true;
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) //кнопка чистки
{
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
}
};
}
