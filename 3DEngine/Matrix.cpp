#include "Matrix.h"

Matrix::Matrix()
{
	matrix.fill(0);
	values.fill(0);
}


Matrix::~Matrix()
{
}

void Matrix::SetMatrix(std::array<double, 16> imatrix)
{
	matrix = imatrix;
}

void Matrix::SetValues(std::array<double, 4> ivalues)
{
	values = ivalues;
}

std::array<double,4> Matrix::Calculate()
{
	std::array<double, 4> out;

	for (int i = 0; i < 4; i++) {
		double a = matrix[i * 4 + 0] * values[0];
		double b = matrix[i * 4 + 1] * values[1];
		double c = matrix[i * 4 + 2] * values[2];
		double d = matrix[i * 4 + 3] * values[3];

		out[i] = a + b + c + d;
	}

	return out;
}