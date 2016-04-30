#pragma once
#include "Utilities.h"

namespace Seidel {
	double* Seidel(utilities::system&); // Прототип функції рішення системи методом Гауса-Зейделя
	bool isSolved(utilities::system&); // Прототип функції перевірки на сходимість метода Гауса-Зейделя
	void nextSolution(utilities::system&, double*, double *); // Прототип функції знаходження наступного наближення
};