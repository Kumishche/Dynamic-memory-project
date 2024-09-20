#include <iostream>
#include <iomanip>
#include <string>
#include "matrix.h"

using namespace std;

void PrintMatrix(float** matrix, int size_1, int size_2);
float** SetMatrix(int& size_1, int& size_2);

struct Matrix
{
	float** matrix;
	int size_1 = 0;
	int size_2 = 0;
};

static void Start()
{
	string s;
	string select;

	//Matrix*** matrices = new Matrix**[2];


	float** matrix_A = nullptr;
	float** matrix_B = nullptr;
	float** res = nullptr;
	int size_a1 = 0, size_a2 = 0;
	int size_b1 = 0, size_b2 = 0;
	int size_res1 = 0, size_res2 = 0;
	


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
			cout << "Выберите матрицу для ввода: " << endl;
			cout << "1 - матрица А	|	2 - матрица B" << endl;
			cin >> select;

			for (int i = 0; i < size_a1; i++)
			{
				delete[] matrix_A[i];
			}
			delete[] matrix_A;
			//matrix_A = nullptr; //!!!!!!!!!!!!
			matrix_A = SetMatrix(size_a1, size_a2);
			cout << endl;
			cout << "Задание матрицы B:" << endl;
			for (int i = 0; i < size_b1; i++)
			{
				delete[] matrix_B[i];
			}
			delete[] matrix_B;
			matrix_B = SetMatrix(size_b1, size_b2);
			break;
		case '2':
			cout << "Матрица А: " << endl;
			PrintMatrix(matrix_A, size_a1, size_a2);
			cout << "Матрица B: " << endl;
			PrintMatrix(matrix_B, size_b1, size_b2);
			break;
		case '3':
			res = FindSolution(matrix_A, matrix_B, size_a1, size_a2, size_b1, size_b2, size_res1, size_res2);
			cout << "Новая матрица: " << endl;
			PrintMatrix(res, size_res1, size_res2);
			break;
		case '4':
			return;
			break;
		default:
			cout << "ерунда какая-то";
		}

		cout << setw(40) << setfill('=') << " " << endl;
		cout << endl;
	}
}


static float** SetMatrix(int& size_1, int& size_2)
{
	float** matrix = nullptr;

	cout << "Введите размеры матрицы: ";
	cin >> size_1 >> size_2;

	matrix = new float* [size_1];
	for (int i = 0; i < size_1; i++)
	{
		matrix[i] = new float[size_2];
		for (int j = 0; j < size_2; j++)
			cin >> matrix[i][j];
	}

	cout << "Матрица записана" << endl;
	return matrix;
}


static void PrintMatrix(float** matrix, int size_1, int size_2)
{
	if (matrix == nullptr)
		cout << "Матрица не введена" << endl;
	else
	{
		for (int i = 0; i < size_1; i++)
		{
			for (int j = 0; j < size_2; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
}