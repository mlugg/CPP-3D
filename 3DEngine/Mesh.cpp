#include "Mesh.h"

Mesh::Mesh(std::vector<Face> ifaces)
{
	faces = ifaces;
	scale = 1;
}

Mesh::Mesh(std::vector<Face> ifaces, double iscale)
{
	faces = ifaces;
	scale = iscale;
}

Mesh::~Mesh()
{
}

void Mesh::SetPosition(Vector3 ipos)
{
	pos = ipos;
}

Vector3 Mesh::GetPosition()
{
	return pos;
}

void Mesh::SetRotation(Vector3 irot)
{
	rot = irot;
}

Vector3 Mesh::GetRotation()
{
	return rot;
}

void Mesh::SetScale(double iscale)
{
	scale = iscale;
}

double Mesh::GetScale()
{
	return scale;
}

std::vector<Face> Mesh::GetFaces() {
	return faces;
}