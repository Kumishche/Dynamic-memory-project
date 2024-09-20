#include <iostream>
#include <iomanip>
#include <string>
#include "matrix.h"

using namespace std;

void PrintMatrix(Matrix M);
void SetMatrix(Matrix& M);

//====================
// Осталось:
// 1 - проверка на дурака везде вообще
// 2 - вывод в PrintMatrix() через указатели
//====================


static void Start()
{
	string s;
	string select;

	int n = 2;
	Matrix* matrices = new Matrix[n]; 
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

		cin >> s;
		switch (s[0])
		{
		case '1':
			cout << "Введите номер матрицы для ввода (1 или 2): " << endl;
			cin >> select;
			SetMatrix(matrices[stoi(select) - 1]);
			break;

		case '2':
			cout << "Введите номер матрицы для вывода (1 или 2): " << endl;
			cin >> select;
			PrintMatrix(matrices[stoi(select) - 1]);
			break;

		case '3':
			res = FindSolution(matrices, n);
			PrintMatrix(res);
			break;

		case '4':
			return;
		default:
			cout << "ерунда какая-то";
		}

		cout << setw(40) << setfill('=') << " " << endl;
		cout << endl;
	}
}


static void SetMatrix(Matrix& M)
{
	for (int i = 0; i < M.size_1; i++)
	{
		delete[] M.matrix[i];
	}
	delete[] M.matrix;

	cout << "Введите размеры матрицы: ";
	cin >> M.size_1 >> M.size_2;

	cout << "Введите матрицу: " << endl;
	M.matrix = new float*[M.size_1];
	for (int i = 0; i < M.size_1; i++)
	{
		M.matrix[i] = new float[M.size_2];
		for (int j = 0; j < M.size_2; j++)
			cin >> M.matrix[i][j];
	}

	cout << "Матрица записана" << endl;
}


static void PrintMatrix(Matrix M)
{
	if (M.matrix == nullptr)
		cout << "Матрица не введена" << endl;
	else
	{
		for (int i = 0; i < M.size_1; i++)
		{
			for (int j = 0; j < M.size_2; j++)
			{
				cout << M.matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}