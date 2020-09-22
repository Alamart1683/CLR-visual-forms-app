#include "Sub_Programs.h"

//��������� ������:
std::vector<std::vector<Stuff_Member>> Load_Data(std::vector<std::vector<Stuff_Member>> Main_Days)
{
	char Worker_Controller[10];
	int i = -1;
	std::ifstream fin;
	std::stringstream ss_Worker;
	std::string s_Worker;
	fin.open("AMS_Data.txt");
	if (!fin.is_open())
	{
		std::ofstream ofs("AMS_Data.txt");
		Main_Days = Create_Empty_Data(Main_Days);
		Save_Data(Main_Days);
		ofs.close();
		return Main_Days;
	}
	while (true)
	{
		int Worker_Controller_Count = 0;
		while (i + 1 <= Main_Days.size())
		{
			getline(fin, s_Worker);
			ss_Worker.str(s_Worker);
			ss_Worker >> Worker_Controller;

			if (strcmp(Worker_Controller, "Workers,") == 0)
				Worker_Controller_Count++;
			if (Worker_Controller_Count == 1)
			{
				i++;
				break;
			}
			else
			{
				//������ ��� ����������� ����� �� ������ �����
				std::vector<std::string> v_Worker;
				//��������� ���������� ������� ���������
				v_Worker = String_Split(v_Worker, s_Worker);
				//�������� ��� �� �����
				char* Temp_Name = new char[v_Worker[1].size() + 1];
				std::copy(v_Worker[1].begin(), v_Worker[1].end(), Temp_Name);
				Temp_Name[v_Worker[1].size()] = '\0';
				//�������� ������� �� �����
				char* Temp_Surname = new char[v_Worker[2].size() + 1];
				std::copy(v_Worker[2].begin(), v_Worker[2].end(), Temp_Surname);
				Temp_Surname[v_Worker[2].size()] = '\0';
				//�������� ������� �� �����
				char* Temp_Attendance = new char[v_Worker[11].size() + 1];
				std::copy(v_Worker[11].begin(), v_Worker[11].end(), Temp_Attendance);
				Temp_Attendance[v_Worker[11].size()] = '\0';
				//�������� �������� ��������� ������ Stuff_Member, ��������� ����������� � ����������� � ������ �� �����
				Stuff_Member S_M = Stuff_Member
				(
					std::atoi(v_Worker[0].c_str()),
					Temp_Name, //���
					Temp_Surname, //�������
					std::atoi(v_Worker[3].c_str()), std::atoi(v_Worker[4].c_str()), //������ ������ �� �������
					std::atoi(v_Worker[5].c_str()), std::atoi(v_Worker[6].c_str()), //����� ������ �� �������
					std::atoi(v_Worker[7].c_str()), std::atoi(v_Worker[8].c_str()), //�������� ������
					std::atoi(v_Worker[9].c_str()), std::atoi(v_Worker[10].c_str()), //�������� ����
					Temp_Attendance //�������
				);
				Main_Days[i].push_back(S_M);
				delete[] Temp_Name;
				delete[] Temp_Surname;
				delete[] Temp_Attendance;
			}
		}
		//����� �� ����� �������� ������� �������
		if (i == 365)
		{
			fin.close();
			return Main_Days;
			break;
		}
	}
}

//����������� ������� �����:
std::vector<std::vector<Stuff_Member>> Create_Empty_Data(std::vector<std::vector<Stuff_Member>> Main_Days)
{
	Stuff_Member S_F = Stuff_Member();
	for (int i = 0; i < Main_Days.size(); i++)
	{
		Main_Days[i].push_back(S_F);
	}
	return Main_Days;
}

//������� ������ ����� �� �������:
std::vector<std::string> String_Split(std::vector<std::string> v_Worker, std::string s_Worker)
{
	//������� ������ � ������ ���
	char* s_Temp = new char[s_Worker.size() + 1];
	std::copy(s_Worker.begin(), s_Worker.end(), s_Temp);
	s_Temp[s_Worker.size()] = '\0';
	//����������, � ������� ����� ���������� ��������� ������ ������ ������
	char *s_Pointer;
	//��������� ������ ����� ������
	s_Pointer = strtok(s_Temp, " ");
	//��������� ����������� ������
	while (s_Pointer != NULL)
	{
		v_Worker.push_back(s_Pointer);
		s_Pointer = strtok(NULL, " ");
	}
	return v_Worker;
}

//��������� ������:
void Save_Data(std::vector<std::vector<Stuff_Member>> Main_Days)
{
	std::ofstream fout("AMS_Data.txt");
	if (!fout.is_open())
	{
		std::ofstream ofs("AMS_Data.txt");
		ofs.close();
	}
	for (int i = 0; i < Main_Days.size(); i++)
	{
		fout << "Workers," << " Day: " << i + 1 << std::endl;
		for (int j = 0; j < Main_Days[i].size(); j++)
		{
			fout //������ ��� � ������� ������� �������������� ��� ������ �����, ��� ������ ������ - ���� �������� � ��� ������
				<< Main_Days[i][j].get_Number() << " "
				<< Main_Days[i][j].get_Name() << " "
				<< Main_Days[i][j].get_Surname() << " "
				<< Main_Days[i][j].get_WorkBegin().get_Hour() << " " << Main_Days[i][j].get_WorkBegin().get_Minutes() << " "
				<< Main_Days[i][j].get_WorkEnd().get_Hour() << " " << Main_Days[i][j].get_WorkEnd().get_Minutes() << " "
				<< Main_Days[i][j].get_Advent().get_Hour() << " " << Main_Days[i][j].get_Advent().get_Minutes() << " "
				<< Main_Days[i][j].get_Leave().get_Hour() << " " << Main_Days[i][j].get_Leave().get_Minutes() << " "
				<< Main_Days[i][j].get_Attendance() << std::endl;
		}
	}
	fout << "Workers, the end of year." << std::endl;
	fout.close();
}

//�������� ����������:
std::vector<std::vector<Stuff_Member>> Add_Stuff_Member(std::vector<std::vector<Stuff_Member>> Main_Days, System::String^ N, System::String^ S, System::String^ W_B, System::String^ W_E, unsigned int Day_Of_Week, unsigned int Current_Day)
{
	//�������������� ����� �����
	char* Name = (char*)(void*)Marshal::StringToHGlobalAnsi(N);
	char* Surname = (char*)(void*)Marshal::StringToHGlobalAnsi(S);
	char* Work_Begin = (char*)(void*)Marshal::StringToHGlobalAnsi(W_B);
	char* Work_End = (char*)(void*)Marshal::StringToHGlobalAnsi(W_E);
	//������� �����
	Stuff_Worker_Time W_B_Time;
	Stuff_Worker_Time W_E_Time;
	if (!((W_B == "") || (W_E == ""))) //������� ��������� �������
	{
		W_B_Time = Add_Time(Work_Begin, W_B_Time);
		W_E_Time = Add_Time(Work_End, W_E_Time);
	}
	else
	{
		W_B_Time.set_Hour(0);
		W_B_Time.set_Minutes(0);

		W_E_Time.set_Hour(0);
		W_E_Time.set_Minutes(0);

	}
    
	//������� � ���� ��������� ������ ���������� ��������� � ���� ���� ������ ������� �� ��� ���������� � �� ����� ����:
	//�������� �������� ��� ������������ ������������:
	if ((W_B != "") && (W_E != ""))
	{
		for (int i = Day_Of_Week - 1; i < Main_Days.size(); i += 7)
		{
			//�������� ��������� ������ ���������, ���� �������� ���������� ������, ����������� ����������� � �����������:
			Stuff_Member S_F = Stuff_Member(Main_Days[i].size(), Name, Surname, W_B_Time.get_Hour(), W_B_Time.get_Minutes(), W_E_Time.get_Hour(), W_E_Time.get_Minutes(), 0, 0, 0, 0, "N/A");
			if (i >= /*Current_Day - 1*/ 90)
			{
				Main_Days[i].push_back(S_F);
			}
		}
	}
	//�������� ������ ��� �������� ����� ������ ��������� ������������ � ����������� ��� ������ ��������:
	else if ((W_B == "") || (W_E == ""))
	{
		for (int i = Day_Of_Week - 1; i < Main_Days.size(); i += 7)
		{
			//�������� ��������� ������ ���������, ���� �������� ���������� ������, ����������� ����������� � �����������:
			Stuff_Member S_F = Stuff_Member(Main_Days[i].size(), Name, Surname, 0, 0, 0, 0, 0, 0, 0, 0, "N/A");
			if (i >= /*Current_Day - 1*/ 90)
			{
				Main_Days[i].push_back(S_F);
			}
		}
	}
	
	return Main_Days;
}

//�������� �����:
Stuff_Worker_Time Add_Time(char* Time, Stuff_Worker_Time W_Time)
{
	char *s_Pointer;
	std::vector<unsigned short int> Time_Buffer;
	//��������� ������ �� ������  � ����� �� � ����� � ����������� �����
	s_Pointer = strtok(Time, ":");
	while (s_Pointer != NULL)
	{
		Time_Buffer.push_back(atoi(s_Pointer));
		s_Pointer = strtok(NULL, ":");
	}
	//������� �� ������ � ���� ������
	W_Time.set_Hour(Time_Buffer[0]);
	W_Time.set_Minutes(Time_Buffer[1]);

	return W_Time;
}

//���������� �������:
std::vector<std::vector<Stuff_Member>> Add_Marks(std::vector<std::vector<Stuff_Member>> Main_Days, unsigned int Current_Day)
{
	for (int i = 0; i < Main_Days.size(); i++)
	{
		for (int j = 0; j < Main_Days[i].size(); j++)
		{
			if ((i < Current_Day - 1) &&
				(Main_Days[i][j].get_Advent().get_Hour() + Main_Days[i][j].get_Advent().get_Minutes()) != 0 &&
				(Main_Days[i][j].get_Leave().get_Hour() + Main_Days[i][j].get_Leave().get_Minutes()) == 0)
			{
				Main_Days[i][j].set_Leave(23, 59); //��������� ����� �������� �����������, �� ������, ���� ��������� �� ���� � ������ ���, ��� 23:59
			}
			else if (Main_Days[i][j].get_WorkBegin().get_Hour() == 0 && Main_Days[i][j].get_WorkBegin().get_Minutes() == 0
				&& Main_Days[i][j].get_WorkEnd().get_Hour() == 0 && Main_Days[i][j].get_WorkEnd().get_Minutes() == 0)
			{
				Main_Days[i][j].set_Attendance("�");
			}
			else if ((i < Current_Day - 1) &&
				(((Main_Days[i][j].get_WorkBegin().get_Hour() < Main_Days[i][j].get_Advent().get_Hour()) || 
				((Main_Days[i][j].get_WorkBegin().get_Minutes() < Main_Days[i][j].get_Advent().get_Minutes()) && (Main_Days[i][j].get_WorkBegin().get_Hour() == Main_Days[i][j].get_Advent().get_Hour()))) ||
					((Main_Days[i][j].get_WorkEnd().get_Hour() > Main_Days[i][j].get_Leave().get_Hour()) ||
				((Main_Days[i][j].get_WorkEnd().get_Minutes() > Main_Days[i][j].get_Leave().get_Minutes()) && (Main_Days[i][j].get_WorkEnd().get_Hour() == Main_Days[i][j].get_Leave().get_Hour()))) &&
				(strcmp(Main_Days[i][j].get_Attendance(), "�") != 0)))
			{
				Main_Days[i][j].set_Attendance("�");
			}
		}
	}
	return Main_Days;
}

//�������� ���� �� ������ ���:
std::string DateFromDayNumber(int DayNumber, int Year, std::vector<int> MonthDays, std::vector<int> MonthDaysLeap)
{
	//������� �����
	time_t t;
	struct tm *t_m;
	t = time(NULL);
	t_m = localtime(&t);
	//���������� ���� ��� ��������� ������ ��� � ������
	int FullCountOfDays = 0;
	//����� ��� � ������
	int DayNumberInMonth = 0;
	//����� ������
	int NumberOfMonth = 0;
	//����� ����
	int NumberOfYear = t_m->tm_year + 1900;
	//�������� ����
	std::string Date;
	std::string Day, Month, SYear;
	//�� ������ �������� ����:
	if (Year == 365)
	{
		for (int i = 0; i < t_m->tm_mon; i++)
		{
			FullCountOfDays += MonthDays[i];
			NumberOfMonth++;	 
		}
		//�������� ����� ��� � ������
		DayNumberInMonth = DayNumber - FullCountOfDays;
		//����������� ��� � ������:
		Day = std::to_string(DayNumberInMonth + 1);
		Month = std::to_string(NumberOfMonth + 1);
		SYear = std::to_string(NumberOfYear);
		if (DayNumberInMonth < 10 && NumberOfMonth < 10)
		{
			Date = "0" + Day + ".0" + Month + "." + SYear;
		}
		else if (NumberOfMonth < 10)
		{
			Date = Day + ".0" + Month + "." + SYear;
		}
		else if (DayNumberInMonth < 10)
		{
			Date = "0" + Day + "." + Month + "." + SYear;
		}
		else
		{
			Date = Day + "." + Month + "." + SYear;
		}		
	}
	//�� ������ ����������� ����
	else
	{
		for (int i = 0; i < t_m->tm_mon; i++)
		{
			FullCountOfDays += MonthDaysLeap[i];
			NumberOfMonth++;
		}
		//�������� ����� ��� � ������
		DayNumberInMonth = DayNumber - FullCountOfDays;
		//����������� ��� � ������:
		Day = std::to_string(DayNumberInMonth + 1);
		Month = std::to_string(NumberOfMonth + 1);
		SYear = std::to_string(NumberOfYear);
		if (DayNumberInMonth < 10 && NumberOfMonth < 10)
		{
			Date = "0" + Day + ".0" + Month + "." + SYear;
		}
		else if (NumberOfMonth < 10)
		{
			Date = Day + ".0" + Month + "." + SYear;
		}
		else if (DayNumberInMonth < 10)
		{
			Date = "0" + Day + "." + Month + "." + SYear;
		}
		else
		{
			Date = Day + "." + Month + "." + SYear;
		}
	}
	
	return Date;
}

//������� ����������, ������ ��� ������ �� �������:
std::vector<std::vector<Stuff_Member>> Dismiss_Stuff_Member(std::vector<std::vector<Stuff_Member>> Main_Days, unsigned int Current_Day, unsigned int Current_Number)
{
	for (int i = 0; i < Main_Days.size(); i++)
	{
		if (Current_Number < Main_Days[i].size())
		{
			Main_Days[i].erase(Main_Days[i].begin() + Current_Number);
			for (int j = Current_Number; j < Main_Days[i].size(); j++)
			{
				//�������� ������ ����������� � ������ �� �������:
				if (j >= Current_Number)
				{
					Main_Days[i][j].set_Number(Main_Days[i][j].get_Number() - 1);
				}

			}
		}
			
	}

	return Main_Days;
}