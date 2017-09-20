#pragma once
#include <SDL.h>
#include <vector>
#include "Mesh.h"
#include <CL\cl2.hpp>

class Engine3D
{
private:
	std::vector<Mesh> meshes;
	SDL_Surface* surface;
public:
	Engine3D(SDL_Surface*);
	~Engine3D();
	void RenderMeshes();
	void AddMesh(Mesh);
	void AddMeshes(std::vector<Mesh>);
	std::vector<Mesh> GetMeshes();
};