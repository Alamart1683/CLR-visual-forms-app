#pragma once
class Stuff_Worker_Time
{
private:
	unsigned short int Hour : 5;
	unsigned short int Minutes : 6;

public:
	//Конструктор без параметров:
	Stuff_Worker_Time()
	{
		Hour = 0;
		Minutes = 0;
	}
	//Конструктор с параметрами:
	Stuff_Worker_Time(unsigned short int H, unsigned short int M)
	{
		Hour = H;
		Minutes = M;
	}
	//Set:
	void set_Hour(unsigned short int H)
	{
		Hour = H;
	}
	void set_Minutes(unsigned short int M)
	{
		Minutes = M;
	}
	//Get:
	unsigned short int get_Hour()
	{
		return Hour;
	}
	unsigned short int get_Minutes()
	{
		return Minutes;
	}
	//Деструктор
	~Stuff_Worker_Time()
	{

	}
};

