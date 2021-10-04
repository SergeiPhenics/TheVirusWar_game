#pragma once
#include "TableGame.h"
namespace Project {

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
			playerX = gcnew Player(1);
			playerO = gcnew Player(2);
			buff = playerX;
			myTable = gcnew PaperTable(10, playerX->GetVal(), playerO->GetVal(), pictureBox1);
			//Invalidate();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			delete buff;
			delete playerX;
			delete playerO;
			delete myTable;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private:
		Player^ playerX;
		Player^ playerO;
		Player^ buff;
		PaperTable^ myTable;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ новаяИграToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ обАвтореToolStripMenuItem;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ button4;

	private: System::ComponentModel::IContainer^ components;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->новаяИграToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обАвтореToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox1->Location = System::Drawing::Point(12, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1000, 1000);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button1->Location = System::Drawing::Point(1135, 801);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Пропустить Ход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button2->Location = System::Drawing::Point(1135, 872);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 43);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Сдаться";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1147, 191);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"PlayerX";
			this->toolTip1->SetToolTip(this->label1, L"имя игрока");
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1148, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Сейчас Ходит :";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(1262, 196);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"3";
			this->toolTip1->SetToolTip(this->label3, L"кол-во ходов");
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->новаяИграToolStripMenuItem,
					this->обАвтореToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(9, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(210, 28);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// новаяИграToolStripMenuItem
			// 
			this->новаяИграToolStripMenuItem->Name = L"новаяИграToolStripMenuItem";
			this->новаяИграToolStripMenuItem->Size = System::Drawing::Size(105, 24);
			this->новаяИграToolStripMenuItem->Text = L"Новая Игра";
			this->новаяИграToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::новаяИграToolStripMenuItem_Click);
			// 
			// обАвтореToolStripMenuItem
			// 
			this->обАвтореToolStripMenuItem->Name = L"обАвтореToolStripMenuItem";
			this->обАвтореToolStripMenuItem->Size = System::Drawing::Size(97, 24);
			this->обАвтореToolStripMenuItem->Text = L"Об Авторе";
			this->обАвтореToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::обАвтореToolStripMenuItem_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button3->Location = System::Drawing::Point(1135, 964);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 44);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Темная Тема";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->BackColor = System::Drawing::Color::White;
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button4->Location = System::Drawing::Point(1135, 585);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(159, 47);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Узнать Правила Игры";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(1334, 1056);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Virus War";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool first = true;
	private: int n = 0;
	private: int i;
	private: int j;
	private: bool end;
	private: bool light_theme = true;

	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		i = e->Y / 80;
		j = e->X / 80;

		if (myTable->isMoveLegal(i, j, buff->GetVal()))
		{
			myTable->Add(i, j, buff->Move(myTable->GetVal(i, j)));
			Invalidate();
			if (myTable->isDefeated(buff->GetVal()))
			{
				MessageBox::Show(this->label1->Text + " is Winner!", "Win", MessageBoxButtons::OK);
				end = true;
			}

			button1_Click(nullptr, nullptr);
		}
		if (myTable->isFull())
		{
			MessageBox::Show("Draw", "The End");
			end = true;
		}
		if (end) новаяИграToolStripMenuItem_Click(nullptr, nullptr);
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (light_theme)
		{
			myTable->DrawLight(playerX->GetVal(), playerO->GetVal());
		}
		else
		{
			myTable->DrawDark(playerX->GetVal(), playerO->GetVal());
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		++n;
		if (n == 3)
		{
			first = !first;
			n = 0;
		}
		this->label3->Text = System::Convert::ToString(3 - n);
		if (first)
		{
			this->label1->Text = L"PlayerX";
			buff = playerX;
		}
		else
		{
			this->label1->Text = L"PlayerO";
			buff = playerO;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (first)
		{
			MessageBox::Show("PlayerO is Winner!", "Win", MessageBoxButtons::OK);
		}
		else
		{
			MessageBox::Show("PlayerX is Winner!", "Win", MessageBoxButtons::OK);
		}
		новаяИграToolStripMenuItem_Click(nullptr, nullptr);
	}

	private: System::Void новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		myTable->~PaperTable();
		myTable = gcnew PaperTable(10, playerX->GetVal(), playerO->GetVal(), pictureBox1);
		Invalidate();

		this->label3->Text = L"3";
		this->label1->Text = L"PlayerX";
		first = true;
		buff = playerX;
		n = 0;
		end = false;
	}
	private: System::Void обАвтореToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("I will be waiting for you, gamma-06, there... in the morning,\n'cause it Feels Like Forever\n\n   phenics", "Author");
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		light_theme = !light_theme;
		if (light_theme)
		{
			button3->Text = L"Темная Тема";
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ScrollBar;

			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->новаяИграToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			this->обАвтореToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
		}
		else
		{
			button3->Text = L"Светлая Тема";
			this->BackColor = System::Drawing::SystemColors::WindowText;
			this->menuStrip1->BackColor = System::Drawing::SystemColors::WindowText;

			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->новаяИграToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->обАвтореToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show("Играют два игрока. Ход игрока состоит из трех ходиков. Он может поставить фигуру на место пустой клетки или атаковать соперника. Игрок может ходить через цепочку убитых фигур соперника, если она связана с живой фигурой игрока. Выигрывает тот игрок, который убил все фигуры соперника. Ничья - если все поле занято фигурами.\n\nПриятной Игры!", "Правила Игры");
	}
};
}
