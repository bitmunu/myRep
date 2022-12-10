
/* Вариант-7.

   Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если все диагональные элементы матрицы являются наибольшими элементами своих строк,
заменить элементы матрицы, содержащие цифру 0, на произведение диагональных элементов.*/

#include <iostream>
#include <cmath>
#include "Sun.h"

int main()
{
    int n;
    std::cin >> n;
    int** mas = new int* [n];

    for (int i = 0; i < n; i++)
    {
        mas[i] = new int[n];
    }

    myspace::read(mas, n);
    myspace::show(mas, n);
    bool c = myspace::if_max(mas, n);

    if (c == 1)
    {
        myspace::infect_with_max(mas, n, myspace::node(mas, n));
    }

    myspace::show(mas, n);

    for (int i = 0; i < n; i++)
    {
        delete[] mas[i];
    }
    
    delete[] mas;
}

