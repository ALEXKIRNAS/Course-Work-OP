#include "GradientDescent.h"
using utilities::scalarMult;
using utilities::matrixMult;


/******************************************
*		Функція рішення СЛАР методом	  *
*		градієнтного спуску				  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
double* GradientDescent::GradientDescent(system& sols) {
	double* x = utilities::CreateMas(sols.size); // Поточне рішення системи
	double* xk = utilities::CreateMas(sols.size); // Наступне наближення рішення
	double* r = utilities::CreateMas(sols.size); // Поточне значення незвязка
	double* rk = utilities::CreateMas(sols.size); // Наступне значення незвязки
	double* z = utilities::CreateMas(sols.size); // Поточне значення вектору напряку
	double* zk = utilities::CreateMas(sols.size);// Наступне значення вектору напрямку

	// Задання початкових уточнень
	for (int i = 0; i < sols.size; i++) {
		xk[i] = 0;
		rk[i] = sols.free[i];
		zk[i] = sols.free[i];
	}

	double norm = 2 * utilities::eps;
	while (norm >= utilities::eps) {

		utilities::masCopy(xk, x, sols.size);
		utilities::masCopy(rk, r, sols.size);
		utilities::masCopy(zk, z, sols.size);

		double* Az = matrixMult(sols, z);
		double alpha = scalarMult(r, r, sols.size) / scalarMult(Az, z, sols.size) ; // Скалярний крок градієнту

		for (int i = 0; i < sols.size; i++) xk[i] += alpha * z[i];
		for (int i = 0; i < sols.size; i++) rk[i] -= alpha * Az[i];
	
		double beta = scalarMult(rk, rk, sols.size) / scalarMult(r, r, sols.size); // Скалярна корекція напрямку
		
		utilities::masCopy(rk, zk, sols.size);
		for (int i = 0; i < sols.size; i++) zk[i] += beta * z[i];

		utilities::freeMas(Az);

		norm = utilities::normCalc(x, xk, sols.size);
	}

	utilities::freeMas(x);
	utilities::freeMas(r);
	utilities::freeMas(rk);
	utilities::freeMas(z);
	utilities::freeMas(zk);

	return xk;
}

/******************************************
*		Функція перевірки на сходимість	  *
*		методу градієнтного спуску		  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
bool GradientDescent::isSolved(system& sols) {
	return utilities::isPositive(sols) && utilities::isSemetric(sols);
}