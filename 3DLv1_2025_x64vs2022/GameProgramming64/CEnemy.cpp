#include "CEnemy.h"
#define VELOCITY CVector(0.0f,0.0f,0.09f)

void CEnemy::Collision(CCollider* m, CCollider* o) {
	//ƒRƒ‰ƒCƒ_‚Ìm‚Æo‚ªÕ“Ë‚µ‚Ä‚¢‚é‚©”»’è
	if (CCollider::Collision(m, o)) {
		//Õ“Ë‚µ‚Ä‚¢‚é‚Í–³Œø‚É‚·‚é
		mEnabled = false;
	}
}


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
/*void Render() {
	CCharacter3::Render();
	mCollider1.Render();
	mCollider2.Render();
	mCollider3.Render();
}*/
void CEnemy::Update() {
	CTransform::Update();
	mPosition = mPosition + VELOCITY * mMatrixRotate;
}