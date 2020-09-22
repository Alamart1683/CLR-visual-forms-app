#include "Interface_Add.h"

namespace AMSystem
{
	System::Void Interface_Add::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//� 2018 ���� 1 ������ - ��, ������������� ��� ������ ����� ���������� ������ �� 1 �� 7 ������ � ��� �����	
		if ((textBox1->Text != "") && (textBox2->Text != "") //������� ��������� �������
			&&
			//1-� ������� ��� ��������� ������ ���������� �������� ���
			!(comboBox1->Text == "" && comboBox2->Text == "" && comboBox3->Text == "" && comboBox4->Text == "" && comboBox5->Text == "" &&
				comboBox6->Text == "" && comboBox7->Text == "" && comboBox8->Text == "" && comboBox9->Text == "" && comboBox10->Text == "" &&
				comboBox11->Text == "" && comboBox12->Text == "" && comboBox13->Text == "" && comboBox14->Text == "")
			&&
			//2-� ������� ��� ������� ������ ���������� �������� ���
			!((comboBox1->Text != "" && comboBox2->Text == "") || (comboBox1->Text == "" && comboBox2->Text != "") ||
			(comboBox3->Text != "" && comboBox4->Text == "") || (comboBox3->Text == "" && comboBox4->Text != "") ||
			(comboBox5->Text != "" && comboBox6->Text == "") || (comboBox5->Text == "" && comboBox6->Text != "") ||
			(comboBox7->Text != "" && comboBox8->Text == "") || (comboBox7->Text == "" && comboBox8->Text != "") ||
			(comboBox9->Text != "" && comboBox10->Text == "") || (comboBox9->Text == "" && comboBox10->Text != "") ||
			(comboBox11->Text != "" && comboBox12->Text == "") || (comboBox11->Text == "" && comboBox12->Text != "") ||
			(comboBox13->Text != "" && comboBox14->Text == "") || (comboBox13->Text == "" && comboBox14->Text != "")
			))
		{	
			//��������������� ��� ������� ��� ������ ������� ���� ������� ���������� ���������:
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox1->Text, comboBox2->Text, 1, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox3->Text, comboBox4->Text, 2, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox5->Text, comboBox6->Text, 3, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox7->Text, comboBox8->Text, 4, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox9->Text, comboBox10->Text, 5, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox11->Text, comboBox12->Text, 6, Current_Day);
			//��:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox13->Text, comboBox14->Text, 7, Current_Day);

			//������� ���� �����:
			textBox1->Text = "";
			textBox2->Text = "";
			
			MessageBox::Show("��������� ��� ������� ���������������!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else
		{
			MessageBox::Show("��� ���������� ���������� ���������� ����������� ������� ��� ��� � �������, � ��� �� ������ ������ � ������� ���, ������� ������ ���� ��� ������� ����!", "������ �����!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	
	}
}