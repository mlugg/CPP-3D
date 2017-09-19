#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(double ix, double iy)
{
	x = ix;
	y = iy;
}

Vector2::~Vector2()
{
}

double Vector2::GetMagnitude()
{
	return sqrt(x*x + y*y);
}