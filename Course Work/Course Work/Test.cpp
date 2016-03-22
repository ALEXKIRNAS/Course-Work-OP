#include "DetermineCalc.h"
#include "Jacobi.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
	//freopen("input.txt", "r", stdin);
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

	if (isSolution(matrix, free, n) == false) printf("No solution!");
	else for (int i = 0; i < n; i++) {
		x = Jacobi(matrix, free, n);
		printf("Solution: %Lf ", x[i]);
	}

	clocks = clock() - clocks;
	printf("\nRuntime: %d\n", clocks);
}