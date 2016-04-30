#pragma once
#include "Utilities.h"
#include <algorithm>


namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Graph
	/// </summary>
	public ref class Graph : public System::Windows::Forms::Form
	{
	public:
		Graph(utilities::system& sols, double* x)
		{
			InitializeComponent(sols, x);
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Graph()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  CGraph;
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
		void InitializeComponent(utilities::system& sols, double* x)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->CGraph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CGraph))->BeginInit();
			this->SuspendLayout();
			// 
			// CGraph
			// 
			chartArea1->Name = L"ChartArea1";
			this->CGraph->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->CGraph->Legends->Add(legend1);
			this->CGraph->Location = System::Drawing::Point(0, 0);
			this->CGraph->Name = L"CGraph";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Система-1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Система-2";
			series2->Name = L"Series2";
			this->CGraph->Series->Add(series1);
			this->CGraph->Series->Add(series2);
			this->CGraph->Size = System::Drawing::Size(784, 562);
			this->CGraph->TabIndex = 0;
			this->CGraph->Text = L"chart1";
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->CGraph);
			this->Name = L"Graph";
			this->Text = L"Графік";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CGraph))->EndInit();
			this->ResumeLayout(false);


			double xl = x[0] - 10;
			double xr = x[0] + 10;
			double yl = x[1] - 10;
			double yr = x[1] + 10;

			if (sols.matrix[0][1] != 0) {
				yl = std::min(yl, (sols.free[0] - sols.matrix[0][0] * xl) / sols.matrix[0][1]);
				yr = std::max(yr, (sols.free[0] - sols.matrix[0][0] * xr) / sols.matrix[0][1]);
			}

			if (sols.matrix[1][1] != 0) {
				yl = std::min(yl, (sols.free[1] - sols.matrix[1][0] * xl) / sols.matrix[1][1]);
				yr = std::max(yr, (sols.free[1] - sols.matrix[1][0] * xr) / sols.matrix[1][1]);
			}

			chartArea1->AxisX->ScaleView->Zoom(xl, xr);
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->AxisX->ScaleView->Zoomable = true;
			chartArea1->AxisX->Title = "X";

			chartArea1->AxisY->ScaleView->Zoom(yl, yr);
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->AxisY->ScaleView->Zoomable = true;
			chartArea1->AxisY->Title = "Y";

			if(sols.matrix[0][1] != 0)
				for (double i = xl; i <= xr; i += 0.1) series1->Points->AddXY(i, (sols.free[0] - sols.matrix[0][0] * i) / sols.matrix[0][1]);
			else for (double i = yl; i <= yr; i += 0.1) series1->Points->AddXY(sols.free[0] / sols.matrix[0][0], i);

			if (sols.matrix[1][1] != 0)
				for (double i = xl; i <= xr; i += 0.1) series2->Points->AddXY(i, (sols.free[1] - sols.matrix[1][0] * i) / sols.matrix[1][1]);
			else for (double i = yl; i <= yr; i += 0.1) series2->Points->AddXY(sols.free[1] / sols.matrix[1][0], i);
		}
#pragma endregion
	};
}
