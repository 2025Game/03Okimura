#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
class CTriangle {
public:
	const CVector& V0()const;
	const CVector& V1()const;
	const CVector& V2()const;
	const CVector& N0()const;
	const CVector& N1()const;
	const CVector& N2()const;
	const CVector& U0()const;
	const CVector& U1()const;
	const CVector& U2()const;
	void Render(const CMatrix& m);
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

