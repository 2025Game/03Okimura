#pragma once
#include "CCharacter3.h"
#include "CColliderTriangle.h"
class CCube : public CCharacter3
{
public:
	CCube();
	void Update();
private:
	static CModel msModel;
	CColliderTriangle mCollider[2];
};