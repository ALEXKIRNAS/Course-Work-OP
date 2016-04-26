#pragma once

namespace Graphic_alpha {

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
		Graph(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  GraphChart;
	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->GraphChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphChart))->BeginInit();
			this->SuspendLayout();
			// 
			// GraphChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->GraphChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->GraphChart->Legends->Add(legend1);
			this->GraphChart->Location = System::Drawing::Point(0, 1);
			this->GraphChart->Name = L"GraphChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->LegendText = L"бЫРа-1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->LegendText = L"бЫРа-2";
			series2->Name = L"Series2";
			this->GraphChart->Series->Add(series1);
			this->GraphChart->Series->Add(series2);
			this->GraphChart->Size = System::Drawing::Size(377, 245);
			this->GraphChart->TabIndex = 0;
			this->GraphChart->Text = L"chart1";
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 247);
			this->Controls->Add(this->GraphChart);
			this->Name = L"Graph";
			this->Text = L"Graph";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphChart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: void Build(void) {
		
	}

	};
}
