#pragma once
#ifndef CENEMY_H
#define CENEMY_H
#include "CCharacter3.h"

class CEnemy : public CCharacter3
{
public:
	CEnemy(CModel* model, const CVector& posirion,
		const CVector& rotation, const CVector& scale);
	void Update();
};
#endif