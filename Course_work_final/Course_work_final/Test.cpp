#include <stdio.h>
#include "Utilities.h"
#include "Jacobi.h"
#include "Gauss–Seidel.h"
#include "GradientDescent.h"

int main(void) {
	freopen("input5.txt", "rt", stdin);
	utilities::system sols;

	scanf("%d", &sols.size);
	sols.matrix = utilities::CreateMatrix(sols.size);
	sols.free = utilities::CreateMas(sols.size);

	for (int i = 0; i < sols.size; i++)
		for (int z = 0; z < sols.size; z++)
			scanf("%Lf", &sols.matrix[i][z]);

	for (int i = 0; i < sols.size; i++)
		scanf("%Lf", &sols.free[i]);

	printf("Determine: %Lf\n", utilities::det(sols.matrix, sols.size));
	printf("Jacobi:\n");
	if (Jacobi::isSolved(sols)) {
		double* x = Jacobi::Jacobi(sols);
		for (int i = 0; i < sols.size; i++) printf("%Lf\n", x[i]);
		delete[] x;
	}

	printf("\n\nSeidel:\n");
	if (Seidel::isSolved(sols)) {
		double* x = Seidel::Seidel(sols);
		for (int i = 0; i < sols.size; i++) printf("%Lf\n", x[i]);
		delete[] x;
	}


	printf("\n\nGradient:\n");
	if (GradientDescent::isSolved(sols)) {
		double* x = GradientDescent::GradientDescent(sols);
		for (int i = 0; i < sols.size; i++) printf("%Lf\n", x[i]);
		delete[] x;
	}
}