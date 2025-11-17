#include "CPlayer.h"
#define ROTATION_YV CVector(0.0f,1.0f,0.0f)
#define VELOCITY CVector(0.0f,0.0f,0.1f)

CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
{
	CTransform::Update(pos, rot, scale);
}
void CPlayer::Update()
{
	if (mInput.Key('D'))
	{
		mRotation = mRotation - ROTATION_YV;
	}
	if (mInput.Key(VK_UP)) {
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key('A'))
	{
		mRotation = mRotation + ROTATION_YV;
	}
	CTransform::Update();
}
