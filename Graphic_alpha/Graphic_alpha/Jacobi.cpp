#include "DetermineCalc.h"
#include "Jacobi.h"
#include <cmath>
#include <stdio.h>

extern const double eps; // �������� ����������

/******************************************
*		������� ���������� ������� ��	  *
*		�������� ������� ��� �������  *
*		���							  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ��������� ���� �������		  *
*	n - ���������� �������				  *
******************************************/
void deleteDiagZero(double** matrix, const int& n) {
	// ��������� �����, ���� ����� �� � ������� � �������� (i, i) �������
	// �� ���������� ���� ������ (����� �������, �� �� �������� �������
	// ������� ���)
	bool* isZero = new bool[n];
	for (int i = 0; i < n; i++) isZero[i] = false;

	// �������� ���������� ��������, �� ���� ����
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
*	free - �������� ������ ������		  *
*	n - ���������� �������				  *
******************************************/
bool isSolution(double** matrix, double* free, const int& n) {
	// ���� ������� ���� ���������
	if (det(matrix, n) == 0) return false;

	// ������� ������� ���
	//deleteDiagZero(matrix, n);
	stableMatrix(matrix, free, n);

	// �������� �� ��������� ������ ����
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int z = 0; z < n; z++) sum += abs(matrix[i][z]);
		if (sum >= 2 * abs(matrix[i][i])) return false;
	}

	return true;
}

/******************************************
*		������� ���������� ���� �������	  *
*		����							  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ ������		  *
*	n - ���������� �������				  *
******************************************/
double* Jacobi(double** matrix, double* free, const int& n) {
	int iter = 0;

	double* X = new double[n]; // �����, �� ������ �������� ����
	double* TempX = new double[n]; // �������� ����������
	//��������� ���������� ��������
	for (int i = 0; i < n; i++) X[i] = free[i] / matrix[i][i];

	double norm; // �����, ��� ����������� �� �������� ������ ������� ������� � �� �������� ����������

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

		iter++;
	} while (norm > eps);

	printf("Iter - %d\n", iter);

	delete [] TempX;
	return X;
}

/******************************************
*		������� ���������� ���� �������	  *
*		����							  *
*	���������:							  *
*	matrix - ������� �������			  *
*	free - �������� ������ ������		  *
*	n - ���������� �������				  *
******************************************/
double matrixNorm(double* X, double* TempX, const int& n) {
	double norm = abs(X[0] - TempX[0]);
	for (int i = 0; i < n; i++)
		if (abs(X[i] - TempX[i]) > norm) norm = abs(X[i] - TempX[i]);

	return norm;
}


/******************************************
*		������� ���������� �������	  *
*		������� ������� �������		  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ��������� ���� �������		  *
*	free - �������� ������ ������		  *
*	n - ���������� �������				  *
******************************************/
void stableMatrix(double** matrix, double* free, const int& n) {
	int* mas = new int[n]; // ����� ���� ����� �� ����� ����� ���� ������� ����������� ������
	for (int i = 0; i < n; i++) mas[i] = 0;

	int count = 0; // ʳ������ ����������� ��������

	for (int i = 0; i < n; i++) {
		double sum = 0;
		int index = 0;
		for (int z = 0; z < n; z++) {
			sum += matrix[i][z];
			if (matrix[i][z] > matrix[i][index]) index = z;
		}

		if (sum - 2 * matrix[i][index] < 0)
			if (mas[index] != 0) {
				delete[] mas;
				return;
			}
			else {
				mas[index] = i + 1;
				count++;
			}
	}

	if (count < n) {
		delete[] mas;
		return;
	}

	double** temp = new double* [n];
	double* value = new double[n];
	for (int i = 0; i < n; i++) {
		temp[i] = matrix[mas[i] - 1];
		value[i] = free[mas[i] - 1];
	}
	for (int i = 0; i < n; i++) {
		matrix[i] = temp[i];
		free[i] = value[i];
	}

	delete[] temp;
	delete[] mas;
	delete[] value;
}