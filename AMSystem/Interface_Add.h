#pragma once
#include <windows.h>
#include "Sub_Programs.h"
#include "Interface_Main.h"

namespace AMSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

   
	/// <summary>
	/// Сводка для Interface_Add
	/// </summary>
	public ref class Interface_Add : public System::Windows::Forms::Form
	{
	public:
		Interface_Add(Interface_Main^ parent)
		{
			InitializeComponent();
			parentForm = parent;
		}

	private: Interface_Main^ parentForm;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Interface_Add()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel2;
	protected:

	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox10;
	private: System::Windows::Forms::ComboBox^  comboBox9;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox14;
	private: System::Windows::Forms::ComboBox^  comboBox13;
	private: System::Windows::Forms::ComboBox^  comboBox12;
	private: System::Windows::Forms::ComboBox^  comboBox11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface_Add::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->comboBox14 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::DarkCyan;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->comboBox14);
			this->panel2->Controls->Add(this->comboBox13);
			this->panel2->Controls->Add(this->comboBox12);
			this->panel2->Controls->Add(this->comboBox11);
			this->panel2->Controls->Add(this->comboBox10);
			this->panel2->Controls->Add(this->comboBox9);
			this->panel2->Controls->Add(this->comboBox8);
			this->panel2->Controls->Add(this->comboBox7);
			this->panel2->Controls->Add(this->comboBox6);
			this->panel2->Controls->Add(this->comboBox5);
			this->panel2->Controls->Add(this->comboBox4);
			this->panel2->Controls->Add(this->comboBox3);
			this->panel2->Controls->Add(this->comboBox2);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Location = System::Drawing::Point(132, 33);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(776, 59);
			this->panel2->TabIndex = 5;
			// 
			// comboBox14
			// 
			this->comboBox14->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox14->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox14->FormattingEnabled = true;
			this->comboBox14->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox14->Location = System::Drawing::Point(678, 30);
			this->comboBox14->Name = L"comboBox14";
			this->comboBox14->Size = System::Drawing::Size(87, 21);
			this->comboBox14->TabIndex = 24;
			// 
			// comboBox13
			// 
			this->comboBox13->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox13->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox13->FormattingEnabled = true;
			this->comboBox13->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox13->Location = System::Drawing::Point(678, 3);
			this->comboBox13->Name = L"comboBox13";
			this->comboBox13->Size = System::Drawing::Size(87, 21);
			this->comboBox13->TabIndex = 23;
			// 
			// comboBox12
			// 
			this->comboBox12->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox12->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox12->FormattingEnabled = true;
			this->comboBox12->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox12->Location = System::Drawing::Point(585, 30);
			this->comboBox12->Name = L"comboBox12";
			this->comboBox12->Size = System::Drawing::Size(87, 21);
			this->comboBox12->TabIndex = 22;
			// 
			// comboBox11
			// 
			this->comboBox11->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox11->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox11->Location = System::Drawing::Point(585, 3);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(87, 21);
			this->comboBox11->TabIndex = 21;
			// 
			// comboBox10
			// 
			this->comboBox10->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox10->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox10->Location = System::Drawing::Point(492, 30);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(87, 21);
			this->comboBox10->TabIndex = 20;
			// 
			// comboBox9
			// 
			this->comboBox9->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox9->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox9->Location = System::Drawing::Point(492, 3);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(87, 21);
			this->comboBox9->TabIndex = 19;
			// 
			// comboBox8
			// 
			this->comboBox8->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox8->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox8->Location = System::Drawing::Point(399, 30);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(87, 21);
			this->comboBox8->TabIndex = 18;
			// 
			// comboBox7
			// 
			this->comboBox7->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox7->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox7->Location = System::Drawing::Point(399, 3);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(87, 21);
			this->comboBox7->TabIndex = 17;
			// 
			// comboBox6
			// 
			this->comboBox6->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox6->Location = System::Drawing::Point(306, 30);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(87, 21);
			this->comboBox6->TabIndex = 16;
			// 
			// comboBox5
			// 
			this->comboBox5->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox5->Location = System::Drawing::Point(306, 3);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(87, 21);
			this->comboBox5->TabIndex = 15;
			// 
			// comboBox4
			// 
			this->comboBox4->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox4->Location = System::Drawing::Point(213, 30);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(87, 21);
			this->comboBox4->TabIndex = 14;
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox3->Location = System::Drawing::Point(213, 3);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(87, 21);
			this->comboBox3->TabIndex = 13;
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"13:00", L"13:30", L"14:00", L"14:30", L"15:00",
					L"15:30", L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30",
					L"22:00", L"22:30", L"23:00"
			});
			this->comboBox2->Location = System::Drawing::Point(120, 30);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(87, 21);
			this->comboBox2->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(3, 33);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(94, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Конец работы:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(3, 6);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(101, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Начало работы:";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::LightCyan;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				L"0:30", L"1:00", L"1:30", L"2:00", L"2:30", L"3:00",
					L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30", L"10:00",
					L"10:30", L"11:00", L"11:30", L"12:00"
			});
			this->comboBox1->Location = System::Drawing::Point(120, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(87, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Имя:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Фамилия:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightCyan;
			this->textBox1->Location = System::Drawing::Point(12, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LightCyan;
			this->textBox2->Location = System::Drawing::Point(12, 72);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(250, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"ПН:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(343, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(27, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"ВТ:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(436, 17);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"СР:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(529, 17);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"ЧТ:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(622, 17);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(28, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"ПТ:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cyan;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(896, 44);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Зарегистрировать сотрудника в ситеме";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Interface_Add::button1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(720, 17);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"CБ:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(808, 17);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(27, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"ВС:";
			// 
			// Interface_Add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Aquamarine;
			this->ClientSize = System::Drawing::Size(920, 149);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Interface_Add";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавление сотрудника";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
};
}
