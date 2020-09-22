#pragma once
#include "string.h"
#include "Stuff_Worker_Time.h"

class Stuff_Member
{
private:
	unsigned int Number; //Номер в списке рабочих
	char Name[20]; //Имя
	char Surname[20]; // Фамилия

	Stuff_Worker_Time WorkBegin; //Время прихода на работу по графику
	Stuff_Worker_Time WorkEnd; //Время ухода с работы по графику

	Stuff_Worker_Time Advent; //Реальное время прихода
	Stuff_Worker_Time Leave; //Реальное время ухода	
	char Attendance[4]; //Отметка посещения/непосещения
public:
	//Конструктор без параметров:
	Stuff_Member()
	{
		Number = 0;
		strcpy_s(Name, "N/A");
		strcpy_s(Surname, "N/A");

		WorkBegin.set_Hour(0);
		WorkBegin.set_Minutes(0);

		WorkEnd.set_Hour(0);
		WorkEnd.set_Minutes(0);

		Advent.set_Hour(0);
	    Advent.set_Minutes(0);

		Leave.set_Hour(0);
		Leave.set_Minutes(0);

		strcpy_s(Attendance, "N/A");
	}
	//Конструктор с параметрами:
	Stuff_Member(unsigned short Num, char* N, char* S, 
		unsigned short int H1, unsigned short int M1, unsigned short int H2, unsigned short int M2, 
		unsigned short int H3, unsigned short int M3, unsigned short int H4, unsigned short int M4, char* A)
	{
		Number = Num;
		strcpy_s(Name, N);
		strcpy_s(Surname, S);
		

		WorkBegin.set_Hour(H1);
		WorkBegin.set_Minutes(M1);

		WorkEnd.set_Hour(H2);
		WorkEnd.set_Minutes(M2);

		Advent.set_Hour(H3);
		Advent.set_Minutes(M3);

		Leave.set_Hour(H4);
		Leave.set_Minutes(M4);

		strcpy_s(Attendance, A);
	}
	//Set:
	void set_Number(unsigned int N)
	{
		Number = N;
	}
	void set_Name(char* N)
	{
		strcpy_s(Name, N);
	}
	void set_Surname(char* S)
	{
		strcpy_s(Surname, S);
	}
	void set_Attendance(char* A)
	{
		strcpy_s(Attendance, A);
	}
	void set_WorkBegin(unsigned int H, unsigned int M)
	{
		WorkBegin.set_Hour(H);
		WorkBegin.set_Minutes(M);
	}
	void set_WorkEnd(unsigned int H, unsigned int M)
	{
		WorkEnd.set_Hour(H);
		WorkEnd.set_Minutes(M);
	}
	void set_Advent(unsigned int H, unsigned int M)
	{
		Advent.set_Hour(H);
		Advent.set_Minutes(M);
	}
	void set_Leave(unsigned int H, unsigned int M)
	{
		Leave.set_Hour(H);
		Leave.set_Minutes(M);
	}
	//Get:
	unsigned int get_Number()
	{
		return Number;
	}
	char* get_Name()
	{
		return Name;
	}
	char* get_Surname()
	{
		return Surname;
	}
	char* get_Attendance()
	{
		return Attendance;
	}
	Stuff_Worker_Time get_WorkBegin()
	{
		return WorkBegin;
	}
	Stuff_Worker_Time get_WorkEnd()
	{
		return WorkEnd;
	}
	Stuff_Worker_Time get_Advent()
	{
		return Advent;
	}
	Stuff_Worker_Time get_Leave()
	{
		return Leave;
	}
	//Деструктор
	~Stuff_Member()
	{

	}
};




