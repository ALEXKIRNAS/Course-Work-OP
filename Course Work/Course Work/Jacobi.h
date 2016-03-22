#pragma once
void deleteDiagZero(double**, const int&); // Прототим функції, що видає матрицю на головній діагоналі якої відсутні нулі
bool isSolution(double**, double* free, const int&); // Протопип функції, що перевіряє на сходимість метод Якобі
double* Jacobi(double**, double*, const int&); // Прототип функції вирішення СЛАР методом Якобі
double matrixNorm(double*, double*, const int&); // Прототип функції обчислення норми масиву