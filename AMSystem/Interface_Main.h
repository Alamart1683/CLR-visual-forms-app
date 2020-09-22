#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include "string.h"
#include <windows.h>
#include <algorithm>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include "Sub_Programs.h"
#include "Stuff_Member.h"

//Объявим их в общей видимости
extern unsigned int Default_Year;
extern unsigned int Leap_Year;
extern unsigned short int Current_Day;
extern unsigned short int Changed_Day;
extern std::vector<std::vector<Stuff_Member>> Main_Days; //Список дней с посещаемостью всех сотрудников
extern std::vector<int> MonthDays;
extern std::vector<int> MonthDaysLeap;

namespace AMSystem
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для Interface_Main
	/// </summary>
	public ref class Interface_Main : public System::Windows::Forms::Form
	{
	public:
		Interface_Main(void)
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
		~Interface_Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface_Main::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::LightCyan;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8
			});
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(220, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(598, 424);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"№";
			this->columnHeader1->Width = 29;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Имя";
			this->columnHeader2->Width = 80;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Фамилия";
			this->columnHeader3->Width = 80;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Начало работы";
			this->columnHeader4->Width = 96;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Конец работы";
			this->columnHeader5->Width = 93;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Пришёл";
			this->columnHeader6->Width = 70;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Ушёл";
			this->columnHeader7->Width = 70;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Отметка";
			this->columnHeader8->Width = 75;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::DarkCyan;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->monthCalendar1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(184, 174);
			this->panel1->TabIndex = 3;
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->BackColor = System::Drawing::Color::Teal;
			this->monthCalendar1->Location = System::Drawing::Point(9, 5);
			this->monthCalendar1->MaxDate = System::DateTime(2018, 12, 31, 0, 0, 0, 0);
			this->monthCalendar1->MaxSelectionCount = 1;
			this->monthCalendar1->MinDate = System::DateTime(2018, 1, 1, 0, 0, 0, 0);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->ShowTodayCircle = false;
			this->monthCalendar1->TabIndex = 0;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Interface_Main::monthCalendar1_DateSelected);
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::DarkCyan;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(12, 192);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(184, 244);
			this->panel2->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Cyan;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(9, 180);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(164, 50);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Менеджер нарушений";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Interface_Main::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Cyan;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(9, 124);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 50);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Зарегистрировать проход";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Interface_Main::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Cyan;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(9, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Добавить сотрудника";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Interface_Main::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cyan;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(9, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сохранить данные";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Interface_Main::button1_Click);
			// 
			// Interface_Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Aquamarine;
			this->ClientSize = System::Drawing::Size(830, 448);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->listView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(846, 486);
			this->MinimumSize = System::Drawing::Size(846, 486);
			this->Name = L"Interface_Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AMSystem";
			this->Load += gcnew System::EventHandler(this, &Interface_Main::Interface_Main_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Interface_Main_Load(System::Object^  sender, System::EventArgs^  e);

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void monthCalendar1_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e);


};
}
