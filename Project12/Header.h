#pragma once
#ifndef HEADER_H
#define HEADER_H


namespace Project12 {

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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(42, 180);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 61);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Определить лежит ли точка на плоскости";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"x = -3     y = 27", L"x = -2     y = 56", L"x = -1     y = 1",
					L"x = -3     y = -27"
			});
			this->listBox1->Location = System::Drawing::Point(42, 64);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(181, 84);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(42, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(181, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Выберите значение y, x";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->listBox1->Items->Clear();

		String^ it = this->listBox1->Items[this->listBox1->SelectedIndex]->ToString();

		int x, y;
		double fx1 = Math::Pow(x, 3);
		double fx2 = Math::Sqrt(2 - Math::Pow(x, 2));
		const double eps = 1e-3;
		int k = listBox1->SelectedIndex;
		String^ it = listBox1->Items[k]->ToString();
		switch (k)
		{
		case 0: { x = -3; y = 27; break;  }
		case 1: { x = -2; y = 56; break;  }
		case 2: { x = -1; y = 1; break;   }
		case 3: { x = -3; y = -27; break; }
		default: MessageBox::Show("Сделайте выбор x, y"); return;
		}
		if (Math::Abs(x) > 1)
		{
			fx1; k = 1;
			if (Math::Abs(fx1 - y) < eps)
			{
				MessageBox::Show("Точка лежит на f(x) ");
			}
			if (Math::Abs(fx1 - y) > eps)
			{
				MessageBox::Show("Точка не лежит на f(x) ");
			}
		}
		if (Math::Abs(x) <= 1)
		{
			fx2; k = 2;
			if (Math::Abs(fx2 - y) < eps)
			{
				MessageBox::Show("Точка лежит на f(x) ");
			}
			if (Math::Abs(fx2 - y) > eps)
			{
				MessageBox::Show("Точка не лежит на f(x) ");
			}
		}
	};


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};;
#endif
}