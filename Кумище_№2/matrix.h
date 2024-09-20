#pragma once

struct Matrix
{
	float** matrix = nullptr;
	int size_1 = 0;
	int size_2 = 0;
};

Matrix FindSolution(Matrix* matrices, int size);
