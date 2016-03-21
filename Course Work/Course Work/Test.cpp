#include "DetermineCalc.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) matrix[i] = new int[n];
	
	for (int i = 0; i < n; i++)
		for (int z = 0; z < n; z++) scanf("%d", &matrix[i][z]);

	time_t clocks = clock();

	printf("Determine: %d", det(matrix, n));
	clocks = clock() - clocks;
	printf("\nRuntime: %d\n", clocks);
	system("pause");
}