#include "Violation_Manager.h"
using namespace System;
using namespace msclr::interop;

namespace AMSystem
{
	
	//��������� ������ � ������������ ����������� � ���������
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

	//��������� �� ������� �����:
	System::Void Violation_Manager::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//������ ����� �������� ������
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			int Current_Month = t_m->tm_mon;
			//���������� ����� ������� ��� �������� ������ � ����
			int MonthFirstDay = 0;
			for (int i = 0; i < Current_Month; i++)
			{
				if (MonthFirstDay < Current_Day - 1)
					MonthFirstDay += MonthDays[i];
			}
			//������� ����������� ����� ������ � listview:
			int j = 0; //���������� ��� listviewitems
			for (int i = MonthFirstDay; i < Current_Day - 1; i++)
			{
				//������� �������� ������� ��������� � ����� �� ��� ����
				if (CurrentNumber < Main_Days[i].size() && (strcmp(Main_Days[i][CurrentNumber].get_Attendance(), "�") == 0))
				{
					//����� ��� �������� ���:
					std::string Date = DateFromDayNumber(i, Default_Year, MonthDays, MonthDaysLeap);
					listView1->Items->Add(gcnew System::String(Date.c_str())); //�������� ���� ���������
																			   //������
					if (Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
					//����
					if (Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
					//�������� ������
					if (Main_Days[i][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour() != 0)
						listView1->Items[j]->SubItems->Add("");
					else if (Main_Days[i][CurrentNumber].get_Advent().get_Minutes() < 10)
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
					//�������� ����
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
			MessageBox::Show("� ������ ������ ��� ��������� �����������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}			
	}

	//��������� �� ��������� �����:
	System::Void Violation_Manager::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			//������ ����� �������� ������
			time_t t;
			struct tm *t_m;
			t = time(NULL);
			t_m = localtime(&t);
			int Current_Month = t_m->tm_mon;
			//� ������ ���� � ������ ��� ����������� ������:
			if (t_m->tm_mon != 0)
			{
				//���������� ����� ������� ��� ����������� ������ � ����
				int MonthFirstDay = 0;
				int MonthLastDay = 0;
				for (int i = 0; i < Current_Month - 1; i++)
				{
					if (MonthFirstDay < Current_Day - 1)
						MonthFirstDay += MonthDays[i];
				}
				//��������� ����� ���������� ��� ���������� ������ � ����
				MonthLastDay = MonthFirstDay + MonthDays[Current_Month];
				//������� ����������� ����� ������ � listview:
				int j = 0; //���������� ��� listviewitems
				for (int i = MonthFirstDay; i < MonthLastDay; i++)
				{
					//������� �������� ������� ��������� � ����� �� ��� ����
					if (CurrentNumber < Main_Days[i].size() && (strcmp(Main_Days[i][CurrentNumber].get_Attendance(), "�") == 0))
					{
						//����� ��� �������� ���:
						std::string Date = DateFromDayNumber(i, Default_Year, MonthDays, MonthDaysLeap);
						listView1->Items->Add(gcnew System::String(Date.c_str())); //�������� ���� ���������
																				   //������
						if (Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkBegin().get_Minutes().ToString());
						//����
						if (Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_WorkEnd().get_Minutes().ToString());
						//�������� ������
						if (Main_Days[i][CurrentNumber].get_Advent().get_Hour() == 0 && Main_Days[i][CurrentNumber].get_WorkBegin().get_Hour() != 0)
							listView1->Items[j]->SubItems->Add("");
						else if (Main_Days[i][CurrentNumber].get_Advent().get_Minutes() < 10)
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
						else
							listView1->Items[j]->SubItems->Add(Main_Days[i][CurrentNumber].get_Advent().get_Hour().ToString() + ":" + Main_Days[i][CurrentNumber].get_Advent().get_Minutes().ToString());
						//�������� ����
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
				MessageBox::Show("� ������ ������ ���� � ������ �� ���������� ����������� ������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
		}
		else
		{
			MessageBox::Show("� ������ ������ ��� ��������� �����������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}

	//���������� ����������:
	System::Void Violation_Manager::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->Text != "")
		{
			//������� ���������� ����� ���������� ���������� � ���������
			char* CurrentNumberChar = (char*)(void*)Marshal::StringToHGlobalAnsi(comboBox1->Text);
			unsigned int CurrentNumber = 0;
			CurrentNumberChar = (strtok(CurrentNumberChar, "."));
			CurrentNumber = atoi(CurrentNumberChar);
			if (Main_Days[Current_Day - 1].size() == 1)
				MessageBox::Show("� ������ ������ ��� ��������� ��� �������� �����������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			else
			{
				Main_Days = Dismiss_Stuff_Member(Main_Days, Current_Day, CurrentNumber);
				//������ ������ ������ ����������:
				comboBox1->Items->Clear();
				//������� ��������� ����� �������� ����������:
				for (int i = 1; i < Main_Days[Current_Day - 1].size(); i++)
				{
					std::string s1 = Main_Days[Current_Day - 1][i].get_Name();
					std::string s2 = Main_Days[Current_Day - 1][i].get_Surname();
					std::string s = ". " + s1 + " " + s2;
					String^ s_buf = marshal_as<String^>(s);
					this->comboBox1->Items->Add(Main_Days[Current_Day - 1][i].get_Number() + s_buf);
				}
				//������� ������ ��������� ����� ���������� ����������:
				for (int i = listView1->Items->Count - 1; i >= 0; i--)
				{
					listView1->Items[i]->Remove();
				}
			}
				
		}
		else
		{
			MessageBox::Show("� ������ ������ ��� ��������� �����������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}
}
