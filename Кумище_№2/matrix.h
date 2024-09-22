#pragma once

struct Matrix
{
	float** matrix;
	int size_1;
	int size_2;

	Matrix(int s1 = 0, int s2 = 0)
	{
		size_1 = s1; size_2 = s2;
		matrix = nullptr;
		if (s1 != 0 && s2 != 0)
		{
			matrix = new float* [s1];
			for (int i = 0; i < s1; i++)
				matrix[i] = new float[s2];
		}
	}
};

Matrix FindSolution(Matrix* matrices, int size);
