#include <iostream>
#include <iomanip>
#include <string>
#include "matrix.h"

using namespace std;

void PrintMatrix(Matrix M);
void SetMatrix(Matrix& M);

//====================
// ��������:
// 1 - �������� �� ������ ����� ������
// 2 - ����� � PrintMatrix() ����� ���������
//====================


static void Start()
{
	string s;
	string select;

	int n = 2;
	Matrix* matrices = new Matrix[n]; 
	Matrix res;

	cout << "�������: " << int('K') % 8 << endl;
	cout << setw(10) << setfill('-') << " " << endl;
	cout << endl;

	while (true)
	{
		cout << "�������� ��������: " << endl;
		cout << "1 - ���� ������ � ������� (�������)" << endl;
		cout << "2 - ����� ������ �� ������� (�������)" << endl;
		cout << "3 - ���������� ������������� ��������� ������" << endl;
		cout << setw(10) << setfill('-') << " " << endl;
		cout << "4 - �����" << endl;
		cout << setw(40) << setfill('=') << " " << endl;

		cin >> s;
		switch (s[0])
		{
		case '1':
			cout << "������� ����� ������� ��� ����� (1 ��� 2): " << endl;
			cin >> select;
			SetMatrix(matrices[stoi(select) - 1]);
			break;

		case '2':
			cout << "������� ����� ������� ��� ������ (1 ��� 2): " << endl;
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
			cout << "������ �����-��";
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

	cout << "������� ������� �������: ";
	cin >> M.size_1 >> M.size_2;

	cout << "������� �������: " << endl;
	M.matrix = new float*[M.size_1];
	for (int i = 0; i < M.size_1; i++)
	{
		M.matrix[i] = new float[M.size_2];
		for (int j = 0; j < M.size_2; j++)
			cin >> M.matrix[i][j];
	}

	cout << "������� ��������" << endl;
}


static void PrintMatrix(Matrix M)
{
	if (M.matrix == nullptr)
		cout << "������� �� �������" << endl;
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