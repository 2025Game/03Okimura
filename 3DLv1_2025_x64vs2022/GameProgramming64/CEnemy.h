#pragma once
#ifndef CENEMY_H
#define CENEMY_H
#include "CCharacter3.h"
#include "CCollider.h"


class CEnemy : public CCharacter3
{
public:
	CEnemy(CModel* model, const CVector& posirion,
		const CVector& rotation, const CVector& scale);
	void Update();
	void Render() {
		CCharacter3::Render();
		mCollider1.Render();
		mCollider2.Render();
		mCollider3.Render();
	}
private:
	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;
};
#endif