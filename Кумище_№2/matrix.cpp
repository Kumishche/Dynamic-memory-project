#include <iostream>
#include "matrix.h"

Matrix FindSolution(Matrix* matrices, int size)
{
	Matrix res;

	int size1 = matrices[0].size_1;
	int size2 = matrices[0].size_2;

	for (int i = 1; i < size; i++)
	{
		if (size1 != matrices[i].size_1 || size2 != matrices[i].size_2)
		{
			std::cout << "Неверные матрицы" << std::endl;
			return res;
		}
	}
	

	res.matrix = new float* [size1];
	res.size_1 = size1; res.size_2 = size2;

	for (int i = 0; i < size1; i++)
	{
		res.matrix[i] = new float[size2];
		for (int j = 0; j < size2; j++)
		{
			res.matrix[i][j] = 1;
			for (int k = 0; k < size; k++)
				res.matrix[i][j] *= matrices[k].matrix[i][j];
		}
	}

	return res;
}