#include "Gauss–Seidel.h"
using namespace Seidel;

/******************************************
*		Функція рішення СЛАР методом	  *
*		Гауса-Зейделя					  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
double* Seidel::Seidel(utilities::system& sols) {
	double* x = utilities::CreateMas(sols.size);
	double* xk = utilities::CreateMas(sols.size);

	for (int i = 0; i < sols.size; i++) xk[i] = 0;
	double norm = 2 * utilities::eps;

	int iter = 0;

	while (norm >= utilities::eps) {
		iter++;
		utilities::masCopy(xk, x, sols.size);
		nextSolution(sols, x, xk);
		norm = utilities::normCalc(x, xk, sols.size);
	}

	utilities::freeMas(x);
	double* temp = new double[sols.size + 1];
	utilities::masCopy(xk, temp, sols.size);
	utilities::freeMas(xk);

	temp[sols.size] = iter;

	xk = temp;
	return xk;
}

/******************************************
*		Функція перевірки на сходимість	  *
*		методу Гауса-Зейделя			  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
bool Seidel::isSolved(utilities::system& sols) {
	utilities::stableSystem(sols);
	if (utilities::isDiagDominate(sols) || (utilities::isPositive(sols) && utilities::isSemetric(sols))) return true;
	else return false;
}

/******************************************
*		Функція знаходження наступного	  *
*		наближення для методу			  *
*		Гауса-Зейделя					  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
*	x - поперднє наближення				  *
*	xk - поточне наближення				  *
******************************************/
void Seidel::nextSolution(utilities::system& sols, double* x, double * xk) {
	for (int i = 0; i < sols.size; i++) {
		xk[i] = sols.free[i];
		for (int z = 0; z < i; z++) xk[i] -= sols.matrix[i][z] * xk[z];
		for (int z = i + 1; z < sols.size; z++) xk[i] -= sols.matrix[i][z] * xk[z];
		xk[i] /= sols.matrix[i][i];
	}
}