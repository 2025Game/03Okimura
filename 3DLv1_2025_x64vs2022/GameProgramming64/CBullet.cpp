#include "CBullet.h"

void CBullet::Collision(CCollider* m, CCollider* o) {
	if (CCollider::Collision(m, o)) {
		mEnabled = false;
	}
}

void CBullet::Set(float w, float d) {
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mT.Normal(CVector(0.0f, 1.0f, 0.0f));
	mT.Vertex(CVector(w, 0, 0), CVector(0, 0, -d), CVector(-w, 0, 0));
}

void CBullet::Update() {
	if (mLife-- > 0) {
		CTransform::Update();
		mPosition = mPosition + CVector(0.0f, 0.0f, 1.0f) * mMatrixRotate;;
	}
	else {
		mEnabled = false;
	}
}

void CBullet::Render() {
	float c[] = { 1.0f,1.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	mT.Render(mMatrix);
}
CBullet::CBullet()
	 :mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.1f)
	, mLife(50)
{};