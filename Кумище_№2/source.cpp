#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "matrix.h"

using namespace std;

void PrintMatrix(Matrix M);
void SetMatrix(Matrix& M);

void Check(int& a);

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	// Меню
	int c;
	// Выбор матрицы
	int select;
	// Исходное количество матриц
	int n = 2;
	Matrix* matrices = new Matrix[n];
	// Вычисленная матрциа
	Matrix res;

	cout << "Вариант: " << int('K') % 8 << endl;
	cout << setw(10) << setfill('-') << " " << endl;
	cout << endl;

	while (true)
	{
		cout << "Выберите действие: " << endl;
		cout << "1 - Ввод данных с консоли (матрицы)" << endl;
		cout << "2 - Вывод данных на консоль (матрицы)" << endl;
		cout << "3 - Выполнение поэлементного умножения матриц" << endl;
		cout << setw(10) << setfill('-') << " " << endl;
		cout << "4 - Выход" << endl;
		cout << setw(40) << setfill('=') << " " << endl;

		cin >> c;
		Check(c);

		switch (c)
		{
		case 1:
			cout << "Введите номер матрицы для ввода (1-" << n << ")" << endl;
			cin >> select;
			Check(select);
			while (select < 1 || select > n)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> select;
				Check(select);
			}
			SetMatrix(matrices[select - 1]);
			break;

		case 2:
			cout << "Введите номер матрицы для вывода (1-" << n << ")" << endl;
			cin >> select;
			Check(select);
			while (select < 1 || select > n)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> select;
				Check(select);
			}
			PrintMatrix(matrices[select - 1]);
			break;

		case 3:
			res = FindSolution(matrices, n);
			if (res.size_1 != 0) PrintMatrix(res);
			break;

		case 4:
			return 0;
		default:
			cout << "Некорректный ввод" << endl;
		}

		cout << setw(40) << setfill('=') << " " << endl;
		cout << endl;
	}
}


void Check(int& a)
{
	while (cin.fail() || cin.get() != '\n')
	{
		cin.clear(); cin.ignore(256, '\n');
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> a;
	}
}


void SetMatrix(Matrix& M)
{
	int s1, s2;

	for (int i = 0; i < M.size_1; i++)
	{
		delete[] M.matrix[i];
	}
	delete[] M.matrix;

	cout << "Введите количество строк матрицы: ";
	cin >> s1;
	Check(s1);
	while (s1 < 1)
	{
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> s1;
		Check(s1);
	}

	cout << "Введите количество столбцов матрицы: ";
	cin >> s2;
	Check(s2);
	while (s2 < 1)
	{
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> s2;
		Check(s2);
	}

	cout << "Введите матрицу: " << endl;
	M = Matrix(s1, s2);
	for (int i = 0; i < M.size_1; i++)
	{
		for (int j = 0; j < M.size_2; j++)
		{
			cin >> M.matrix[i][j];
			while (cin.fail())
			{
				cin.clear(); cin.ignore(256, '\n');
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод, начиная с элемента matrix[" << i << "][" << j << "] (включительно): ";
				cin >> M.matrix[i][j];
			}
		}
	}

	cin.ignore(256, '\n');
	cout << "Матрица записана" << endl;
}


void PrintMatrix(Matrix M)
{
	if (M.matrix == nullptr)
		cout << "Матрица не введена" << endl;
	else
	{
		float** p = &M.matrix[0];
		for (; p < &(M.matrix[0]) + M.size_1; p++)
		{
			for (int i = 0; i < M.size_2; i++)
			{
				cout << *(*p + i) << " ";
			}
			cout << endl;
		}
	}
}