#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
class CTriangle {
public:
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	int MaterialIdx();
	void MaterialIdx(int idx);
	void Vertex(const CVector& v0, const CVector& v1, const CVector& v2);
	void Normal(const CVector &n);
	void Render();
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
	CVector mUv[3];
	int mMaterialIdx;
	CVector mV[3];
	CVector mN[3];
};


#endif 

