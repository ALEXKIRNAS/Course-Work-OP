#pragma once
#include "Utilities.h"
using utilities::system;

namespace Seidel {
	double* Seidel(system&); // �������� ������� ������ ������� ������� �����-�������
	bool isSolved(system&); // �������� ������� �������� �� ��������� ������ �����-�������
	void nextSolution(system&, double*, double *); // �������� ������� ����������� ���������� ����������
};