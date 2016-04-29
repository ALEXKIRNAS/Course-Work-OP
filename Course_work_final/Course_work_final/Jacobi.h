#pragma once
#include "Utilities.h"
using utilities::system;

namespace Jacobi {
	double* Jacobi(system&); // �������� ������� ������ ������� ������� ����
	bool isSolved(system&); // �������� ������� �������� �� ��������� ������ ����
	void nextSolution(system&, double*, double *); // �������� ������� ����������� ���������� ����������
};