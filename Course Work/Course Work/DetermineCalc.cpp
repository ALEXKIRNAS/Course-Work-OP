#include "DetermineCalc.h"

/******************************************
*		������� ���������� ����������	  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ���������� ���������			  *
*	n - ���������� �������				  *
******************************************/
int det(int** matrix, int n){
	int determine = 0; // ��������� ������� matrix

	// ���� ���������� ������� ������ �� �������
	if (n != 1) {
		// ��, ���������� ��������� ���������� �� ������ �������� (�� ���� ����������� ��������� �� 1-�� �����)
		for (int z = 0; z < n; z++) 
			determine += AlgebralAdditionCalc(matrix, n, z) * matrix[0][z];
	}
	// ������ ��������� ��������� ������� 1�1
	else return **matrix;

	return determine;
}

/******************************************
*		������� ���������� ������������  *
*		���������� �������� ��������	  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ���������� ����				  *
*	n - ���������� �������				  *
*	y - ����� ������� ��������, ���		  *
*		����� ������� ����������		  *
*		���������� ����				  *
******************************************/
int AlgebralAdditionCalc(int** matrix, const int& n, const int& y) {
	int** mas = matrixCut(matrix, n, y);
	int ans = det(mas, n - 1) * (y & 1 ? -1 : 1); // ����� ��� ���������� ������

	// ������� ������
	for (int i = 0; i < n - 1; i++) delete[] mas[i];
	delete[] mas;

	return ans;
}

/******************************************
*		�������  �������� �������		  *
*		(N-1)-�� �������				  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ���������� ����				  *
*	n - ���������� �������				  *
*	y - ����� ������� ��������, ���		  *
*		����� ������� ����������		  *
*		���������� ����				  *
******************************************/
int** matrixCut(int** matrix, const int& n, const int& y) {

	// C�������� ���� �������
	int** newMatrix = new int*[n - 1];
	for (int i = 0; i < n - 1; i++) newMatrix[i] = new int[n - 1];

	int index = 0; // ���������� ������ �������� � ������� newMatrix

	// ���������� �������
	for (int i = 1; i < n; i++)
		for (int z = 0; z < n; z++)
			if (z == y) continue;
			else {
				newMatrix[index / (n - 1)][index % (n - 1)] = matrix[i][z];
				index++;
			}

	return newMatrix;
}