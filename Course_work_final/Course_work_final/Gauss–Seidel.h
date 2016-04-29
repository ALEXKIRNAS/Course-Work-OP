#pragma once
#include "Utilities.h"
using utilities::system;

namespace Seidel {
	double* Seidel(system&); // Прототип функції рішення системи методом Гауса-Зейделя
	bool isSolved(system&); // Прототип функції перевірки на сходимість метода Гауса-Зейделя
	void nextSolution(system&, double*, double *); // Прототип функції знаходження наступного наближення
};