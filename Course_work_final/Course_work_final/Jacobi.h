#pragma once
#include "Utilities.h"
using utilities::system;

namespace Jacobi {
	double* Jacobi(system&); // Прототип функції рішення системи метод Якобі
	bool isSolved(system&); // Прототип функції перевірки на сходимість метода Якобі
	void nextSolution(system&, double*, double *); // Прототип функції знаходження наступного наближення
};