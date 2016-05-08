#pragma once

namespace utilities {
	const double eps = 1e-5; // Точність обчислення розвяку

	// Структура, що представляє систему
	struct system {
		int size; // Розмір системи
		double** matrix; // Матриця системи
		double* free; // Стовпець вільних членів
	};


	double det(double**, const int&); // Прототип функції обчислення визначника
	double** matrixCut(double**, const int&, const int&); // Прототип функції уворення матриці(N - 1) - го порядку
	double AlgebralAdditionCalc(double**, const int&, const int&); // Прототип функції обчислення алгебраїного доповнення заданого елементу
	double normCalc(double*, double*, const int&); // Прототип функції обчислення норми поточного рішення
	bool isSemetric(const system&); // Прототип функції превірки матриці системи на симетричність
	bool isPositive(const system&); // Прототип функції превірки матриці системи на додатньовизначеність
	double** cornerMinor(const system&, int); // Прототип функції утворення кутового мінору
	double* matrixMult(const system&, double*); // Прототип функції множення матриці системи на вектор
	double scalarMult(double*, double*, int&); // Прототип функції скалярного добутку векторів
	void stableSystem(system&); // Прототип функції приведння матриці системи до канонічного вигляду
	int indexOfMaxElement(double*, const int&);  // Прототип функції знаходження індекса максимального елементу в рядку
	double lineSumElement(double*, const int&);  // Прототип функції знаходження суми елементів в рядку
	bool isDiagDominate(const system&); // Прототип функції перевірки матриці системи на діагональний перевіс
	double** CreateMatrix(int); // Прототип функції виділення памяті під матрицю
	void freeMatrix(double** &, int); // Прототип функції видалення матриці з памяті
	double* CreateMas(int); // Прототип функції виділення памяті під масив
	void freeMas(double* &); // Прототип функції видалення масиву з памяті
	void masCopy(double*, double*, int&); // Прототип функції копіювання масиву
};