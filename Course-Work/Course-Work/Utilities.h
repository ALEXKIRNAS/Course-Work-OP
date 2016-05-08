#pragma once

namespace utilities {
	const double eps = 1e-5; // ������� ���������� �������

	// ���������, �� ����������� �������
	struct system {
		int size; // ����� �������
		double** matrix; // ������� �������
		double* free; // �������� ������ �����
	};


	double det(double**, const int&); // �������� ������� ���������� ����������
	double** matrixCut(double**, const int&, const int&); // �������� ������� �������� �������(N - 1) - �� �������
	double AlgebralAdditionCalc(double**, const int&, const int&); // �������� ������� ���������� ����������� ���������� �������� ��������
	double normCalc(double*, double*, const int&); // �������� ������� ���������� ����� ��������� ������
	bool isSemetric(const system&); // �������� ������� ������� ������� ������� �� ������������
	bool isPositive(const system&); // �������� ������� ������� ������� ������� �� �������������������
	double** cornerMinor(const system&, int); // �������� ������� ��������� �������� �����
	double* matrixMult(const system&, double*); // �������� ������� �������� ������� ������� �� ������
	double scalarMult(double*, double*, int&); // �������� ������� ���������� ������� �������
	void stableSystem(system&); // �������� ������� ��������� ������� ������� �� ���������� �������
	int indexOfMaxElement(double*, const int&);  // �������� ������� ����������� ������� ������������� �������� � �����
	double lineSumElement(double*, const int&);  // �������� ������� ����������� ���� �������� � �����
	bool isDiagDominate(const system&); // �������� ������� �������� ������� ������� �� ����������� ������
	double** CreateMatrix(int); // �������� ������� �������� ����� �� �������
	void freeMatrix(double** &, int); // �������� ������� ��������� ������� � �����
	double* CreateMas(int); // �������� ������� �������� ����� �� �����
	void freeMas(double* &); // �������� ������� ��������� ������ � �����
	void masCopy(double*, double*, int&); // �������� ������� ��������� ������
};