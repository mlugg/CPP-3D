#pragma once
#include <array>

class Matrix
{
public:
	Matrix();
	~Matrix();

	void SetMatrix(std::array<double, 16>);

	void SetValues(std::array<double, 4>);

	std::array<double,4> Calculate();
private:
	std::array<double, 16> matrix;
	std::array<double, 4> values;
};