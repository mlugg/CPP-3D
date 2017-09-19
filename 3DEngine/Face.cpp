#include "Face.h"

Face::Face()
{
	a = Vector3();
	b = Vector3();
	c = Vector3();
}

Face::Face(Vector3 ia, Vector3 ib, Vector3 ic )
{
	a = ia;
	b = ib;
	c = ic;
}

Face::~Face()
{
}