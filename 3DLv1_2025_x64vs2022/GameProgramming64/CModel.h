#pragma once
#ifndef CMODEL_H
#define CMODEL_H
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
#include "CVertex.h"

class CModel {
public:
	void Render(const CMatrix& m);
	~CModel();
	void Load(const char* obj, const char* mtl);
	void Render();
private:
	CVertex* mpVertexes;
	void CreateVertexBuffer();
	std::vector<CTriangle> mTriangles;
	std::vector<CMaterial*>mpMaterials;
};

#endif