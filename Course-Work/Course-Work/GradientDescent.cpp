#include "GradientDescent.h"
using utilities::scalarMult;
using utilities::matrixMult;


/******************************************
*		������� ������ ���� �������	  *
*		���䳺������ ������				  *
*	���������:							  *
*	sols - ������� ������� �����������  *
*		   ������						  *
******************************************/
double* GradientDescent::GradientDescent(utilities::system& sols) {
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

	int iter = 0;

	double norm = 2 * utilities::eps;
	while (norm >= utilities::eps) {
		iter++; 

		utilities::masCopy(xk, x, sols.size);
		utilities::masCopy(rk, r, sols.size);
		utilities::masCopy(zk, z, sols.size);

		double* Az = matrixMult(sols, z);

		int j;
		for (j = 0; j < sols.size; j++) if (Az[j]) break;
		if (j == sols.size) break;

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

	double* temp = new double[sols.size + 1];
	utilities::masCopy(xk, temp, sols.size);
	utilities::freeMas(xk);

	temp[sols.size] = iter;

	xk = temp;
	return xk;
}

/******************************************
*		������� �������� �� ���������	  *
*		������ ���䳺������ ������		  *
*	���������:							  *
*	sols - ������� ������� �����������  *
*		   ������						  *
******************************************/
bool GradientDescent::isSolved(utilities::system& sols) {
	return utilities::isPositive(sols) && utilities::isSemetric(sols);
}