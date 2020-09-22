#include "Add_Appearance.h"
using namespace System;
using namespace msclr::interop;

namespace AMSystem
{
	//������ ����� ������������ �� ������� ���� ����������� � ���������:
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

	//����������� �������
	System::Void Add_Appearance::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//������� ������� �����:
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			unsigned int Hour, Minutes;
			Hour = t_m->tm_hour;
			Minutes = t_m->tm_min;
			//�������� ����� ������� �������� ���������� �������
			if (strcmp(Main_Days[Current_Day - 1][CurrentNumber].get_Attendance(), "�") == 0)
			{
				MessageBox::Show("������� ��������� �� ���������� ����������� � ��� �������� �������� ����!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else if (Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Minutes() == 0 &&
				Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Minutes() == 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Advent(Hour, Minutes);
				String^ Date = gcnew String(DateFromDayNumber(Current_Day - 1, Default_Year, MonthDays, MonthDaysLeap).c_str());
				if (t_m->tm_min < 10)
				{
					MessageBox::Show("�� ������ �� ���������� ����������� � " + t_m->tm_hour + ":" + "0" + t_m->tm_min + "." + " ���� �������: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}			
				else
					MessageBox::Show("�� ������ �� ���������� ����������� � " + t_m->tm_hour + ":" + t_m->tm_min + "." + " ���� �������: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("���������� �������� ������ �� ������!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("�� �� ������� ����������!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//����������� ������
	System::Void Add_Appearance::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//������� ������� �����:
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			unsigned int Hour, Minutes;
			Hour = t_m->tm_hour;
			Minutes = t_m->tm_min;
			//�������� ����� ������� �������� ���������� �������
			if (((Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Hour() + Main_Days[Current_Day - 1][CurrentNumber].get_Advent().get_Minutes()) != 0) &&
				Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][CurrentNumber].get_Leave().get_Minutes() == 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Leave(Hour, Minutes);
				String^ Date = gcnew String(DateFromDayNumber(Current_Day - 1, Default_Year, MonthDays, MonthDaysLeap).c_str());
				if (t_m->tm_min < 10)
					MessageBox::Show("�� �������� ���������� ����������� � " + t_m->tm_hour + ":" + "0" + t_m->tm_min + "." + " ���� ������: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				else
					MessageBox::Show("�� �������� ���������� ����������� � " + t_m->tm_hour + ":" + t_m->tm_min + "." + " ���� ������: " + Date, "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("�� �� ������ �������� ���� � ������!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("�� �� ������� ����������!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//�������� � ������������ �������:
	System::Void Add_Appearance::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//������� ������������ ������� ���������� � ������� � ���������:
			if (strcmp(Main_Days[Current_Day - 1][CurrentNumber].get_Attendance(), "�") != 0)
			{
				Main_Days[Current_Day - 1][CurrentNumber].set_Attendance("�");
				MessageBox::Show("������������ ������� ����� ������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			else
			{
				MessageBox::Show("�� ��� �������� � ������������ ������� ��� ����� ���!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}			
		}
		else
		{
			MessageBox::Show("�� �� ������� ����������!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}		
	}
}