#pragma once
#include "Utilities.h"

namespace GradientDescent {
	bool isSolved(utilities::system&); // �������� ������� �������� �� ��������� ������ ���䳺������� ������
	double* GradientDescent(utilities::system&); // �������� ������� ������ ������� ������� ���䳺������� ������
};