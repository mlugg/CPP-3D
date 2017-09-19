#pragma once
#include <SDL.h>
#include <vector>
#include "Mesh.h"

class Engine3D
{
private:
	std::vector<Mesh> meshes;
public:
	Engine3D(SDL_Surface*);
	~Engine3D();
	void RenderMeshes();
	void AddMesh(Mesh);
	void AddMeshes(std::vector<Mesh>);
};