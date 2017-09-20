#include "Engine3D.h"
#include <iostream>

Engine3D::Engine3D(SDL_Surface* isurface)
{
	surface = isurface;
}

Engine3D::~Engine3D()
{
}

void Engine3D::RenderMeshes()
{
	
}

void Engine3D::AddMesh(Mesh imesh)
{
	meshes.push_back(imesh);
}

void Engine3D::AddMeshes(std::vector<Mesh> imeshes)
{
	for each(Mesh m in imeshes) {
		meshes.push_back(m);
	}
}

std::vector<Mesh> Engine3D::GetMeshes()
{
	return meshes;
}