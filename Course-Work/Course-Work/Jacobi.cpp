#include "Jacobi.h"
using namespace Jacobi;

/******************************************
*		������� ������ ���� �������	  *
*		����							  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
double* Jacobi::Jacobi(system& sols) {
	double* x = utilities::CreateMas(sols.size);
	double* xk = utilities::CreateMas(sols.size);
	
	for (int i = 0; i < sols.size; i++) xk[i] = 0;
	double norm = 2 * utilities::eps;

	while (norm >= utilities::eps) {
		utilities::masCopy(xk, x, sols.size);
		nextSolution(sols, x, xk);
		norm = utilities::normCalc(x, xk, sols.size);
	}

	utilities::freeMas(x);
	return xk;
}

/******************************************
*		������� �������� �� ���������	  *
*		������ ����					  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
bool Jacobi::isSolved(system& sols) {
	utilities::stableSystem(sols);
	if (utilities::isDiagDominate(sols)) return true;
	else return false;
}

/******************************************
*		������� ����������� ����������	  *
*		���������� ��� ������ ����		  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
*	x - ������� ����������				  *
*	xk - ������� ����������				  *
******************************************/
void Jacobi::nextSolution(system& sols, double *x, double* xk) {
	for (int i = 0; i < sols.size; i++) {
		xk[i] = sols.free[i];
		for (int z = 0; z < sols.size; z++)
			if (i != z) xk[i] -= sols.matrix[i][z] * x[z];
		xk[i] /= sols.matrix[i][i];
	}
}