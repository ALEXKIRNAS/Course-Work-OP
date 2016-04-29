#include "GradientDescent.h"
using utilities::scalarMult;
using utilities::matrixMult;


/******************************************
*		������� ������ ���� �������	  *
*		���䳺������ ������				  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
double* GradientDescent::GradientDescent(system& sols) {
	double* x = utilities::CreateMas(sols.size); // ������� ������ �������
	double* xk = utilities::CreateMas(sols.size); // �������� ���������� ������
	double* r = utilities::CreateMas(sols.size); // ������� �������� ��������
	double* rk = utilities::CreateMas(sols.size); // �������� �������� ��������
	double* z = utilities::CreateMas(sols.size); // ������� �������� ������� �������
	double* zk = utilities::CreateMas(sols.size);// �������� �������� ������� ��������

	// ������� ���������� ��������
	for (int i = 0; i < sols.size; i++) {
		xk[i] = 0;
		rk[i] = sols.free[i];
		zk[i] = sols.free[i];
	}

	double norm = 2 * utilities::eps;
	while (norm >= utilities::eps) {

		utilities::masCopy(xk, x, sols.size);
		utilities::masCopy(rk, r, sols.size);
		utilities::masCopy(zk, z, sols.size);

		double* Az = matrixMult(sols, z);
		double alpha = scalarMult(r, r, sols.size) / scalarMult(Az, z, sols.size) ; // ��������� ���� ���䳺���

		for (int i = 0; i < sols.size; i++) xk[i] += alpha * z[i];
		for (int i = 0; i < sols.size; i++) rk[i] -= alpha * Az[i];
	
		double beta = scalarMult(rk, rk, sols.size) / scalarMult(r, r, sols.size); // �������� �������� ��������
		
		utilities::masCopy(rk, zk, sols.size);
		for (int i = 0; i < sols.size; i++) zk[i] += beta * z[i];

		utilities::freeMas(Az);

		norm = utilities::normCalc(x, xk, sols.size);
	}

	utilities::freeMas(x);
	utilities::freeMas(r);
	utilities::freeMas(rk);
	utilities::freeMas(z);
	utilities::freeMas(zk);

	return xk;
}

/******************************************
*		������� �������� �� ���������	  *
*		������ ���䳺������ ������		  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
bool GradientDescent::isSolved(system& sols) {
	return utilities::isPositive(sols) && utilities::isSemetric(sols);
}