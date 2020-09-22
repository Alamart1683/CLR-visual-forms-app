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

//��������� ���������� ��� �������� � ��������� ������ ���������
unsigned int Default_Year = 365;
unsigned int Leap_Year = 366;
unsigned short int Current_Day = 0;
unsigned short int Changed_Day = 0;
std::vector<std::vector<Stuff_Member>> Main_Days(Default_Year); //������ ���� � ������������� ���� �����������
//������� � ���������-�������� � ���-��� ���� � ���:
std::vector<int> MonthDays{ 31,28,31,30,31,30,31,31,30,31,30,31 };
std::vector<int> MonthDaysLeap{ 31,29,31,30,31,30,31,31,30,31,30,31 };

//����� ������ ��������� ������������ ������� ��������� � ���������, ���� ������� ��������� �����
namespace AMSystem
{
	System::Void Interface_Main::Interface_Main_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//������ ���� ������� ����:
		Current_Day = monthCalendar1->TodayDate.DayOfYear;
		//�������� ������ �������������� � ��������� ����� �����
		Main_Days = Load_Data(Main_Days);
		//��������� ��������� ����������� �� ������� ���, ���� ������� �������:
		Main_Days = Add_Marks(Main_Days, Current_Day);
		//��������� ������ ������� �������� ���:
		//������� ���� ������ ������ ��� ��������(�������� ��� ��������) ���:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//����� ��� ��������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					listView1->Items[i]->SubItems->Add("-");
					//����
					listView1->Items[i]->SubItems->Add("-");
					//�������� ������
					listView1->Items[i]->SubItems->Add("-");
					//�������� ����
					listView1->Items[i]->SubItems->Add("-");
					//������������
					listView1->Items[i]->SubItems->Add("��������");
				}
				else
				{
					//����� ��� �������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//����
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//�������� ������
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//�������� ����
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("���������");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("��. �������");
					}
				}
			}
		}
	}
		
	System::Void Interface_Main::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Save_Data(Main_Days);
		MessageBox::Show("������ ���� ������� ���������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	System::Void Interface_Main::button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Interface_Add^ InterfaceAdd = gcnew Interface_Add(this);
		this->Hide();
		InterfaceAdd->ShowDialog();
		this->Show();
		//������� ������� � ������� ����� ����� �������� ���������� ����������:
		//������� ������ �� ����������� ������ �������:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//��������� ������ ������� �������� ���:
		//������� ���� ������ ������ ��� ��������(�������� ��� ��������) ���:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//����� ��� ��������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					listView1->Items[i]->SubItems->Add("-");
					//����
					listView1->Items[i]->SubItems->Add("-");
					//�������� ������
					listView1->Items[i]->SubItems->Add("-");
					//�������� ����
					listView1->Items[i]->SubItems->Add("-");
					//������������
					listView1->Items[i]->SubItems->Add("��������");
				}
				else
				{
					//����� ��� �������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//����
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//�������� ������
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//�������� ����
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("���������");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("��. �������");
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
		//������� ������ � ������������ �� ������� ���� ����� ������� ����������:
		//������� ������ �� ����������� ������ �������:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//��������� ������ ������� �������� ���:
		//������� ���� ������ ������ ��� ��������(�������� ��� ��������) ���:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//����� ��� ��������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					listView1->Items[i]->SubItems->Add("-");
					//����
					listView1->Items[i]->SubItems->Add("-");
					//�������� ������
					listView1->Items[i]->SubItems->Add("-");
					//�������� ����
					listView1->Items[i]->SubItems->Add("-");
					//������������
					listView1->Items[i]->SubItems->Add("��������");
				}
				else
				{
					//����� ��� �������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//����
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//�������� ������
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//�������� ����
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("���������");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("��. �������");
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
		//������� ������� ����� ��������� ��������� ���������� ����������:
		//������� ������ �� ����������� ������ �������:
		for (int i = listView1->Items->Count - 1; i >= 0; i--)
		{
			listView1->Items[i]->Remove();
		}
		//��������� ������ ������� �������� ���:
		//������� ���� ������ ������ ��� ��������(�������� ��� ��������) ���:
		if (Main_Days[Current_Day - 1].size() != 1)
		{
			for (int i = 0; i < Main_Days[Current_Day - 1].size() - 1; i++)
			{
				if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
					&& Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
				{
					//����� ��� ��������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					listView1->Items[i]->SubItems->Add("-");
					//����
					listView1->Items[i]->SubItems->Add("-");
					//�������� ������
					listView1->Items[i]->SubItems->Add("-");
					//�������� ����
					listView1->Items[i]->SubItems->Add("-");
					//������������
					listView1->Items[i]->SubItems->Add("��������");
				}
				else
				{
					//����� ��� �������� ���:
					listView1->Items->Add(Main_Days[Current_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Name()));
					listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Current_Day - 1][i + 1].get_Surname()));
					//������
					if (Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
					//����
					if (Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
					//�������� ������
					if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
					//�������� ����
					if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Current_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
						listView1->Items[i]->SubItems->Add("");
					else if (Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
					else
						listView1->Items[i]->SubItems->Add(Main_Days[Current_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Current_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

					if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("���������");
					}
					else if (strcmp(Main_Days[Current_Day - 1][i + 1].get_Attendance(), "�") == 0)
					{
						listView1->Items[i]->SubItems->Add("��. �������");
					}
				}
			}
		}
	}

	System::Void Interface_Main::monthCalendar1_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e)
	{
			//������� ����� ������ ��� ������� �� ���� � ���� � ������ ������ ���� �� ���������:
			Changed_Day = monthCalendar1->SelectionStart.DayOfYear;
			//������� ������ �� ����������� ������ �������:
			for (int i = listView1->Items->Count - 1; i >= 0; i--)
			{
				listView1->Items[i]->Remove();
			}
			//��������� ����� �������:
			Main_Days = Add_Marks(Main_Days, Current_Day);
			//������� ������� ������ �������:
			if (Main_Days[Changed_Day - 1].size() != 1)
			{
				for (int i = 0; i < Main_Days[Changed_Day - 1].size() - 1; i++)
				{
					if (Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes() == 0
						&& Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes() == 0)
					{
						//����� ��� ��������� ���:
						listView1->Items->Add(Main_Days[Changed_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Name()));
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Surname()));
						//������
						listView1->Items[i]->SubItems->Add("-");
						//����
						listView1->Items[i]->SubItems->Add("-");
						//�������� ������
						listView1->Items[i]->SubItems->Add("-");
						//�������� ����
						listView1->Items[i]->SubItems->Add("-");
						//������������
						listView1->Items[i]->SubItems->Add("��������");
					}
					else
					{
						//����� ��� �������� ���:
						listView1->Items->Add(Main_Days[Changed_Day - 1][i + 1].get_Number().ToString()); //�������� ���� ����� � ������ �������, ����� ��������������� ����������� ������ ���� ���������� ������
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Name()));
						listView1->Items[i]->SubItems->Add(gcnew System::String(Main_Days[Changed_Day - 1][i + 1].get_Surname()));
						//������
						if (Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Minutes().ToString());
						//����
						if (Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Minutes().ToString());
						//�������� ������
						if (Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkBegin().get_Hour() != 0)
							listView1->Items[i]->SubItems->Add("");
						else if (Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_Advent().get_Minutes().ToString());
						//�������� ����
						if (Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour() == 0 && Main_Days[Changed_Day - 1][i + 1].get_WorkEnd().get_Hour() != 0)
							listView1->Items[i]->SubItems->Add("");
						else if (Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes() < 10)
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + "0" + Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes().ToString());
						else
							listView1->Items[i]->SubItems->Add(Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Hour().ToString() + ":" + Main_Days[Changed_Day - 1][i + 1].get_Leave().get_Minutes().ToString());

						if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "�") == 0)
						{
							listView1->Items[i]->SubItems->Add("");
						}
						else if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "�") == 0)
						{
							listView1->Items[i]->SubItems->Add("���������");
						}
						else if (strcmp(Main_Days[Changed_Day - 1][i + 1].get_Attendance(), "�") == 0)
						{
							listView1->Items[i]->SubItems->Add("��. �������");
						}
					}
				}
			}		
		}
}