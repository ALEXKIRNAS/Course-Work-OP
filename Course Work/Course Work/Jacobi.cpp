#include "DetermineCalc.h"
#include "Jacobi.h"
#include <cmath>

const double eps = 1e-5; // Точність обчислення

/******************************************
*		Функція обчислення матриці на	  *
*		головній діагоналі якої відсутні  *
*		нулі							  *
*	Параметри:							  *
*	matrix - матриця для якої потірбно	  *
*		  обчислити нову матрицю		  *
*	n - розмірність матриці				  *
******************************************/
void deleteDiagZero(double** matrix, const int& n) {
	// Створюємо масив, який вказує чи є елемент з індексом (i, i) нульвом
	// та заповнюємо його нулями (тобто вважаємо, що на головній діагоналі
	// відсутні нулі)
	bool* isZero = new bool[n];
	for (int i = 0; i < n; i++) isZero[i] = false;

	// Виділяємо діагональні елементи, які рівні нулю
	for (int i = 0; i < n; i++) if (matrix[i][i] == 0) isZero[i] = true;

	// Заміняємо нульові елементи діагоналі на ненульові 
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
*		Функція перевірки на сходимість	  *
*		метода Якобі					  *
*	Параметри:							  *
*	matrix - матриця для якої потірбно	  *
*		  перевірити сходимість 		  *
*	n - розмірність матриці				  *
******************************************/
bool isSolution(double** matrix, const int& n) {
	// Якщо матриця СЛАР вироджена
	if (det(matrix, n) == 0) return false;

	// Знищуємо діагоналі нулі
	deleteDiagZero(matrix, n);


	// Створення матриці перевірки сходимості методу Якобі
	double** B = new double*[n];
	for (int i = 0; i < n; i++) B[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int z = 0; z < n; z++)
			if (i == z) B[i][z] = 0;
			else B[i][z] = matrix[i][z] / matrix[i][i];

	// Перевірка на сходимість метода Якобі
	if (abs(det(B, n)) < 1) return true;
	else return false;
}

/******************************************
*		Функція розвязання СЛАР методом	  *
*		Якобі							  *
*	Параметри:							  *
*	matrix - матриця системи			  *
*	free - стовпець вільних членів		  *
*	n - розмірність матриці				  *
******************************************/
double* Jacobi(double** matrix, double* free, const int& n) {
	double* X = new double[n]; // Масив, що містить розвязок СЛАР
	double* TempX = new double[n]; // Наступне наближення
	//Попереднє наближення розвязку
	for (int i = 0; i < n; i++) X[i] = free[i] / matrix[i][i];

	double norm; // Норма, яка визначається як найбільша різниця елеметів стовпця Х між сусідніми ітераціями

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

	} while (norm > eps);

	delete [] TempX;
	return X;
}

/******************************************
*		Функція розвязання СЛАР методом	  *
*		Якобі							  *
*	Параметри:							  *
*	matrix - матриця системи			  *
*	free - стовпець вільних членів		  *
*	n - розмірність матриці				  *
******************************************/
double matrixNorm(double* X, double* TempX, const int& n) {
	double norm = abs(X[0] - TempX[0]);
	for (int i = 0; i < n; i++)
		if (abs(X[i] - TempX[i]) > norm) norm = abs(X[0] - TempX[0]);

	return norm;
}