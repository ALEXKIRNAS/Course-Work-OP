#pragma once
int det(const int**, int); // Прототип функції обчислення визначника
int AlgebralMinorCalc(const int const**, const int&, const int&); // Прототип функції обчислення алгебраїчного мінору заданого елементу
int AlgebralAdditionCalc(const int const**, const int&, const int&); // Прототип функції обчислення алгебраїного доповнення заданого елементу
int** matrixCut(const int**, const int&, const int&); // Прототип функції уворення матриці (N-1)-го порядку