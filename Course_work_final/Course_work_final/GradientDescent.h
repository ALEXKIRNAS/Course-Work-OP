#pragma once
#include "Utilities.h"
using utilities::system;

namespace GradientDescent {
	bool isSolved(system&); // �������� ������� �������� �� ��������� ������ ���䳺������� ������
	double* GradientDescent(system&); // �������� ������� ������ ������� ������� ���䳺������� ������
};