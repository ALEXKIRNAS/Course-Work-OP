#include "DetermineCalc.h"
#include "Jacobi.h"
#include "Gauss–Seidel.h"
#include "GradientDescent.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

extern const double eps = 1e-5; // Наближення з яким шукаються корні

int main(void) {
	freopen("input.txt", "r", stdin);
	int n;

	scanf("%d", &n);
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++) matrix[i] = new double[n];
	
	for (int i = 0; i < n; i++)
		for (int z = 0; z < n; z++) scanf("%Lf", &matrix[i][z]);

	double* free = new double[n];
	double* x;
	for (int i = 0; i < n; i++) scanf("%Lf", &free[i]);

	time_t clocks = clock();

	printf("Determine: %Lf\n", det(matrix, n));

	printf("Jakibi method:\n");
	if (isSolution(matrix, n) == false) printf("No solution!");
	else {
		x = Jacobi(matrix, free, n);
		for (int i = 0; i < n; i++)
			printf("Solution: %Lf ", x[i]);
	}
	

	printf("\n\nGauss-Seidel method:\n");
	if (isSolution(matrix, n) == false && !(isPositive(matrix, n) && isSemetric(matrix, n)) ) printf("No solution!");
	else {
		x = GaussSeidel(matrix, free, n);
		for (int i = 0; i < n; i++)
			printf("Solution: %Lf ", x[i]);
	}

	printf("\n\nDesent:\n");
	if (isPositive(matrix, n) && isSemetric(matrix, n))
	{
		x = GradientDescent(matrix, free, n);
		for (int i = 0; i < n; i++)
			printf("Solution: %Lf ", x[i]);
	}
	else printf("No solution!");

	clocks = clock() - clocks;
	printf("\nRuntime: %d\n", clocks);
}