#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include "string.h"
#include "Stuff_Member.h"
#include <conio.h>
#include <time.h>
using namespace System::Runtime::InteropServices;

//Прототипы:
std::vector<std::vector<Stuff_Member>> Load_Data(std::vector<std::vector<Stuff_Member>> Main_Days);
std::vector<std::vector<Stuff_Member>> Create_Empty_Data(std::vector<std::vector<Stuff_Member>> Main_Days);
std::vector<std::string> String_Split(std::vector<std::string> v_Worker, std::string s_Worker);
void Save_Data(std::vector<std::vector<Stuff_Member>> Main_Days);
std::vector<std::vector<Stuff_Member>> Add_Stuff_Member(std::vector<std::vector<Stuff_Member>> Main_Days, System::String^ N, System::String^ S, System::String^ W_B, System::String^ W_E, unsigned int Day_Of_Week, unsigned int Current_Day);
Stuff_Worker_Time Add_Time(char* Time, Stuff_Worker_Time W_Time);
std::vector<std::vector<Stuff_Member>> Add_Marks(std::vector<std::vector<Stuff_Member>> Main_Days, unsigned int Current_Day);
std::string DateFromDayNumber(int DayNumber, int Year, std::vector<int> MonthDays, std::vector<int> MonthDaysLeap);
std::vector<std::vector<Stuff_Member>> Dismiss_Stuff_Member(std::vector<std::vector<Stuff_Member>> Main_Days, unsigned int Current_Day, unsigned int Current_Number);