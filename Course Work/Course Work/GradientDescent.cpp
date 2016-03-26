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
	double *g = new double[n]; // ������� �������� ���䳺���
	double *gk = new double[n]; // �������� �������� ���䳺���
	double *d = new double[n]; // ������� �������� ������� �������
	double *dk = new double[n]; // �������� �������� ������� ��������
	double s; // ��������� ���� ���������

	// ������� ���������� ��������
	for (int i = 0; i < n; i++) gk[i] = g[i] = d[i] = dk[i] = xk[i] = 0;

	do {

		// Step ONE
		for (int i = 0; i < n; i++) {
			gk[i] = -free[i];
			for (int z = 0; z<n; z++)
				gk[i]+= x[z] * matrix[i][z];
		}

		// Step TWO
		double scalar1 = 0; // ���������� ������� ������� gk^T �� gk
		double scalar2 = 0;// ���������� ������� ������� g^T �� g
		for (int i = 0; i<n; i++) {
			scalar1 += gk[i] * gk[i];
			scalar2 += g[i] * g[i];
		}

		// ���������� ���������� ��������
		double alpha = scalar1 / scalar2; //���������� ����������� ������������ ��������
		for (int i = 0; i<n; i++) dk[i] = -gk[i] + alpha*d[i];

		// Step Three
		double scalar3 = 0; // ��������� ������� ������� dk �� gk
		double scalar4 = 0; // ���������� ������� dk^T * matrix * dk
		double* c = new double[n]; // ���������� ������ ��� ���������� ������� dk^T * matrix

		for (int i = 0; i < n; i++) scalar3 += dk[i] * gk[i];

		for (int i = 0; i<n; i++) {
			c[i] = 0;
			for (int z = 0; z<n; z++) c[i] += dk[i] * matrix[i][z];
		}

		for (int i = 0; i<n; i++) scalar4 += c[i] * dk[i];

		s = scalar3 / scalar4;

		// Step Four
		// ���������� ���������� ���������� 
		for (int i = 0; i<n; i++)
			xk[i] = x[i] + s*dk[i];

		// Post step
		for (int i = 0; i<n; i++) {
			d[i] = dk[i];
			g[i] = gk[i];
			x[i] = xk[i];
		}

	} while (matrixNorm(x, xk, n) > eps);

	return x;
}