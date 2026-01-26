#include "CEnemy.h"
#define VELOCITY CVector(0.0f,0.0f,0.09f)

CEnemy::CEnemy(CModel* model, const CVector& position,
	const CVector& rotation, const CVector& scale)
	:mCollider1(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), 0.8f)
	, mCollider2(this, &mMatrix, CVector(0.0f, 5.0f, 20.0f), 0.8f)
	, mCollider3(this, &mMatrix, CVector(0.0f, 5.0f, -20.0f), 0.8f)
{

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}

void CEnemy::Update() {
	CTransform::Update();
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}