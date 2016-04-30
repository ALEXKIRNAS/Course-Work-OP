#pragma once
#include "Utilities.h"

namespace GradientDescent {
	bool isSolved(utilities::system&); // Прототип функції перевірки на сходимість метода градієнтоного спуску
	double* GradientDescent(utilities::system&); // Прототип функції рішення системи методом градієнтоного спуску
};