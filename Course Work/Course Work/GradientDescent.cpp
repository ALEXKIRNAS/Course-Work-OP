#include "GradientDescent.h";
#include "DetermineCalc.h"
#include "Jacobi.h"

extern const double eps;

/******************************************
*		������� ���������� ���� �� �	  *
*		������� �����������				  *
*	���������:							  *
*	matrix - ���������� ���������		  *
*				���������				  *
*	n - ��������� �������				  *
******************************************/
bool isSemetric(double** matrix, const int& n) {
	for (int i = 0; i < n; i++)
		for (int z = i + 1; z < n; z++)
			// ���� ������� �� ����������
			if (matrix[i][z] != matrix[z][i]) return false;
	return true;
}

/******************************************
*		������� ���������� ���� �� �	  *
*		������� ������������������		  *
*	���������:							  *
*	matrix - ���������� ���������		  *
*				���������				  *
*	n - ��������� �������				  *
******************************************/
bool isPositive(double** matrix, const int& n) {
	// ����������� ������� ����������
	for (int i = 1; i <= n; i++) {

		double** cut = new double* [i]; // ������� ���� ������ i X i

		// ���������� ������� �������� �����
		for (int z = 0; z < i; z++) {
			cut[z] = new double[i];
			for (int j = 0; j < i; j++) cut[z][j] = matrix[z][j];
		}

		// ���� ��������� �������� ����� �� � ���������, �� ������� �� � ������������������
		if (det(cut, i) <= 0) return false;
	}

	return true;
}

/******************************************
*		������� ���������� ���� �������	  *
*		���䳺������ ������				  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ �����		  *
*	n - ��������� �������				  *
******************************************/
double* GradientDescent(double** matrix, double* free, const int& n) {
	double *x = new double[n]; // ������� ������ �������
	double *xk = new double[n]; // �������� ���������� ������
	double *r = new double[n]; // ������� �������� ��������
	double *rk = new double[n]; // �������� �������� ��������
	double *z = new double[n]; // ������� �������� ������� �������
	double *zk = new double[n]; // �������� �������� ������� ��������

	// ������� ���������� ��������
	for (int i = 0; i < n; i++) {
		xk[i] = 0;
		rk[i] = free[i];
		zk[i] = free[i];
	}

	do {

		// PreStep
		for (int i = 0; i < n; i++) {
			x[i] = xk[i];
			r[i] = rk[i];
			z[i] = zk[i];
		}

		// Step ONE
		double alpha = 0; // ��������� ���� ���䳺���
		double p1 = 0; // ��������� ������� ������� (r, r)
		double p2 = 0; // C�������� ������� ������� (A*z, z)

		for (int i = 0; i<n; i++) alpha += r[i] * r[i];
		for (int i = 0; i<n; i++) {
			double temp = 0;
			for (int j = 0; j<n; j++) temp += matrix[i][j] * z[j];
			p2 += temp*z[i];
		}

		alpha = p1 / p2;

		// Step TWO
		for (int i = 0; i<n; i++)
			xk[i] = x[i] + alpha * z[i];

		// Step THREE
		for (int i = 0; i<n; i++) {
			double temp = 0;
			for (int j = 0; j<n; j++) temp += matrix[i][j] * z[j];
			temp *= alpha;
			rk[i] = r[i] - temp;
		}

		// Step FOUR
		double beta = 0; // �������� �������� ��������
		double p3 = 0; // ��������� ������� (rk, rk)
		double p4 = 0; // ��������� ������� (r, r)

		for (int i = 0; i<n; i++) {
			p3 += rk[i] * rk[i];
			p4 += r[i] * r[i];
		}

		// Step FIVE
		for (int i = 0; i<n; i++) zk[i] = z[i] + beta*z[i];

	} while (matrixNorm(x, xk, n) > eps);

	return x;
}