#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(double ix, double iy, double iz)
{
	x = ix;
	y = iy;
	z = iz;
}

Vector3::~Vector3()
{
}

double Vector3::GetMagnitude()
{
	return sqrt(x*x + y*y + z*z);
}