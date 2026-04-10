#include "CCollider.h"
#include "CCollisionManager.h"

bool CCollider::Collision(CCollider* m, CCollider* o) {
	CVector mpos = m->mPosition * *m->mpMatrix;
	CVector opos = o->mPosition * *o->mpMatrix;
	mpos = mpos - opos;
	if (m->mRadius + o->mRadius > mpos.Length()) {
		return  true;
	}
	return false;
}

CCollider::CCollider(CCharacter3* parent, CMatrix* matrix,
	const CVector& position, float radius) {
	CCollisionManager::Instance()->Add(this);
	mpParent = parent;
	mpMatrix = matrix;
	mPosition = position;
	mRadius = radius;
}

CCharacter3* CCollider::Parent()
{
	return mpParent;
}

void CCollider::Render() {
	glPushMatrix();
	CVector pos = mPosition * *mpMatrix;
	glMultMatrixf(CMatrix().Translate(pos.X(),pos.Y(), pos.Z()).M());
	float c[] = { 1.0f,0.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	glutWireSphere(mRadius, 16, 16);
	glPopMatrix();
}
CCollider::~CCollider() {
	CCollisionManager::Instance()->Remove(this);
}