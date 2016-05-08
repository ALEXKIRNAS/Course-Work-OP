#include "Utilities.h"
#include <cmath>
using namespace utilities;

/******************************************
*		������� ���������� ����������	  *
*		�������							  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*			 ���������� ���������		  *
*	size - ��������� �������			  *
******************************************/
double utilities::det(double** matrix, const int& size) {
	//���� ��������� ������� ��������, �� ��������� ��������� ������� 1�1
	if (size == 1)  return **matrix;
	else {
		// ���������� ���������� ������� ��������� �� ������ ��������
		double detRes = 0; // ��������� ������� �������
		for (int i = 0; i < size; i++) detRes += AlgebralAdditionCalc(matrix, size, i) * matrix[i][0];
		return detRes;
	}
}

/******************************************
*		�������  �������� �������		  *
*		(N-1)-�� �������				  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		     ����� ����				  *
*	size - ��������� �������			  *
*	y - ����� ����� ��������, ���		  *
*		����� ������� ����������		  *
*	    ����							  *
******************************************/
double** utilities::matrixCut(double** matrix, const int& size, const int& y) {
	int elementCount = 0; // ʳ������ �������� � �������� �������
	// C�������� ���� �������
	double** newMatrix = CreateMatrix(size - 1);

	// ���������� �������
	for (int i = 0; i < size; i++)
		for (int z = 1; z < size; z++)
			if (i != y) {
				newMatrix[elementCount / (size - 1)][elementCount % (size - 1)] = matrix[i][z];
				elementCount++;
			}

	return newMatrix;
}

/******************************************
*		������� ���������� ������������  *
*		���������� �������� ��������	  *
*	���������:							  *
*	matrix - ������� ��� ��� �������	  *
*		  ������ ���������� ����������	  *
*	size - ��������� �������			  *
*	y - ����� ����� ��������, ���		  *
*		����� ������� ����������		  *
*		���������� ����				  *
******************************************/
double utilities::AlgebralAdditionCalc(double** matrix, const int& size, const int& y) {
	double** newMatrix = matrixCut(matrix, size, y);
	double result = det(newMatrix, size-1) * (y & 1 ? -1 : 1); // ���������� ����������

	freeMatrix(newMatrix, size - 1);
	return result;
}

/******************************************
*		������� ���������� �����		  *
*		��������� ����������			  *
*	���������:							  *
*	� - ������� ���������� 			  *
*	�k - �������  ����������			  *
*	size - ��������� ������			  *
******************************************/
double utilities::normCalc(double* x, double* xk, const int& size) {
	double norm = abs(*x - *xk);
	for (int i = 1; i < size; i++)
		if (abs(x[i] - xk[i]) > norm) norm = abs(x[i] - xk[i]);
	return norm;
}


/******************************************
*		������� �������� �������		  *
*		������� �� ������������		  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
bool utilities::isSemetric(const system& sols) {
	for (int i = 0; i < sols.size; i++)
		for (int z = i; z < sols.size; z++)
			if (sols.matrix[i][z] != sols.matrix[z][i]) return false;
	return true;
}

/******************************************
*		������� �������� �������		  *
*		������� �� �������������������	  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
bool utilities::isPositive(const system& sols) {
	// ����������� ������� ����������
	for (int i = 1; i <= sols.size; i++) {
		double** newMatrix = cornerMinor(sols, i);

		// ���� ��������� �������� ����� �� � ���������, �� ������� �� � ������������������
		if (det(newMatrix, i) <= 0) return false;
		freeMatrix(newMatrix, i);
	}

	return true;
}

/******************************************
*		������� ��������� ��������		  *
*		����� �������					  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
*	size - ��������� �������� �����	  *
******************************************/
double** utilities::cornerMinor(const system& sols, int size) {
	double** newMatrix = CreateMatrix(size);
	for (int i = 0; i < size; i++)
		for (int z = 0; z < size; z++)
			newMatrix[i][z] = sols.matrix[i][z];
	return newMatrix;
}

/******************************************
*		������� �������� ������� ��		  *
*		������							  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
*	mas - ������, �� ���� ��������� ����  *
******************************************/
double* utilities::matrixMult(const system& sols, double* mas) {
	double* newVector = CreateMas(sols.size);
	for (int i = 0; i < sols.size; i++) {
		newVector[i] = 0;
		for (int z = 0; z < sols.size; z++) newVector[i] += mas[z] * sols.matrix[i][z];
	}
	return newVector;
}

/******************************************
*		������� ����������� ����������	  *
*		������� �������				  *
*	���������:							  *
*	vector1 - ������ �������			  *
*	vector2 - ������ ������				  *	
*	size - ��������� ������			  *
******************************************/
double utilities::scalarMult(double* vector1, double* vector2, int& size) {
	double scalar = 0;
	for (int i = 0; i < size; i++) scalar += vector1[i] * vector2[i];
	return scalar;
}

/******************************************
*		������� ���������� �������	  *
*		������� ������� �������		  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
void utilities::stableSystem(system& sols) {
	// ����� ���� ����� �� ����� ����� ���� ������� ����������� ������
	int* mas = new int[sols.size];
	for (int i = 0; i < sols.size; i++) mas[i] = -1;

	for (int i = 0; i < sols.size; i++) {
		int index = indexOfMaxElement(sols.matrix[i], sols.size);
		double sum = lineSumElement(sols.matrix[i], sols.size);

		if (sum >= abs(2 * sols.matrix[i][index])) {
			delete[] mas;
			return;
		}

		if(mas[index] != -1){
			delete[] mas;
			return;
		}

		mas[index] = i;
	}

	system newSols;
	newSols.size = sols.size;
	newSols.matrix = CreateMatrix(sols.size);
	newSols.free = CreateMas(sols.size);

	for (int i = 0; i < sols.size; i++) {
		newSols.free[i] = sols.free[mas[i]];
		for (int z = 0; z < sols.size; z++) newSols.matrix[i][z] = sols.matrix[mas[i]][z];
	}

	freeMatrix(sols.matrix, sols.size);
	freeMas(sols.free);

	sols = newSols;
	delete[] mas;
}

/******************************************
*		�������  �����������			  *
*		������������� �� ����������		  *
*		�������� �������� � ���������	  *
*		�����							  *
*	���������:							  *
*	mas - �������� �����				  *
*	size - ������� �������� � �����	  *
******************************************/
int utilities::indexOfMaxElement(double* mas, const int& size) {
	int index = 0; // ������ ������������� ��������
	for (int i = 1; i < size; i++) if (abs(mas[i]) >  abs(mas[index])) index = i;
	return index;
}

/******************************************
*		�������  �����������			  *
*		���� ���������� ��������		  *
*		�������� � ���������			  *
*		�����							  *
*	���������:							  *
*	mas - �������� �����				  *
*	size - ������� �������� � �����	  *
******************************************/
double utilities::lineSumElement(double* mas, const int& size) {
	double sum = 0; // ���� ��������
	for (int i = 0; i < size; i++) sum += abs(mas[i]);
	return sum;
}

/******************************************
*		������� �������� ������� ������� *
*		�� ����������� ������			  *
*	���������:							  *
*	sols - ������� ������ �����������  *
*		   ������						  *
******************************************/
bool utilities::isDiagDominate(const system& sols) {
	for (int i = 0; i < sols.size; i++) {
		double sum = lineSumElement(sols.matrix[i], sols.size);
		if (sum >= abs(2 * sols.matrix[i][i])) return false;
	}
	return true;
}

/******************************************
*		������� �������� ��������	  *
*		����� �� �������				  *
*	���������:							  *
*	size - ��������� �������			  *
******************************************/
double** utilities::CreateMatrix(int size) {
	double** matrix = new double*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new double[size];
	return matrix;
}

/******************************************
*		������� ��������� �������		  *
*	���������:							  *
*	matrix - �������, ��� ���������		  *
*			 ��������					  *
*	size - ��������� �������			  *
******************************************/
void utilities::freeMatrix(double** & matrix, int size) {
	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
}

/******************************************
*		������� �������� ��������	  *
*		����� �� �����				  *
*	���������:							  *
*	size - ��������� ������			  *
******************************************/
double* utilities::CreateMas(int size) {
	double* mas = new double [size];
	return mas;
}

/******************************************
*		������� ��������� ������		  *
*	���������:							  *
*	mas - �����, ���� ���������			  *
*			 ��������					  *
******************************************/
void utilities::freeMas(double* & mas) {
	delete[] mas;
	mas = nullptr;
}

/******************************************
*		������� ��������� ������		  *
*	���������:							  *
*	scr - �����, ���� ������� ��������  *
*	dist - �����, � ���� �������		  *
*		   ��������					  *
*	size - ��������� ������			  *
******************************************/
void utilities::masCopy(double* src, double* dist, int& size) {
	for (int i = 0; i < size; i++) dist[i] = src[i];
}