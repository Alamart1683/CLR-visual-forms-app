#pragma once
class Stuff_Worker_Time
{
private:
	unsigned short int Hour : 5;
	unsigned short int Minutes : 6;

public:
	//����������� ��� ����������:
	Stuff_Worker_Time()
	{
		Hour = 0;
		Minutes = 0;
	}
	//����������� � �����������:
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
	//����������
	~Stuff_Worker_Time()
	{

	}
};

