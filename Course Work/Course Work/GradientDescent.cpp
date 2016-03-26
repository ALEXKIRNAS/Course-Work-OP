#include "GradientDescent.h";
#include "DetermineCalc.h"
#include "Jacobi.h"

extern const double eps;

/******************************************
*		Функція визначення того чи є	  *
*		матриця симетричною				  *
*	Параметри:							  *
*	matrix - матрицяяку необхідно		  *
*				перевірити				  *
*	n - розмірність матриці				  *
******************************************/
bool isSemetric(double** matrix, const int& n) {
	for (int i = 0; i < n; i++)
		for (int z = i + 1; z < n; z++)
			// Якщо матриця не симетрична
			if (matrix[i][z] != matrix[z][i]) return false;
	return true;
}

/******************************************
*		Функція визначення того чи є	  *
*		матриця додатньовизначеною		  *
*	Параметри:							  *
*	matrix - матрицяяку необхідно		  *
*				перевірити				  *
*	n - розмірність матриці				  *
******************************************/
bool isPositive(double** matrix, const int& n) {
	// Користуємося критерієм Сильвестра
	for (int i = 1; i <= n; i++) {

		double** cut = new double* [i]; // Кутовий мінор розміру i X i

		// Заповнюємо матрицю кутового мінора
		for (int z = 0; z < i; z++) {
			cut[z] = new double[i];
			for (int j = 0; j < i; j++) cut[z][j] = matrix[z][j];
		}

		// Якщо визначник кутового мінору не є додатньою, то матриця не є додатньовизначеною
		if (det(cut, i) <= 0) return false;
	}

	return true;
}

/******************************************
*		Функція розвязання СЛАР методом	  *
*		градієнтного спуску				  *
*	Параметри:							  *
*	matrix - матриця системи			  *
*	free - стовпець вільних членів		  *
*	n - розмірність матриці				  *
******************************************/
double* GradientDescent(double** matrix, double* free, const int& n) {
	double *x = new double[n]; // Поточне рішення системи
	double *xk = new double[n]; // Наступне наближення рішення
	double *g = new double[n]; // Поточне значення градієнту
	double *gk = new double[n]; // Наступне значення градієнту
	double *d = new double[n]; // Поточне значення вектору напряку
	double *dk = new double[n]; // Наступне значення вектору напрямку
	double s; // Скалярний крок алгоритму

	// Задання початкових уточнень
	for (int i = 0; i < n; i++) gk[i] = g[i] = d[i] = dk[i] = xk[i] = 0;

	do {

		// Step ONE
		for (int i = 0; i < n; i++) {
			gk[i] = -free[i];
			for (int z = 0; z<n; z++)
				gk[i]+= x[z] * matrix[i][z];
		}

		// Step TWO
		double scalar1 = 0; // Обчислення доботку векторів gk^T та gk
		double scalar2 = 0;// Обчислення доботку векторів g^T та g
		for (int i = 0; i<n; i++) {
			scalar1 += gk[i] * gk[i];
			scalar2 += g[i] * g[i];
		}

		// Обчислення наступного напрямку
		double alpha = scalar1 / scalar2; //Обчислення коефіцієнту попереднього напрямку
		for (int i = 0; i<n; i++) dk[i] = -gk[i] + alpha*d[i];

		// Step Three
		double scalar3 = 0; // Обчилення добутку векторів dk та gk
		double scalar4 = 0; // Обчислення добутку dk^T * matrix * dk
		double* c = new double[n]; // Тимчасовий вектор для збереження добутку dk^T * matrix

		for (int i = 0; i < n; i++) scalar3 += dk[i] * gk[i];

		for (int i = 0; i<n; i++) {
			c[i] = 0;
			for (int z = 0; z<n; z++) c[i] += dk[i] * matrix[i][z];
		}

		for (int i = 0; i<n; i++) scalar4 += c[i] * dk[i];

		s = scalar3 / scalar4;

		// Step Four
		// Обчислення наступного наближення 
		for (int i = 0; i<n; i++)
			xk[i] = x[i] + s*dk[i];

		// Post step
		for (int i = 0; i<n; i++) {
			d[i] = dk[i];
			g[i] = gk[i];
			x[i] = xk[i];
		}

	} while (matrixNorm(x, xk, n) > eps);

	return x;
}