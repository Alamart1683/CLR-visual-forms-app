#include "Interface_Add.h"

namespace AMSystem
{
	System::Void Interface_Add::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//В 2018 году 1 января - ПН, следовательно дни недели имеют порядковые номера от 1 до 7 января и так далее	
		if ((textBox1->Text != "") && (textBox2->Text != "") //Условие введенных фамилий
			&&
			//1-е условие как мининимум одного выбранного рабочего дня
			!(comboBox1->Text == "" && comboBox2->Text == "" && comboBox3->Text == "" && comboBox4->Text == "" && comboBox5->Text == "" &&
				comboBox6->Text == "" && comboBox7->Text == "" && comboBox8->Text == "" && comboBox9->Text == "" && comboBox10->Text == "" &&
				comboBox11->Text == "" && comboBox12->Text == "" && comboBox13->Text == "" && comboBox14->Text == "")
			&&
			//2-е условие как минимум одного выбранного рабочего дня
			!((comboBox1->Text != "" && comboBox2->Text == "") || (comboBox1->Text == "" && comboBox2->Text != "") ||
			(comboBox3->Text != "" && comboBox4->Text == "") || (comboBox3->Text == "" && comboBox4->Text != "") ||
			(comboBox5->Text != "" && comboBox6->Text == "") || (comboBox5->Text == "" && comboBox6->Text != "") ||
			(comboBox7->Text != "" && comboBox8->Text == "") || (comboBox7->Text == "" && comboBox8->Text != "") ||
			(comboBox9->Text != "" && comboBox10->Text == "") || (comboBox9->Text == "" && comboBox10->Text != "") ||
			(comboBox11->Text != "" && comboBox12->Text == "") || (comboBox11->Text == "" && comboBox12->Text != "") ||
			(comboBox13->Text != "" && comboBox14->Text == "") || (comboBox13->Text == "" && comboBox14->Text != "")
			))
		{	
			//Последовательно для каждого дня недели вызовем нашу функцию добавления работника:
			//ПН:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox1->Text, comboBox2->Text, 1, Current_Day);
			//ВТ:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox3->Text, comboBox4->Text, 2, Current_Day);
			//СР:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox5->Text, comboBox6->Text, 3, Current_Day);
			//ЧТ:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox7->Text, comboBox8->Text, 4, Current_Day);
			//ПТ:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox9->Text, comboBox10->Text, 5, Current_Day);
			//СБ:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox11->Text, comboBox12->Text, 6, Current_Day);
			//ВС:
			Main_Days = Add_Stuff_Member(Main_Days, textBox1->Text, textBox2->Text, comboBox13->Text, comboBox14->Text, 7, Current_Day);

			//Очистим поля ввода:
			textBox1->Text = "";
			textBox2->Text = "";
			
			MessageBox::Show("Сотрудник был успешно зарегистрирован!", "", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else
		{
			MessageBox::Show("Для добавление сотрудника необходимо обязательно указать его имя и фамилию, а так же график работы в рабочие дни, которых должно быть как минимум один!", "Ошибка ввода!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	
	}
}