#pragma once
#include "Utilities.h"
using utilities::system;

namespace GradientDescent {
	bool isSolved(system&); // Прототип функції перевірки на сходимість метода градієнтоного спуску
	double* GradientDescent(system&); // Прототип функції рішення системи методом градієнтоного спуску
};