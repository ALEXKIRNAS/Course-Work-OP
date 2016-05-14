#pragma once
#include <cmath>
#include "Jacobi.h"
#include "Gauss–Seidel.h"
#include "GradientDescent.h"
#include "Utilities.h"
#include "Graph.h"
#include <time.h>

#define SIZE 300
#define MSIZE 5
#define presision 1000

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^  solsSize;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::DataGridView^  dataFree;
	private: System::Windows::Forms::DataGridView^  dataRes;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rDesent;
	private: System::Windows::Forms::RadioButton^  RSeidel;
	private: System::Windows::Forms::RadioButton^  RJacobi;
	private: System::Windows::Forms::TextBox^  Info;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  BSolve;
	private: System::Windows::Forms::Button^  BClear;

	private: System::Windows::Forms::DataGridView^  dataMatrix;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->solsSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->dataFree = (gcnew System::Windows::Forms::DataGridView());
			this->dataRes = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rDesent = (gcnew System::Windows::Forms::RadioButton());
			this->RSeidel = (gcnew System::Windows::Forms::RadioButton());
			this->RJacobi = (gcnew System::Windows::Forms::RadioButton());
			this->Info = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BSolve = (gcnew System::Windows::Forms::Button());
			this->BClear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->solsSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataMatrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataFree))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataRes))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// solsSize
			// 
			this->solsSize->InterceptArrowKeys = false;
			this->solsSize->Location = System::Drawing::Point(19, 30);
			this->solsSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->solsSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->solsSize->Name = L"solsSize";
			this->solsSize->Size = System::Drawing::Size(120, 20);
			this->solsSize->TabIndex = 0;
			this->solsSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->solsSize->ValueChanged += gcnew System::EventHandler(this, &Home::solsSize_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Розмір системи";
			// 
			// dataMatrix
			// 
			this->dataMatrix->AllowUserToAddRows = false;
			this->dataMatrix->AllowUserToDeleteRows = false;
			this->dataMatrix->AllowUserToResizeColumns = false;
			this->dataMatrix->AllowUserToResizeRows = false;
			this->dataMatrix->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataMatrix->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataMatrix->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataMatrix->Location = System::Drawing::Point(12, 109);
			this->dataMatrix->MultiSelect = false;
			this->dataMatrix->Name = L"dataMatrix";
			this->dataMatrix->RowHeadersVisible = false;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			this->dataMatrix->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataMatrix->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataMatrix->Size = System::Drawing::Size(300, 303);
			this->dataMatrix->TabIndex = 2;
			this->dataMatrix->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Home::dataMatrix_CellEndEdit);
			// 
			// dataFree
			// 
			this->dataFree->AllowUserToAddRows = false;
			this->dataFree->AllowUserToDeleteRows = false;
			this->dataFree->AllowUserToResizeColumns = false;
			this->dataFree->AllowUserToResizeRows = false;
			this->dataFree->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataFree->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataFree->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataFree->ColumnHeadersVisible = false;
			this->dataFree->Location = System::Drawing::Point(363, 109);
			this->dataFree->MultiSelect = false;
			this->dataFree->Name = L"dataFree";
			this->dataFree->RowHeadersVisible = false;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			this->dataFree->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataFree->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataFree->Size = System::Drawing::Size(60, 303);
			this->dataFree->TabIndex = 3;
			this->dataFree->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Home::dataFree_CellEndEdit);
			// 
			// dataRes
			// 
			this->dataRes->AllowUserToAddRows = false;
			this->dataRes->AllowUserToDeleteRows = false;
			this->dataRes->AllowUserToResizeColumns = false;
			this->dataRes->AllowUserToResizeRows = false;
			this->dataRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataRes->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataRes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataRes->ColumnHeadersVisible = false;
			this->dataRes->Location = System::Drawing::Point(474, 109);
			this->dataRes->Name = L"dataRes";
			this->dataRes->ReadOnly = true;
			this->dataRes->RowHeadersVisible = false;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			this->dataRes->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataRes->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataRes->Size = System::Drawing::Size(90, 303);
			this->dataRes->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(297, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Матриця системи";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(329, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 46);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Стовпець вільних членів";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(471, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 38);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Рішення системи";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rDesent);
			this->groupBox1->Controls->Add(this->RSeidel);
			this->groupBox1->Controls->Add(this->RJacobi);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(585, 122);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(185, 109);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Метод рішення";
			// 
			// rDesent
			// 
			this->rDesent->AutoSize = true;
			this->rDesent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rDesent->Location = System::Drawing::Point(16, 77);
			this->rDesent->Name = L"rDesent";
			this->rDesent->Size = System::Drawing::Size(168, 22);
			this->rDesent->TabIndex = 2;
			this->rDesent->TabStop = true;
			this->rDesent->Text = L"Градієнтного спуску";
			this->rDesent->UseVisualStyleBackColor = true;
			// 
			// RSeidel
			// 
			this->RSeidel->AutoSize = true;
			this->RSeidel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RSeidel->Location = System::Drawing::Point(16, 49);
			this->RSeidel->Name = L"RSeidel";
			this->RSeidel->Size = System::Drawing::Size(131, 22);
			this->RSeidel->TabIndex = 1;
			this->RSeidel->TabStop = true;
			this->RSeidel->Text = L"Гауса-Зейделя";
			this->RSeidel->UseVisualStyleBackColor = true;
			// 
			// RJacobi
			// 
			this->RJacobi->AutoSize = true;
			this->RJacobi->Checked = true;
			this->RJacobi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RJacobi->Location = System::Drawing::Point(16, 21);
			this->RJacobi->Name = L"RJacobi";
			this->RJacobi->Size = System::Drawing::Size(66, 22);
			this->RJacobi->TabIndex = 0;
			this->RJacobi->TabStop = true;
			this->RJacobi->Text = L"Якобі";
			this->RJacobi->UseVisualStyleBackColor = true;
			// 
			// Info
			// 
			this->Info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Info->Location = System::Drawing::Point(12, 463);
			this->Info->Name = L"Info";
			this->Info->ReadOnly = true;
			this->Info->Size = System::Drawing::Size(757, 24);
			this->Info->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(9, 442);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 18);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Системна інформація";
			// 
			// BSolve
			// 
			this->BSolve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BSolve->Location = System::Drawing::Point(585, 257);
			this->BSolve->Name = L"BSolve";
			this->BSolve->Size = System::Drawing::Size(185, 35);
			this->BSolve->TabIndex = 11;
			this->BSolve->Text = L"Знайти рішення";
			this->BSolve->UseVisualStyleBackColor = true;
			this->BSolve->Click += gcnew System::EventHandler(this, &Home::BSolve_Click);
			// 
			// BClear
			// 
			this->BClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BClear->Location = System::Drawing::Point(585, 298);
			this->BClear->Name = L"BClear";
			this->BClear->Size = System::Drawing::Size(185, 35);
			this->BClear->TabIndex = 12;
			this->BClear->Text = L"Очистити вміст";
			this->BClear->UseVisualStyleBackColor = true;
			this->BClear->Click += gcnew System::EventHandler(this, &Home::BClear_Click);
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 497);
			this->Controls->Add(this->BClear);
			this->Controls->Add(this->BSolve);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Info);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataRes);
			this->Controls->Add(this->dataFree);
			this->Controls->Add(this->dataMatrix);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->solsSize);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Home";
			this->Text = L"СЛАР";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->solsSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataMatrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataFree))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataRes))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/******************************************
*	Функція виведення результату		  *
*	роботи програми у поле результату	  *
*	Параметри:							  *
*	х -  результат виконання програми	  *
******************************************/
private: void print(double* x) {
	int size = Convert::ToInt32(solsSize->Value);
	for (int i = 0; i < size; i++) dataRes->Rows[i]->Cells[0]->Value = Convert::ToString(round(x[i]*presision)/ presision);
}

/******************************************
*	Функція читання СЛАР				  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
private: void DataRead(utilities::system& sols) {
	bool flag = false;
	for (int i = 0; i < sols.size; i++)
		for (int z = 0; z < sols.size; z++) sols.matrix[i][z] = Convert::ToDouble(dataMatrix->Rows[i]->Cells[z]->Value);
	for (int i = 0; i < sols.size; i++) sols.free[i] = Convert::ToDouble(dataFree->Rows[i]->Cells[0]->Value);
}

/******************************************
*		Функція перевірки вхідних		  *
*		даних на валідність				  *
******************************************/
private: bool DataRead() {
	int size = Convert::ToInt32(solsSize->Value);
	bool flag = false;
	for (int i = 0; i < size; i++)
		for (int z = 0; z < size; z++) {
			try {
				double x = Convert::ToDouble(dataMatrix->Rows[i]->Cells[z]->Value);
				x = round(x * presision) / presision;
				dataMatrix->Rows[i]->Cells[z]->Value = Convert::ToString(x);
				dataMatrix->Rows[i]->Cells[z]->Style->BackColor = System::Drawing::Color::White;
			}
			catch (System::FormatException^ ex) {
				flag = true;
				dataMatrix->Rows[i]->Cells[z]->Style->BackColor = System::Drawing::Color::Red;
			}
		}

	for (int i = 0; i < size; i++) {
		try {
			double x = Convert::ToDouble(dataFree->Rows[i]->Cells[0]->Value);
			x = round(x * presision) / presision;
			dataFree->Rows[i]->Cells[0]->Value = Convert::ToString(x);
			dataFree->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::White;
		}
		catch (System::FormatException^ ex) {
			flag = true;
			dataFree->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::Red;
		}
	}
	return flag;
}

/******************************************
*		Функція зміни розмірів матриці	  *
*		системи,стовпця вільних членів	  * 
*		та вектора відповіді			  *
******************************************/
private: System::Void Resize() {
	int size = Convert::ToInt32(solsSize->Value);

	dataMatrix->ColumnCount = size;
	dataMatrix->RowCount = size;
	dataFree->ColumnCount = 1;
	dataFree->RowCount = size;
	dataRes->ColumnCount = 1;
	dataRes->RowCount = size;

	int t = SIZE / size;
	for (int i = 0; i < size; i++) {
		dataFree->Rows[i]->Height = t;
		dataRes->Rows[i]->Height = t;
		dataMatrix->Columns[i]->Width = t;
		dataMatrix->Rows[i]->Height = t;	
	}
	dataFree->Columns[0]->Width = SIZE / MSIZE;
	dataRes->Columns[0]->Width = 90;

}

/******************************************
*		Функція очищастки вмісту матриці  *
*		системи, стовпця вільних членів   *
*		та вектора відповіді			  *
******************************************/
private: System::Void Clear() {
	int size = Convert::ToInt32(solsSize->Value);
	for (int i = 0; i < size; i++)
		for (int z = 0; z < size; z++) dataMatrix->Rows[i]->Cells[z]->Value = "0";
	for (int i = 0; i < size; i++) {
		dataFree->Rows[i]->Cells[0]->Value = "0";
		dataRes->Rows[i]->Cells[0]->Value = "";
	}
	Info->Text = "";
	utilities::system sols;
	sols.size = size;
	sols.matrix = utilities::CreateMatrix(size);
	sols.free = utilities::CreateMas(size);
	DataRead(sols);
	utilities::freeMatrix(sols.matrix, size);
	utilities::freeMas(sols.free);
}

/******************************************
*	Функція обробкт події загрузки		  *
*	вікна програми						  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e) {
	Resize();
	Clear();
}

/******************************************
*	Функція обробки події змінення		  *
*	розміру системи						  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void solsSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	int size = Convert::ToInt32(solsSize->Value);
	int old_size = dataFree->RowCount;
	bool flag = size > dataMatrix->ColumnCount;
	Resize();
	if (flag) {
		for (int i = 0; i < size; i++)
			for (int z = old_size; z < size; z++)  dataMatrix->Rows[i]->Cells[z]->Value = "0";
		for (int i = 0; i < size; i++) 
			for (int z = old_size; z < size; z++) dataMatrix->Rows[z]->Cells[i]->Value = "0";
		for (int z = old_size; z < size; z++) dataFree->Rows[z]->Cells[0]->Value = "0";
	}
}

/******************************************
*	Функція обробка події натискання	  *
*	кнопки «Очистити вміст»				  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void BClear_Click(System::Object^  sender, System::EventArgs^  e) {
	Clear();
}

/******************************************
*	Функція обробка події зміни вмісту	  *
*	матриці системи						  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void dataMatrix_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	int size = Convert::ToInt32(solsSize->Value);
	Info->Text = "";
	if (DataRead()) {
		Info->Text = "Невірний фортмат вхідної інформації.";
		BSolve->Enabled = false;
	}
	else BSolve->Enabled = true;
		
	for (int i = 0; i < size; i++) dataRes->Rows[i]->Cells[0]->Value = "";
}

/******************************************
*	Функція обробка події зміни вмісту	  *
*	стовпця вільних членів				  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void dataFree_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	int size = Convert::ToInt32(solsSize->Value);
	Info->Text = "";
	if (DataRead()) {
		Info->Text = "Невірний фортмат вхідної інформації.";
		BSolve->Enabled = false;
	}
	else BSolve->Enabled = true;

	for (int i = 0; i < size; i++) dataRes->Rows[i]->Cells[0]->Value = "";
}

/******************************************
*	Функція обробки події натискання	  *
*	кнопки «Знайти рішення»				  *
*	Параметри:							  *
*	Посилання на відправника, додаткові   *
*	аргументи виклику					  *
******************************************/
private: System::Void BSolve_Click(System::Object^  sender, System::EventArgs^  e) {
	Info->Text = "";
	int size = Convert::ToInt32(solsSize->Value);
	for (int i = 0; i < size; i++) dataRes->Rows[i]->Cells[0]->Value = "";

	utilities::system sols;
	sols.size = size;
	sols.matrix = utilities::CreateMatrix(size);
	sols.free = utilities::CreateMas(size);

	DataRead(sols);

	if (utilities::det(sols.matrix, sols.size) == 0) {
		Info->Text = "Система вироджена (визначник системи рівний нулю).";
		utilities::freeMatrix(sols.matrix, size);
		utilities::freeMas(sols.free);
		return;
	}

	double* x;
	if (RJacobi->Checked) {
		if (!Jacobi::isSolved(sols)) {
			Info->Text = "Для даної матриці метод Якобі не сходиться.";
			utilities::freeMatrix(sols.matrix, size);
			utilities::freeMas(sols.free);
			return;
		}
		x = Jacobi::Jacobi(sols);
	}
	else if (RSeidel->Checked) {
		if (!Seidel::isSolved(sols)) {
			Info->Text = "Для даної матриці метод Гауса-Зейделя не сходиться.";
			utilities::freeMatrix(sols.matrix, size);
			utilities::freeMas(sols.free);
			return;
		}
		x = Seidel::Seidel(sols);
	}
	else {
		if (!GradientDescent::isSolved(sols)) {
			Info->Text = "Для даної матриці метод градієнтного спуску не сходиться.";
			utilities::freeMatrix(sols.matrix, size);
			utilities::freeMas(sols.free);
			return;
		}
		x = GradientDescent::GradientDescent(sols);
	}

	print(x);
	if (sols.size == 2) {
		Graph^ form = gcnew Graph(sols, x);
		form->Show();
	}

	time_t rawtime;
	struct tm * timeinfo;
	char buffer[200];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 200, "%d_%m_%Y_%H_%M_%S", timeinfo);

	if (RJacobi->Checked) strcat(buffer, "_Jacobi.txt");
	else if (RSeidel->Checked) strcat(buffer, "_Seidel.txt");
	else strcat(buffer, "_GradientDescent.txt");

	FILE* file = fopen(buffer, "wt");

	if (file == nullptr) Info->Text = "Неможливо створити вихідний файл.";
	else {
		Info->Text = "Результат успішно записаний у вихідний файл.";
		for (int i = 0; i < size; i++) fprintf(file, "%Lf\n", x[i]);
	}
	fclose(file);

	utilities::freeMatrix(sols.matrix, size);
	utilities::freeMas(sols.free);
	utilities::freeMas(x);
}
};
}
