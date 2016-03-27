#include "GradientDescent.h";
#include "DetermineCalc.h"
#include "Jacobi.h"

extern const double eps;

/******************************************
*		‘ункц≥€ визначенн€ того чи Ї	  *
*		матриц€ симетричною				  *
*	ѕараметри:							  *
*	matrix - матриц€€ку необх≥дно		  *
*				перев≥рити				  *
*	n - розм≥рн≥сть матриц≥				  *
******************************************/
bool isSemetric(double** matrix, const int& n) {
	for (int i = 0; i < n; i++)
		for (int z = i + 1; z < n; z++)
			// якщо матриц€ не симетрична
			if (matrix[i][z] != matrix[z][i]) return false;
	return true;
}

/******************************************
*		‘ункц≥€ визначенн€ того чи Ї	  *
*		матриц€ додатньовизначеною		  *
*	ѕараметри:							  *
*	matrix - матриц€€ку необх≥дно		  *
*				перев≥рити				  *
*	n - розм≥рн≥сть матриц≥				  *
******************************************/
bool isPositive(double** matrix, const int& n) {
	//  ористуЇмос€ критер≥Їм —ильвестра
	for (int i = 1; i <= n; i++) {

		double** cut = new double* [i]; //  утовий м≥нор розм≥ру i X i

		// «аповнюЇмо матрицю кутового м≥нора
		for (int z = 0; z < i; z++) {
			cut[z] = new double[i];
			for (int j = 0; j < i; j++) cut[z][j] = matrix[z][j];
		}

		// якщо визначник кутового м≥нору не Ї додатньою, то матриц€ не Ї додатньовизначеною
		if (det(cut, i) <= 0) return false;
	}

	return true;
}

/******************************************
*		‘ункц≥€ розв€занн€ —Ћј– методом	  *
*		град≥Їнтного спуску				  *
*	ѕараметри:							  *
*	matrix - матриц€ системи			  *
*	free - стовпець в≥льних член≥в		  *
*	n - розм≥рн≥сть матриц≥				  *
******************************************/
double* GradientDescent(double** matrix, double* free, const int& n) {
	double *x = new double[n]; // ѕоточне р≥шенн€ системи
	double *xk = new double[n]; // Ќаступне наближенн€ р≥шенн€
	double *r = new double[n]; // ѕоточне значенн€ незв€зка
	double *rk = new double[n]; // Ќаступне значенн€ незв€зки
	double *z = new double[n]; // ѕоточне значенн€ вектору напр€ку
	double *zk = new double[n]; // Ќаступне значенн€ вектору напр€мку

	// «аданн€ початкових уточнень
	for (int i = 0; i < n; i++) {
		xk[i] = 0;
		rk[i] = free[i];
		zk[i] = free[i];
	}

	do {

		// PreStep
		for (int i = 0; i < n; i++) {
			x[i] = xk[i];
			r[i] = rk[i];
			z[i] = zk[i];
		}

		// Step ONE
		double alpha = 0; // —кал€рний крок град≥Їнту
		double p1 = 0; // —кал€рний добуток вектор≥в (r, r)
		double p2 = 0; // Cкал€рний добуток вектор≥в (A*z, z)

		for (int i = 0; i<n; i++) alpha += r[i] * r[i];
		for (int i = 0; i<n; i++) {
			double temp = 0;
			for (int j = 0; j<n; j++) temp += matrix[i][j] * z[j];
			p2 += temp*z[i];
		}

		alpha = p1 / p2;

		// Step TWO
		for (int i = 0; i<n; i++)
			xk[i] = x[i] + alpha * z[i];

		// Step THREE
		for (int i = 0; i<n; i++) {
			double temp = 0;
			for (int j = 0; j<n; j++) temp += matrix[i][j] * z[j];
			temp *= alpha;
			rk[i] = r[i] - temp;
		}

		// Step FOUR
		double beta = 0; // —кал€рна корекц≥€ напр€мку
		double p3 = 0; // —кал€рний добуток (rk, rk)
		double p4 = 0; // —кал€рний добуток (r, r)

		for (int i = 0; i<n; i++) {
			p3 += rk[i] * rk[i];
			p4 += r[i] * r[i];
		}

		// Step FIVE
		for (int i = 0; i<n; i++) zk[i] = z[i] + beta*z[i];

	} while (matrixNorm(x, xk, n) > eps);

	return x;
}