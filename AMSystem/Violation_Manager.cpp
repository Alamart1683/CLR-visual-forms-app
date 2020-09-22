#include "Violation_Manager.h"
using namespace System;
using namespace msclr::interop;

namespace AMSystem
{
	
	//Загрузить данные о существуюших сотрудниках в комбобокс
	System::Void Violation_Manager::Violation_Manager_Load(System::Object^  sender, System::EventArgs^  e)
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

	//Нарушения за текущий месяц:
	System::Void Violation_Manager::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//Узнаем номер текущего месяца
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			int Current_Month = t_m->tm_mon;
			//Опеределим номер первого дня текущего месяца в году
			int MonthFirstDay = 0;
			for (int i = 0; i < Current_Month; i++)
			{
				if (MonthFirstDay < Current_Day - 1)
					MonthFirstDay += MonthDays[i];
			}
			//Выведем необходимый набор данных в listview:
			int j = 0; //Переменная для listviewitems
			for (int i = MonthFirstDay; i < Current_Day - 1; i++)
			{
				//Условие проверки наличия работника в штате на тот день
				if (CurrentNumber < Main_Days[i].size() && (strcmp(Main_Days[i][CurrentNumber].get_Attendance(), "Н") == 0))
				{
					//Вывод для рабочего дня:
					std::string Date = DateFromDayNumber(i, Default_Year, MonthDays, MonthDaysLeap);
					listView1->Items->Add(gcnew System::String(Date.c_str())); //Добавить дату нарушения
																			   //Приход
					if (Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
					//Уход
					if (Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
					//Реальный приход
					if (Main_Days[i][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour() != 0)
						listView1->Items[j]->SubItems->Add("");
					else if (Main_Days[i][CurrentNumber].get_Advent().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
					//Реальный уход
					if (Main_Days[i][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour() != 0)
						listView1->Items[j]->SubItems->Add("");
					else if (Main_Days[i][CurrentNumber].get_Leave().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Leave().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Leave().get_Minutes().ToString());
					j++;
				}
			}
		}
		else
		{
			MessageBox::Show("В данный момент нет доступных сотрудников!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}			
	}

	//Нарушения за прошедший месяц:
	System::Void Violation_Manager::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//Узнаем номер текущего месяца
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			int Current_Month = t_m->tm_mon;
			//В рамках года у января нет предыдущего месяца:
			if (t_m->tm_mon != 0)
			{
				//Опеределим номер первого дня предыдущего месяца в году
				int MonthFirstDay = 0;
				int MonthLastDay = 0;
				for (int i = 0; i < Current_Month - 1; i++)
				{
					if (MonthFirstDay < Current_Day - 1)
						MonthFirstDay += MonthDays[i];
				}
				//Определим номер последнего дня предыдщего месяца в году
				MonthLastDay = MonthFirstDay + MonthDays[Current_Month];
				//Выведем необходимый набор данных в listview:
				int j = 0; //Переменная для listviewitems
				for (int i = MonthFirstDay; i < MonthLastDay; i++)
				{
					//Условие проверки наличия работника в штате на тот день
					if (CurrentNumber < Main_Days[i].size() && (strcmp(Main_Days[i][CurrentNumber].get_Attendance(), "Н") == 0))
					{
						//Вывод для рабочего дня:
						std::string Date = DateFromDayNumber(i, Default_Year, MonthDays, MonthDaysLeap);
						listView1->Items->Add(gcnew System::String(Date.c_str())); //Добавить дату нарушения
																				   //Приход
						if (Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
						//Уход
						if (Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
						//Реальный приход
						if (Main_Days[i][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour() != 0)
							listView1->Items[j]->SubItems->Add("");
						else if (Main_Days[i][CurrentNumber].get_Advent().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
						//Реальный уход
						if (Main_Days[i][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour() != 0)
							listView1->Items[j]->SubItems->Add("");
						else if (Main_Days[i][CurrentNumber].get_Leave().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Leave().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Leave().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Leave().get_Minutes().ToString());
						j++;
					}
				}
			}
			else
			{
				MessageBox::Show("В рамках одного года у января не существует предыдущего месяца!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
		}
		else
		{
			MessageBox::Show("В данный момент нет доступных сотрудников!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}

	//Увольнение сотрудника:
	System::Void Violation_Manager::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//Выделим уникальный номер сотрудника выбранного в комбобокс
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			if (Main_Days[Current_Day - 1].size() == 1)
				MessageBox::Show("В данный момент нет доступных для удаления сотрудников!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			else
			{
				Main_Days = Dismiss_Stuff_Member(Main_Days, Current_Day, CurrentNumber);
				//Удалим старый список комбобокса:
				comboBox1->Items->Clear();
				//Обновим комбобокс после удаления сотрудника:
				for (int i = 1; i < Main_Days[Current_Day - 1].size(); i++)
				{
					std::string s1 = Main_Days[Current_Day - 1][i].get_Name();
					std::string s2 = Main_Days[Current_Day - 1][i].get_Surname();
					std::string s = ". " + s1 + " " + s2;
					String^ s_buf = marshal_as<String^>(s);
					this->comboBox1->Items->Add(Main_Days[Current_Day - 1][i].get_Number() + s_buf);
				}
				//Очистим список нарушений после увольнения сотрудника:
				for (int i = listView1->Items->Count - 1; i >= 0; i--)
				{
					listView1->Items[i]->Remove();
				}
			}
				
		}
		else
		{
			MessageBox::Show("В данный момент нет доступных сотрудников!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}
}
