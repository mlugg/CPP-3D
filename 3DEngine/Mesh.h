#pragma once
#include <vector>
#include "Vector3.h"
#include "Face.h"

class Mesh
{
private:
	std::vector<Face> faces;
	double scale;
	Vector3 pos;
	Vector3 rot;
public:
	Mesh(std::vector<Face>);
	Mesh(std::vector<Face>, double);
	~Mesh();
	Vector3 GetPosition();
	void SetPosition(Vector3);
	Vector3 GetRotation();
	void SetRotation(Vector3);
	void SetScale(double);
	double GetScale();
	std::vector<Face> GetFaces();
};

