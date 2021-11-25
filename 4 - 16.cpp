// #include "stdafx.h" (если более ранняя версия программы)
#include <conio.h>
#include <locale>
#include <iostream>
#include <cmath>
using namespace std;
double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		cout << "Введите число: 1 - начало работы, 0 - конец работы" << endl;
		int z = _getch();
		switch (z)
		{
		case 49:
		{
			cout << "Вычисление значений функции sh(x)\n\n";
			double x; // Значение аргумента
			double func; // Точное значение функции
			double sum; // Значение частичной суммы
			int n; // Число слагаемых в частичной сумме

			cout << "Выберите задание: " << endl;
			cout << "Первое задание - 1" << endl;
			cout << "Второе задание - 2" << endl;
			int p = _getch();
			switch (p)
			{
			case 49:
			{
				cout << "Введите значение аргумента: ";
				cin >> x;
				cout << "Задайте число слагаемых: ";
				cin >> n;
				func = (exp(x) - exp(-x))/2;// Вычисление точного значения sh(x)
				double last;
				sum = sumN(x, n, last);
				cout << "Точное значение функции равно " << func << endl;
				cout << "Частичная сумма ряда равна " << sum << endl;
				cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
				cout << "Последнее слагаемое равно " << last << endl;
				cout << endl;
				continue;
			}
			
			case 50:
			{
				double E;
				cout << "Введите значение аргумента: ";
				cin >> x;
				cout << "Задайте точность вычислений: ";
				cin >> E;
				func = (exp(x) - exp(-x)) / 2;
				sum = sumE(x, E, n);
				cout << "Точное значение функции равно " << func << endl;
				cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
				cout << "Учтено " << n << " членов ряда" << endl;
				sum = sumE(x, E / 10, n);
				cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
				cout << "Учтено " << n << " членов ряда" << endl;
				cout << endl;
				continue;
			}

			default:
				cout << "Ошибка. Введите 1 или 2" << endl;
			}
		}
		case 48:
		{
			cout << "Конец работы." << endl;
			return 1;
		}

		default:
			cout << "Ошибка. Введите 1 или 0" << endl;
		}
	}
}

double sumN(double x, int n, double& last)
{
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		double r; // Отношение i-го слагаемлого к (i - 1)-му
	   // Вычисление значения r
		r = x * x / (2 * i) / (2 * i + 1);
		last *= r;
		sum += last;
	}
	return sum;
}

double sumE(double x, double E, int& n)
{
	double last;
	last = x;
	double sum = last;
	n = 1;
	while (fabs(last) > E)
	{
		double r; // Отношение n-го слагаемлого к (n - 1)-му
	  // Вычисление значения r
		r = x * x / (2 * n) / (2 * n + 1);
		last *= r;
		sum += last;
		n++;
	}
	return sum;
}