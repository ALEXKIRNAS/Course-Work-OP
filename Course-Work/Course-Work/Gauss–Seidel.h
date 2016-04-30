#pragma once
#include "Utilities.h"

namespace Seidel {
	double* Seidel(utilities::system&); // �������� ������� ������ ������� ������� �����-�������
	bool isSolved(utilities::system&); // �������� ������� �������� �� ��������� ������ �����-�������
	void nextSolution(utilities::system&, double*, double *); // �������� ������� ����������� ���������� ����������
};