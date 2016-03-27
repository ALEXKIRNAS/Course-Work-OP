#pragma once
void deleteDiagZero(double**, const int&); // �������� �������, �� ���� ������� �� ������� ������� ��� ������ ���
bool isSolution(double**, const int&); // �������� �������, �� �������� �� ��������� ����� ����
double* Jacobi(double**, double*, const int&); // �������� ������� �������� ���� ������� ����
double matrixNorm(double*, double*, const int&); // �������� ������� ���������� ����� ������
void stableMatrix(double**, const int&); // �������� �������, �� ������� �������