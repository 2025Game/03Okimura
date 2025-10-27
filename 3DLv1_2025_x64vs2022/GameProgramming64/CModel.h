#pragma once
#ifndef CMODEL_H
#define CMODEL_H
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"

class CModel {
public:
	~CModel();
	void Load(const char* obj, const char* mtl);
	void Render();
private:
	std::vector<CTriangle> mTriangles;
	std::vector<CMaterial*>mpMaterials;
};

#endif