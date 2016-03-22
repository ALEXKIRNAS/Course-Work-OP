#include "Gauss�Seidel.h"
#include "Jacobi.h"
#include <stdio.h>

extern const double eps;

/******************************************
*		������� ���������� ���� �������	  *
*		������-�������					  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ �����		  *
*	n - ��������� �������				  *
******************************************/
double* GaussSeidel(double** matrix, double* free, const int& n) {

	int iter = 0;

	double* X = new double[n]; // �����, �� ������ �������� ����
	double* TempX = new double[n]; // �������� ����������
								   //�������� ���������� ��������
	for (int i = 0; i < n; i++) X[i] = free[i] / matrix[i][i];

	double norm; // �����, ��� ����������� �� �������� ������ ������� ������� � �� ������� ����������

	do {
		for (int i = 0; i < n; i++) {

			TempX[i] = free[i];

			for (int z = 0; z < i; z++) 
				TempX[i] -= matrix[i][z] * TempX[z];

			for (int z = i + 1; z < n; z++)
				TempX[i] -= matrix[i][z] * X[z];

			TempX[i] /= matrix[i][i];
		}

		norm = matrixNorm(X, TempX, n);
		for (int i = 0; i < n; i++) X[i] = TempX[i];
		iter++;

	} while (norm > eps);


	printf("Iter - %d\n", iter);
	delete[] TempX;
	return X;

}