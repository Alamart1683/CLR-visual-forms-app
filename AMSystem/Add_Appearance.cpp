#include "Add_Appearance.h"
using namespace System;
using namespace msclr::interop;

namespace AMSystem
{
	//Внесем имена существующих на текущий день сотрудников в комбобокс:
	System::Void Add_Appearance::Add_Appearance_Load(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 1; i < Main_Days[Current_Day - 1].size(); i++)
		{
			std::string s1 = Main_Days[Current_Day - 1][i].get_Name();
			std::string s2 = Main_Days[Current_Day - 1][i].get_Surname();
			std::string s = ". " + s1 + " " + s2;
			String^ s_buf = marshal_as<String^>(s);
			this->comboBox1->Items->Add(Main_Days[Current_Day - 1][i].get_Number() + s_buf);
		}
	}

	//Регистрация прохода
	System::Void Add_Appearance::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//Выделим текущее время:
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			unsigned int Hour, Minutes;
			Hour = t_m->tm_hour;
			Minutes = t_m->tm_min;
			//Поместим время прохода соблюдая логические условия
			if (strcmp(Main_Days[Current_Day - 1][CurrentNumber].get_Attendance(), "В") == 0)
			{
				MessageBox::Show("Незачем проходить на территорию предприятия в ваш законный выходной день!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else if (Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Minutes() == 0 &&
				Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Minutes() == 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Advent(Hour, Minutes);
				String^ Date = gcnew String(DateFromDayNumber(Current_Day - 1, Default_Year, MonthDays, MonthDaysLeap).c_str());
				if (t_m->tm_min < 10)
				{
					MessageBox::Show("Вы прошли на территорию предприятия в " + t_m->tm_hour + ":" + "0" + t_m->tm_min + "." + " Дата прохода: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}			
				else
					MessageBox::Show("Вы прошли на территорию предприятия в " + t_m->tm_hour + ":" + t_m->tm_min + "." + " Дата прохода: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("Невозможно повторно прийти на работу!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Вы не выбрали сотрудника!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//Регистрация выхода
	System::Void Add_Appearance::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//Выделим текущее время:
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			unsigned int Hour, Minutes;
			Hour = t_m->tm_hour;
			Minutes = t_m->tm_min;
			//Поместим время прохода соблюдая логические условия
			if (((Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Hour() + Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Minutes()) != 0) &&
				Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Minutes() == 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Leave(Hour, Minutes);
				String^ Date = gcnew String(DateFromDayNumber(Current_Day - 1, Default_Year, MonthDays, MonthDaysLeap).c_str());
				if (t_m->tm_min < 10)
					MessageBox::Show("Вы покинули территорию предприятия в " + t_m->tm_hour + ":" + "0" + t_m->tm_min + "." + " Дата выхода: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				else
					MessageBox::Show("Вы покинули территорию предприятия в " + t_m->tm_hour + ":" + t_m->tm_min + "." + " Дата выхода: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("Вы не можете повторно уйти с работы!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Вы не выбрали сотрудника!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//Сообщить о уважительной причине:
	System::Void Add_Appearance::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//Добавим уважительную причину отсутствия в отметку о посещении:
			if (strcmp(Main_Days[Current_Day - 1][CurrentNumber].get_Attendance(), "У") != 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Attendance("У");
				MessageBox::Show("Уважительная причина будет учтена!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("Вы уже сообщали о уважительной причине для этого дня!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}			
		}
		else
		{
			MessageBox::Show("Вы не выбрали сотрудника!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}		
	}
}