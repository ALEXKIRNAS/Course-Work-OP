#pragma once
#include "Utilities.h"
using utilities::system;

namespace Jacobi {
	double* Jacobi(utilities::system&); // �������� ������� ������ ������� ������� ����
	bool isSolved(utilities::system&); // �������� ������� �������� �� ��������� ������ ����
	void nextSolution(utilities::system&, double*, double *); // �������� ������� ����������� ���������� ����������
};