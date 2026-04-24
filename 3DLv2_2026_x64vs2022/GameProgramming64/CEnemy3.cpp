#include"CEnemy3.h"
#include "CEffect.h"
#include "CCollisionManager.h"
#include "CPlayer.h"
#define OBJ "res\\f16.obj"
#define MTL "res\\f16.mtl"

CModel CEnemy3::sModel;
CEnemy3::CEnemy3()
	:CCharacter3(1)
	, mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.4f)
{
	if (sModel.Triangles().size() == 0)
	{
		sModel.Load(OBJ, MTL);
	}
	mpModel = &sModel;
}
CEnemy3::CEnemy3(const CVector& position, const CVector& rotation, const CVector& scale)
	:CEnemy3()
{
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CTransform::Update();
}
void CEnemy3::Update()
{
	CPlayer* player = CPlayer::Instance();
	if (player != nullptr)
	{
		CVector vp = player->Position() - mPosition;
		float dx = vp.Dot(mMatrixRotate.VectorX());
		float dy = vp.Dot(mMatrixRotate.VectorY());
		float dz = vp.Dot(mMatrixRotate.VectorZ());
		float distance = vp.Length();
		if (-2.0f < dx && dx < 2.0f)
		{
			if (-2.0f < dy && dy < 2.0f)
			{
				if (dz > 0.0f && distance < 30.0f)
				{
					CBullet* bullet = new CBullet();
					bullet->Set(0.1f, 1.5f);
					bullet->Position(
						CVector(0.0f, 0.0f, 10.0f) * mMatrix);
					bullet->Rotation(mRotation);
					bullet->Update();
				}
			}
		}
	}
}
void CEnemy3::Collision(CCollider* m, CCollider* o)
{
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE:
		if (CCollider::Collision(m, o)) {
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
		break;
	case CCollider::EType::ETRIANGLE:
		CVector adjust; 
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{	
			mPosition = mPosition + adjust;
		}
		break;
	}
}
void CEnemy3::Collision()
{
	mCollider.ChangePriority();
	//Õ“Ëˆ—‚ðŽÀs
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}