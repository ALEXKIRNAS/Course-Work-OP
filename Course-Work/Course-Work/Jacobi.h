#pragma once
#include "Utilities.h"
using utilities::system;

namespace Jacobi {
	double* Jacobi(utilities::system&); // Прототип функції рішення системи методом Якобі
	bool isSolved(utilities::system&); // Прототип функції перевірки на сходимість метода Якобі
	void nextSolution(utilities::system&, double*, double *); // Прототип функції знаходження наступного наближення
};