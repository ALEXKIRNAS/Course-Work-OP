#include "Utilities.h"
#include <cmath>
using namespace utilities;

/******************************************
*		Функція обчислення визначника	  *
*		матриці							  *
*	Параметри:							  *
*	matrix - матриця для якої потірбно	  *
*			 порахувати визначник		  *
*	size - розмірність матриці			  *
******************************************/
double utilities::det(double** matrix, const int& size) {
	//ЯКЩО розмірність матриці одинична, ТО повернути визначник матриці 1х1
	if (size == 1)  return **matrix;
	else {
		// Обчислення визначника матриці розкладом за першим стовпцем
		double detRes = 0; // Визначник поточної матриці
		for (int i = 0; i < size; i++) detRes += AlgebralAdditionCalc(matrix, size, i) * matrix[i][0];
		return detRes;
	}
}

/******************************************
*		Функція  уворення матриці		  *
*		(N-1)-го порядку				  *
*	Параметри:							  *
*	matrix - матриця для якої потірбно	  *
*		     знайт мінор				  *
*	size - розмірність матриці			  *
*	y - номер рядка елемента, для		  *
*		якого потрібно порахувати		  *
*	    мінор							  *
******************************************/
double** utilities::matrixCut(double** matrix, const int& size, const int& y) {
	int elementCount = 0; // Кількість елементів в утвореній матриці
	// Cтворюємо нову матрицю
	double** newMatrix = CreateMatrix(size - 1);

	// Заповнюємо матрицю
	for (int i = 0; i < size; i++)
		for (int z = 1; z < size; z++)
			if (i != y) {
				newMatrix[elementCount / (size - 1)][elementCount % (size - 1)] = matrix[i][z];
				elementCount++;
			}

	return newMatrix;
}

/******************************************
*		Функція обчислення алгебраїчного  *
*		доповнення заданого елементу	  *
*	Параметри:							  *
*	matrix - матриця для якої потірбно	  *
*		  знайти алгебраїчне доповнення	  *
*	size - розмірність матриці			  *
*	y - номер рядка елемента, для		  *
*		якого потрібно порахувати		  *
*		алгебраїний мінор				  *
******************************************/
double utilities::AlgebralAdditionCalc(double** matrix, const int& size, const int& y) {
	double** newMatrix = matrixCut(matrix, size, y);
	double result = det(newMatrix, size-1) * (y & 1 ? -1 : 1); // Алгебраїчне доповнення

	freeMatrix(newMatrix, size - 1);
	return result;
}

/******************************************
*		Функція обчислення норми		  *
*		поточного наближення			  *
*	Параметри:							  *
*	х - поперднє наближення 			  *
*	хk - поточне  наближення			  *
*	size - розмірність масивів			  *
******************************************/
double utilities::normCalc(double* x, double* xk, const int& size) {
	double norm = abs(*x - *xk);
	for (int i = 1; i < size; i++)
		if (abs(x[i] - xk[i]) > norm) norm = abs(x[i] - xk[i]);
	return norm;
}


/******************************************
*		Функція перевірки матриці		  *
*		системи на симетричність		  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
bool utilities::isSemetric(const system& sols) {
	for (int i = 0; i < sols.size; i++)
		for (int z = i; z < sols.size; z++)
			if (sols.matrix[i][z] != sols.matrix[z][i]) return false;
	return true;
}

/******************************************
*		Функція перевірки матриці		  *
*		системи на додатньовизначеність	  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
bool utilities::isPositive(const system& sols) {
	// Користуємося критерієм Сильвестра
	for (int i = 1; i <= sols.size; i++) {
		double** newMatrix = cornerMinor(sols, i);

		// Якщо визначник кутового мінору не є додатньою, то матриця не є додатньовизначеною
		if (det(newMatrix, i) <= 0) return false;
		freeMatrix(newMatrix, i);
	}

	return true;
}

/******************************************
*		Функція утворення кутового		  *
*		мінору матриці					  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
*	size - розмірність кутового мінору	  *
******************************************/
double** utilities::cornerMinor(const system& sols, int size) {
	double** newMatrix = CreateMatrix(size);
	for (int i = 0; i < size; i++)
		for (int z = 0; z < size; z++)
			newMatrix[i][z] = sols.matrix[i][z];
	return newMatrix;
}

/******************************************
*		Функція множення матриці на		  *
*		вектор							  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
*	mas - вектор, на який множиться СЛАР  *
******************************************/
double* utilities::matrixMult(const system& sols, double* mas) {
	double* newVector = CreateMas(sols.size);
	for (int i = 0; i < sols.size; i++) {
		newVector[i] = 0;
		for (int z = 0; z < sols.size; z++) newVector[i] += mas[z] * sols.matrix[i][z];
	}
	return newVector;
}

/******************************************
*		Функція знаходження скалярного	  *
*		добутку векторів				  *
*	Параметри:							  *
*	vector1 - перший векртор			  *
*	vector2 - другий вектор				  *	
*	size - розмірність векторі			  *
******************************************/
double utilities::scalarMult(double* vector1, double* vector2, int& size) {
	double scalar = 0;
	for (int i = 0; i < size; i++) scalar += vector1[i] * vector2[i];
	return scalar;
}

/******************************************
*		Функція стабілізації матриці	  *
*		відносно головної діагоналі		  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
void utilities::stableSystem(system& sols) {
	// Масив який вказує на якому рядку було замічено діагональний перевіс
	int* mas = new int[sols.size];
	for (int i = 0; i < sols.size; i++) mas[i] = -1;

	for (int i = 0; i < sols.size; i++) {
		int index = indexOfMaxElement(sols.matrix[i], sols.size);
		double sum = lineSumElement(sols.matrix[i], sols.size);

		if (sum >= abs(2 * sols.matrix[i][index])) {
			delete[] mas;
			return;
		}

		if(mas[index] != -1){
			delete[] mas;
			return;
		}

		mas[index] = i;
	}

	system newSols;
	newSols.size = sols.size;
	newSols.matrix = CreateMatrix(sols.size);
	newSols.free = CreateMas(sols.size);

	for (int i = 0; i < sols.size; i++) {
		newSols.free[i] = sols.free[mas[i]];
		for (int z = 0; z < sols.size; z++) newSols.matrix[i][z] = sols.matrix[mas[i]][z];
	}

	freeMatrix(sols.matrix, sols.size);
	freeMas(sols.free);

	sols = newSols;
	delete[] mas;
}

/******************************************
*		Функція  знаходження			  *
*		максимального за абсолютним		  *
*		значення елемента в поточному	  *
*		рядку							  *
*	Параметри:							  *
*	mas - поточний рядок				  *
*	size - кількість елементів в рядку	  *
******************************************/
int utilities::indexOfMaxElement(double* mas, const int& size) {
	int index = 0; // Індекс максимального елементу
	for (int i = 1; i < size; i++) if (abs(mas[i]) >  abs(mas[index])) index = i;
	return index;
}

/******************************************
*		Функція  знаходження			  *
*		суми абсолютних значеннь		  *
*		елементів в поточному			  *
*		рядку							  *
*	Параметри:							  *
*	mas - поточний рядок				  *
*	size - кількість елементів в рядку	  *
******************************************/
double utilities::lineSumElement(double* mas, const int& size) {
	double sum = 0; // Сума елементів
	for (int i = 0; i < size; i++) sum += abs(mas[i]);
	return sum;
}

/******************************************
*		Функція перевірки матриці системи *
*		на діагональний перевіс			  *
*	Параметри:							  *
*	sols - система лінійних алгебраїчних  *
*		   рівнянь						  *
******************************************/
bool utilities::isDiagDominate(const system& sols) {
	for (int i = 0; i < sols.size; i++) {
		double sum = lineSumElement(sols.matrix[i], sols.size);
		if (sum >= abs(2 * sols.matrix[i][i])) return false;
	}
	return true;
}

/******************************************
*		Функція виділення динамічної	  *
*		памяті під матрицю				  *
*	Параметри:							  *
*	size - розмірність матриці			  *
******************************************/
double** utilities::CreateMatrix(int size) {
	double** matrix = new double*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new double[size];
	return matrix;
}

/******************************************
*		Функція видалення матриці		  *
*	Параметри:							  *
*	matrix - матриця, яку необхідно		  *
*			 видалити					  *
*	size - розмірність матриці			  *
******************************************/
void utilities::freeMatrix(double** & matrix, int size) {
	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
}

/******************************************
*		Функція виділення динамічної	  *
*		памяті під масив				  *
*	Параметри:							  *
*	size - розмірність масиву			  *
******************************************/
double* utilities::CreateMas(int size) {
	double* mas = new double [size];
	return mas;
}

/******************************************
*		Функція видалення масиву		  *
*	Параметри:							  *
*	mas - масив, який необхідно			  *
*			 видалити					  *
******************************************/
void utilities::freeMas(double* & mas) {
	delete[] mas;
	mas = nullptr;
}

/******************************************
*		Функція копіювання масиву		  *
*	Параметри:							  *
*	scr - масив, який потрібно копіювати  *
*	dist - масив, в який потірбно		  *
*		   копіювати					  *
*	size - розмірність масиву			  *
******************************************/
void utilities::masCopy(double* src, double* dist, int& size) {
	for (int i = 0; i < size; i++) dist[i] = src[i];
}