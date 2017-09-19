#pragma once
#include "Vector3.h"

class Face
{
public:
	Face();
	Face(Vector3, Vector3, Vector3);
	~Face();
	Vector3 a;
	Vector3 b;
	Vector3 c;
};