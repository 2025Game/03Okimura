#include "CPlayer.h"
#include "CApplication.h"
#define ROTATION_YV CVector(0.0f,1.0f,0.0f)
#define VELOCITY CVector(0.0f,0.0f,0.1f)

CPlayer::CPlayer(const CVector& pos, const CVector& rot, const CVector& scale)
{
	CTransform::Update(pos, rot, scale);
}
void CPlayer::Update() {
	if (mInput.Key('D')) {
		mRotation = mRotation - ROTATION_YV;
	}
	if (mInput.Key(VK_UP)) {
		mPosition = mPosition + VELOCITY * mMatrixRotate;
	}
	if (mInput.Key('A')) {
		mRotation = mRotation + ROTATION_YV;
	}
	CTransform::Update();
}
/*void CPlayer::Update()
{
	if (mInput.Key(VK_SPACE))
	{
		CApplication::CharacterManager()->Add(
			new CBullet(X(), Y() + H() + 10.0f
				, 3.0f, 10.0f, 1396, 1420, 750, 592
				, CApplication::Texture()));
	}

	if (mInput.Key('A'))
	{
		float x = X() - 4.0f;
		X(x);
	}
	if (mInput.Key('D'))
	{
		float x = X() + 4.0f;
		X(x);
	}
}
*/