#include "DetermineCalc.h"
#include "Jacobi.h"
#include "Gauss–Seidel.h"
#include "GradientDescent.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

extern const double eps = 1e-5; // Наближення з яким шукаються корні

int main(void) {
	DWORD startTime = GetTickCount();

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;

	scanf("%d", &n);
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++) matrix[i] = new double[n];
	
	for (int i = 0; i < n; i++)
		for (int z = 0; z < n; z++) scanf("%Lf", &matrix[i][z]);

	double* free = new double[n];
	double* x;
	for (int i = 0; i < n; i++) scanf("%Lf", &free[i]);

	//printf("Determine: %Lf\n", det(matrix, n));

	DWORD read = GetTickCount() - startTime;

	startTime = GetTickCount();
	printf("Jakibi method:\n");
	x = Jacobi(matrix, free, n);
	startTime = GetTickCount() - startTime;
	printf("Runtime: %d\n", startTime);
	printf("Runtime with read: %I64d", startTime + read);


	startTime = GetTickCount();
	printf("\n\nGauss-Seidel method:\n");
	x = GaussSeidel(matrix, free, n);
	startTime = GetTickCount() - startTime;
	printf("Runtime: %d\n", startTime);
	printf("Runtime with read: %I64d", startTime + read);

	startTime = GetTickCount();
	printf("\n\nDesent:\n");
	x = GradientDescent(matrix, free, n);
	startTime = GetTickCount() - startTime;
	printf("\nRuntime: %d\n", startTime);
	printf("Runtime with read: %I64d", startTime + read);
}