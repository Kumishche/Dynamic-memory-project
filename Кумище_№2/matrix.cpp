#include <iostream>

float** FindSolution(float** matrix_A, float** matrix_B, int size_a1, int size_a2, int size_b1, int size_b2, int& size1, int& size2)
{
	float** res = nullptr;

	if (size_a1 != size_b1 || size_a2 != size_b2)
	{
		std::cout << "Неверные матрицы" << std::endl;
		return res;
	}

	res = new float* [size_a1];
	for (int i = 0; i < size_a1; i++)
	{
		res[i] = new float[size_a2];
		for (int j = 0; j < size_a2; j++)
		{
			res[i][j] = matrix_A[i][j] * matrix_B[i][j];
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}


	return res;
}