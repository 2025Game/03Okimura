#pragma once
#ifndef CMODEL_H
#define CMODEL_H
#include <vector>
#include "CTriangle.h"

class CModel {
public:
	void Load(const char* obj, const char* mtl);
	void Render();
private:
	std::vector<CTriangle> mTriangles;
};

#endif