#pragma once
#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "CCharacter3.h"

class CCollider :public CTransform {
public:
	CCollider(CCharacter3* parent, CMatrix* maatrix,
		const CVector& position, float radius);
	CCharacter3* Parent();
	void Render();
protected:
	CCharacter3* mpParent;
	CMatrix* mpMatrix;
	float mRadius;
};
#endif