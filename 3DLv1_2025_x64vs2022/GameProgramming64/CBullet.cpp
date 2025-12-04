#include "CBullet.h"

void CBullet::Set(float w, float d) {
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mT.Normal(CVector(0.0f, 1.0f, 0.0f));
	mT.Vertex(CVector(w, 0, 0), CVector(0, 0, -d), CVector(-w, 0, 0));
}

void CBullet::Update() {
	CTransform::Update();
	mPosition = mPosition + CVector(0, 0, 1) * mMatrixRotate;
}

void CBullet::Render() {
	float c[] = { 1.0f,1.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	mT.Render(mMatrix);
}