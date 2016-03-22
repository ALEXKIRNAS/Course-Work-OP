#include "DetermineCalc.h"
#include "Jacobi.h"
#include <cmath>

const double eps = 1e-5; // ������� ����������

/******************************************
*		������� ���������� ������� ��	  *
*		������� ������� ��� ������  *
*		���							  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ��������� ���� �������		  *
*	n - ��������� �������				  *
******************************************/
void deleteDiagZero(double** matrix, const int& n) {
	// ��������� �����, ���� ����� �� � ������� � �������� (i, i) �������
	// �� ���������� ���� ������ (����� �������, �� �� ������� �������
	// ������ ���)
	bool* isZero = new bool[n];
	for (int i = 0; i < n; i++) isZero[i] = false;

	// �������� ��������� ��������, �� ��� ����
	for (int i = 0; i < n; i++) if (matrix[i][i] == 0) isZero[i] = true;

	// �������� ������ �������� ������� �� �������� 
	for (int i = 0; i < n; i++)
		if (isZero[i] == true)
			for (int z = 0; z < n; z++)
				if (matrix[z][i] != 0) {
					for (int j = 0; j < n; j++) matrix[i][j] += matrix[z][j];
					break;
				}

	delete [] isZero;
}

/******************************************
*		������� �������� �� ���������	  *
*		������ ����					  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ��������� ��������� 		  *
*	n - ��������� �������				  *
******************************************/
bool isSolution(double** matrix, const int& n) {
	// ���� ������� ���� ���������
	if (det(matrix, n) == 0) return false;

	// ������� ������� ���
	deleteDiagZero(matrix, n);


	// ��������� ������� �������� ��������� ������ ����
	double** B = new double*[n];
	for (int i = 0; i < n; i++) B[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int z = 0; z < n; z++)
			if (i == z) B[i][z] = 0;
			else B[i][z] = matrix[i][z] / matrix[i][i];

	// �������� �� ��������� ������ ����
	if (abs(det(B, n)) < 1) return true;
	else return false;
}

/******************************************
*		������� ���������� ���� �������	  *
*		����							  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ �����		  *
*	n - ��������� �������				  *
******************************************/
double* Jacobi(double** matrix, double* free, const int& n) {
	double* X = new double[n]; // �����, �� ������ �������� ����
	double* TempX = new double[n]; // �������� ����������
	//�������� ���������� ��������
	for (int i = 0; i < n; i++) X[i] = free[i] / matrix[i][i];

	double norm; // �����, ��� ����������� �� �������� ������ ������� ������� � �� ������� ����������

	do {
		for (int i = 0; i < n; i++) {
			TempX[i] = free[i];
			for (int z = 0; z < n; z++)
				if (i != z)
					TempX[i] -= matrix[i][z] * X[z];
			TempX[i] /= matrix[i][i];
		}

		norm = matrixNorm(X, TempX, n);
		for (int i = 0; i < n; i++) X[i] = TempX[i];

	} while (norm > eps);

	delete [] TempX;
	return X;
}

/******************************************
*		������� ���������� ���� �������	  *
*		����							  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ �����		  *
*	n - ��������� �������				  *
******************************************/
double matrixNorm(double* X, double* TempX, const int& n) {
	double norm = abs(X[0] - TempX[0]);
	for (int i = 0; i < n; i++)
		if (abs(X[i] - TempX[i]) > norm) norm = abs(X[0] - TempX[0]);

	return norm;
}