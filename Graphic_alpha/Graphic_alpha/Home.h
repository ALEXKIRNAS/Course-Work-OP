#pragma once
#include "DetermineCalc.h"
#include "Gauss–Seidel.h"
#include "Jacobi.h"
#include "GradientDescent.h"
#include "Graph.h"

extern const double eps = 1e-5;

namespace Graphic_alpha {

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
	private: System::Windows::Forms::NumericUpDown^  matrixSize;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  matrix;
	private: System::Windows::Forms::DataGridView^  free;
	private: System::Windows::Forms::DataGridView^  solution;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  Gradient_ch;


	private: System::Windows::Forms::RadioButton^  Seidel_ch;

	private: System::Windows::Forms::RadioButton^  Jacobi_ch;

	private: System::Windows::Forms::Button^  Solve;
	private: System::Windows::Forms::TextBox^  OutputInfo;
	private: System::Windows::Forms::Label^  label5;


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
			this->matrixSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->matrix = (gcnew System::Windows::Forms::DataGridView());
			this->free = (gcnew System::Windows::Forms::DataGridView());
			this->solution = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Gradient_ch = (gcnew System::Windows::Forms::RadioButton());
			this->Seidel_ch = (gcnew System::Windows::Forms::RadioButton());
			this->Jacobi_ch = (gcnew System::Windows::Forms::RadioButton());
			this->Solve = (gcnew System::Windows::Forms::Button());
			this->OutputInfo = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->free))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->solution))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// matrixSize
			// 
			this->matrixSize->Location = System::Drawing::Point(12, 29);
			this->matrixSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->matrixSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->matrixSize->Name = L"matrixSize";
			this->matrixSize->ReadOnly = true;
			this->matrixSize->Size = System::Drawing::Size(90, 20);
			this->matrixSize->TabIndex = 0;
			this->matrixSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->matrixSize->ValueChanged += gcnew System::EventHandler(this, &Home::matrixSize_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Розмір системи";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// matrix
			// 
			this->matrix->AllowUserToAddRows = false;
			this->matrix->AllowUserToDeleteRows = false;
			this->matrix->AllowUserToResizeColumns = false;
			this->matrix->AllowUserToResizeRows = false;
			this->matrix->BackgroundColor = System::Drawing::Color::LightGray;
			this->matrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrix->ColumnHeadersVisible = false;
			this->matrix->Location = System::Drawing::Point(12, 79);
			this->matrix->Name = L"matrix";
			this->matrix->RowHeadersVisible = false;
			this->matrix->Size = System::Drawing::Size(240, 150);
			this->matrix->TabIndex = 2;
			// 
			// free
			// 
			this->free->AllowUserToAddRows = false;
			this->free->AllowUserToDeleteRows = false;
			this->free->AllowUserToResizeColumns = false;
			this->free->AllowUserToResizeRows = false;
			this->free->BackgroundColor = System::Drawing::Color::LightGray;
			this->free->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->free->ColumnHeadersVisible = false;
			this->free->Location = System::Drawing::Point(258, 79);
			this->free->Name = L"free";
			this->free->RowHeadersVisible = false;
			this->free->Size = System::Drawing::Size(85, 150);
			this->free->TabIndex = 3;
			// 
			// solution
			// 
			this->solution->AllowUserToAddRows = false;
			this->solution->AllowUserToDeleteRows = false;
			this->solution->AllowUserToResizeColumns = false;
			this->solution->AllowUserToResizeRows = false;
			this->solution->BackgroundColor = System::Drawing::Color::LightGray;
			this->solution->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->solution->ColumnHeadersVisible = false;
			this->solution->Location = System::Drawing::Point(349, 79);
			this->solution->Name = L"solution";
			this->solution->ReadOnly = true;
			this->solution->RowHeadersVisible = false;
			this->solution->Size = System::Drawing::Size(78, 150);
			this->solution->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(16, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(236, 23);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Матриця системи";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(258, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 44);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Стовпець вільних членів";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(349, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 18);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Рішення";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Gradient_ch);
			this->groupBox1->Controls->Add(this->Seidel_ch);
			this->groupBox1->Controls->Add(this->Jacobi_ch);
			this->groupBox1->Location = System::Drawing::Point(264, 248);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(147, 102);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Метод";
			// 
			// Gradient_ch
			// 
			this->Gradient_ch->AutoSize = true;
			this->Gradient_ch->Location = System::Drawing::Point(11, 69);
			this->Gradient_ch->Name = L"Gradient_ch";
			this->Gradient_ch->Size = System::Drawing::Size(128, 17);
			this->Gradient_ch->TabIndex = 2;
			this->Gradient_ch->Text = L"Градієнтного спуску";
			this->Gradient_ch->UseVisualStyleBackColor = true;
			// 
			// Seidel_ch
			// 
			this->Seidel_ch->AutoSize = true;
			this->Seidel_ch->Location = System::Drawing::Point(11, 46);
			this->Seidel_ch->Name = L"Seidel_ch";
			this->Seidel_ch->Size = System::Drawing::Size(100, 17);
			this->Seidel_ch->TabIndex = 1;
			this->Seidel_ch->TabStop = true;
			this->Seidel_ch->Text = L"Гауса-Зейделя";
			this->Seidel_ch->UseVisualStyleBackColor = true;
			// 
			// Jacobi_ch
			// 
			this->Jacobi_ch->AutoSize = true;
			this->Jacobi_ch->Checked = true;
			this->Jacobi_ch->Location = System::Drawing::Point(11, 23);
			this->Jacobi_ch->Name = L"Jacobi_ch";
			this->Jacobi_ch->Size = System::Drawing::Size(53, 17);
			this->Jacobi_ch->TabIndex = 0;
			this->Jacobi_ch->TabStop = true;
			this->Jacobi_ch->Text = L"Якобі";
			this->Jacobi_ch->UseVisualStyleBackColor = true;
			// 
			// Solve
			// 
			this->Solve->Location = System::Drawing::Point(12, 248);
			this->Solve->Name = L"Solve";
			this->Solve->Size = System::Drawing::Size(121, 29);
			this->Solve->TabIndex = 9;
			this->Solve->Text = L"Рішити систему";
			this->Solve->UseVisualStyleBackColor = true;
			this->Solve->Click += gcnew System::EventHandler(this, &Home::Solve_Click);
			// 
			// OutputInfo
			// 
			this->OutputInfo->Location = System::Drawing::Point(12, 330);
			this->OutputInfo->Name = L"OutputInfo";
			this->OutputInfo->ReadOnly = true;
			this->OutputInfo->Size = System::Drawing::Size(226, 20);
			this->OutputInfo->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 310);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Системна інформація";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(439, 366);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->OutputInfo);
			this->Controls->Add(this->Solve);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->solution);
			this->Controls->Add(this->free);
			this->Controls->Add(this->matrix);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->matrixSize);
			this->Name = L"Home";
			this->Text = L"СЛАР";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->free))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->solution))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void matrixScan(double** Matrix, double* Free, int& size) {
		for (int i = 0; i < size; i++)
			for (int z = 0; z < size; z++)
				Matrix[i][z] = Convert::ToDouble(matrix->Rows[i]->Cells[z]->Value);

		for (int i = 0; i < size; i++) Free[i] = Convert::ToDouble(free->Rows[i]->Cells[0]->Value);
	}

	private: void clear(void) {
		int size = Convert::ToInt32(matrixSize->Value);
		for (int i = 0; i < size; i++)
			for (int z = 0; z < size; z++)
				matrix->Rows[i]->Cells[z]->Value = Convert::ToString(0);

		for (int i = 0; i < size; i++) {
			free->Rows[i]->Cells[0]->Value = Convert::ToString(0);
			solution->Rows[i]->Cells[0]->Value = Convert::ToString(0);
		}
	}
	
	private: void Answer(double* mas, int& size) {
		for (int i = 0; i < size; i++)
			solution->Rows[i]->Cells[0]->Value = Convert::ToString(mas[i]);
	}

	private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e) {
		int size = Convert::ToInt32(matrixSize->Value);

		matrix->RowCount = size;
		matrix->ColumnCount = size;
		matrix->AutoResizeColumns();
		matrix->AutoResizeRows();

		free->RowCount = size;
		free->ColumnCount = 1;
		free->AutoResizeRows();
		free->AutoResizeColumns();

		solution->RowCount = size;
		solution->ColumnCount = 1;
		solution->AutoResizeRows();
		solution->AutoResizeColumns();
		clear();
	}

	private: System::Void matrixSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		int size = Convert::ToInt32(matrixSize->Value);

		matrix->RowCount = size;
		matrix->ColumnCount = size;
		matrix->AutoResizeColumns();
		matrix->AutoResizeRows();

		free->RowCount = size;
		free->ColumnCount = 1;
		free->AutoResizeRows();
		free->AutoResizeColumns();

		solution->RowCount = size;
		solution->ColumnCount = 1;
		solution->AutoResizeRows();
		solution->AutoResizeColumns();
	}

	private: System::Void Solve_Click(System::Object^  sender, System::EventArgs^  e) {
		OutputInfo->Text = "";

		int size = Convert::ToInt32(matrixSize->Value);
		double** Matrix = new double*[size];
		double* Free = new double[size];
		for (int i = 0; i < size; i++) Matrix[i] = new double[size];

		matrixScan(Matrix, Free, size);

		if (det(Matrix, size) == 0) {
			OutputInfo->Text = "Визначник системи дорівнює нулю.";
			return;
		}

		double* x = new double[size];

		if (Jacobi_ch->Checked == true) {
			if (isSolution(Matrix, Free, size) == false) {
				OutputInfo->Text = "Для даної матриці метод не сходиться.";
				return;
			}

			x = Jacobi(Matrix, Free, size);
		}
		else if (Seidel_ch->Checked == true) {
			if (isSolution(Matrix, Free, size) == false || (!isPositive(Matrix, size) && isSemetric(Matrix, size))) {
				OutputInfo->Text = "Для даної матриці метод не сходиться.";
				return;
			}

			x = GaussSeidel(Matrix, Free, size);
		}
		else {
			if (!(isPositive(Matrix, size) && isSemetric(Matrix, size))) {
				OutputInfo->Text = "Для даної матриці метод не сходиться.";
				return;
			}

			x = GradientDescent(Matrix, Free, size);
		}

		Answer(x, size);
		solution->AutoResizeRows();
		solution->AutoResizeColumns();

		if (size == 2) {
			Graph^ Form = gcnew Graph(x, Free, Matrix);
			Form->Show();
		}

		delete[] Free;
		for (int i = 0; i < size; i++) delete[] Matrix[i];
		delete[] Matrix;
	}
};
}
