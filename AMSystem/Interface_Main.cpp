#include "Interface_Main.h"
#include "Interface_Add.h"
#include "Add_Appearance.h"
#include "Violation_Manager.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread] void Main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AMSystem::Interface_Main InterfaceMain;
	Application::Run(%InterfaceMain);
}

//Опередлим переменные для хранения и обработки данных программы
unsigned int Default_Year = 365;
unsigned int Leap_Year = 366;
unsigned short int Current_Day = 0;
unsigned short int Changed_Day = 0;
std::vector<std::vector<Stuff_Member>> Main_Days(Default_Year); //Список дней с посещаемостью всех сотрудников
//Вектора с индексами-месяцами и кол-вом дней в них:
std::vector<int> MonthDays{ 31,28,31,30,31,30,31,31,30,31,30,31 };
std::vector<int> MonthDaysLeap{ 31,29,31,30,31,30,31,31,30,31,30,31 };

//Пусть только прототипы обработчиков событий останутся в заголовке, сами функции определим здесь
namespace AMSystem
{
	System::Void Interface_Main::Interface_Main_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//Вернем день текущей даты:
		Current_Day = monthCalendar1->TodayDate.DayOfYear;
		//Загрузка данных осуществляется с загрузкой самой формы
		Main_Days = Load_Data(Main_Days);
		//Проставим нарушения сотрудникам за прошлые дни, если таковые имеются:
		Main_Days = Add_Marks(Main_Days, Current_Day);
		//Отобразим список рабочих текущего дня:
		//Зададим цикл вывода списка для текущего(базового при загрузке) дня:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//Вывод для выходного дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					listView1->Items[i]->SubItems->Add("-");
					//Уход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный приход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный уход
					listView1->Items[i]->SubItems->Add("-");
					//Посещаемость
					listView1->Items[i]->SubItems->Add("Выходной");
				}
				else
				{
					//Вывод для рабочего дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//Уход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//Реальный приход
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//Реальный уход
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "П") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "Н") == 0)
					{
						listView1->Items[i]->SubItems->Add("Нарушение");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "У") == 0)
					{
						listView1->Items[i]->SubItems->Add("Ув. Причина");
					}
				}
			}
		}
	}
		
	System::Void Interface_Main::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Save_Data(Main_Days);
		MessageBox::Show("Данные были успешно сохранены!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	System::Void Interface_Main::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Interface_Add^ InterfaceAdd = gcnew Interface_Add(this);
		this->Hide();
		InterfaceAdd->ShowDialog();
		this->Show();
		//Обновим таблицу в главной форме после операции добавления сотрудника:
		//Очистим список от предыдущего списка рабочих:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//Отобразим список рабочих текущего дня:
		//Зададим цикл вывода списка для текущего(базового при загрузке) дня:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//Вывод для выходного дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					listView1->Items[i]->SubItems->Add("-");
					//Уход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный приход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный уход
					listView1->Items[i]->SubItems->Add("-");
					//Посещаемость
					listView1->Items[i]->SubItems->Add("Выходной");
				}
				else
				{
					//Вывод для рабочего дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//Уход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//Реальный приход
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//Реальный уход
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "П") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "Н") == 0)
					{
						listView1->Items[i]->SubItems->Add("Нарушение");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "У") == 0)
					{
						listView1->Items[i]->SubItems->Add("Ув. Причина");
					}
				}
			}
		}
	}

	System::Void Interface_Main::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Add_Appearance^ AddAppearance = gcnew Add_Appearance(this);
		this->Hide();
		AddAppearance->ShowDialog();
		this->Show();	
		//Обновим данные о посещаемости на текущий день после прохода сотрудника:
		//Очистим список от предыдущего списка рабочих:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//Отобразим список рабочих текущего дня:
		//Зададим цикл вывода списка для текущего(базового при загрузке) дня:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//Вывод для выходного дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					listView1->Items[i]->SubItems->Add("-");
					//Уход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный приход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный уход
					listView1->Items[i]->SubItems->Add("-");
					//Посещаемость
					listView1->Items[i]->SubItems->Add("Выходной");
				}
				else
				{
					//Вывод для рабочего дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//Уход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//Реальный приход
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//Реальный уход
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "П") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "Н") == 0)
					{
						listView1->Items[i]->SubItems->Add("Нарушение");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "У") == 0)
					{
						listView1->Items[i]->SubItems->Add("Ув. Причина");
					}
				}
			}
		}
	}

	System::Void Interface_Main::button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Violation_Manager^ ViolationManager = gcnew Violation_Manager(this);
		this->Hide();
		ViolationManager->ShowDialog();
		this->Show();
		//Обновим таблицу после возможной процедуры увольнения сотрудника:
		//Очистим список от предыдущего списка рабочих:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//Отобразим список рабочих текущего дня:
		//Зададим цикл вывода списка для текущего(базового при загрузке) дня:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//Вывод для выходного дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					listView1->Items[i]->SubItems->Add("-");
					//Уход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный приход
					listView1->Items[i]->SubItems->Add("-");
					//Реальный уход
					listView1->Items[i]->SubItems->Add("-");
					//Посещаемость
					listView1->Items[i]->SubItems->Add("Выходной");
				}
				else
				{
					//Вывод для рабочего дня:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//Приход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//Уход
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//Реальный приход
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//Реальный уход
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "П") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "Н") == 0)
					{
						listView1->Items[i]->SubItems->Add("Нарушение");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "У") == 0)
					{
						listView1->Items[i]->SubItems->Add("Ув. Причина");
					}
				}
			}
		}
	}

	System::Void Interface_Main::monthCalendar1_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e)
	{
			//Сделаем смену списка для каждого из дней в году в момент выбора даты на календаре:
			Changed_Day = monthCalendar1->SelectionStart.DayOfYear;
			//Очистим список от предыдущего списка рабочих:
			for (int i = listView1->Items->Count - 1; i >= 0; i--)
			{
				listView1->Items[i]->Remove();
			}
			//Проставим новые отметки:
			Main_Days = Add_Marks(Main_Days, Current_Day);
			//Выведем текущий список рабочих:
			if (Main_Days[Changed_Day - 1].size() != 1)
			{
				for (int i = 0; i < Main_Days[Changed_Day - 1].size() - 1; i++)
				{
					if (Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
						&& Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
					{
						//Вывод для выходного дня:
						listView1->Items->Add(Main_Days[Changed_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Name()));
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Surname()));
						//Приход
						listView1->Items[i]->SubItems->Add("-");
						//Уход
						listView1->Items[i]->SubItems->Add("-");
						//Реальный приход
						listView1->Items[i]->SubItems->Add("-");
						//Реальный уход
						listView1->Items[i]->SubItems->Add("-");
						//Посещаемость
						listView1->Items[i]->SubItems->Add("Выходной");
					}
					else
					{
						//Вывод для рабочего дня:
						listView1->Items->Add(Main_Days[Changed_Day - 1][i + 1].get_Number().ToString()); //Добавить поле Номер в первую колонку, далее последовательно привязываем другие поля экземпляра класса
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Name()));
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Surname()));
						//Приход
						if (Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
						//Уход
						if (Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
						//Реальный приход
						if (Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
							listView1->Items[i]->SubItems->Add("");
						else if (Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
						//Реальный уход
						if (Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
							listView1->Items[i]->SubItems->Add("");
						else if (Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

						if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "П") == 0)
						{
							listView1->Items[i]->SubItems->Add("");
						}
						else if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "Н") == 0)
						{
							listView1->Items[i]->SubItems->Add("Нарушение");
						}
						else if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "У") == 0)
						{
							listView1->Items[i]->SubItems->Add("Ув. Причина");
						}
					}
				}
			}		
		}
}