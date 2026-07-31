#include "CPaladin.h"

// staticメンバの定義
CModelX CPaladin::msModel;
#define PALADIN_MODEL "res\\paladin\\Paladin WProp J Nordstrom@Idle.fbx.x"
CPaladin::CPaladin(const CVector& pos, const CVector& rot,

	const CVector& scale)
	: mCollider(this, &mCombinedMatrix, CVector(0.0f, 4.0f, 0.0f),
		CVector(0.0f, 0.0f, 0.0f), 0.5f)

{
	static bool first = true;
	if (first)
	{
		msModel.Load(PALADIN_MODEL);
		first = false;
	}
	Init(&msModel);
	mPosition = pos;
	mRotation = rot;
	mScale = scale;
}
void CPaladin::Update()
{
	// 親クラスの更新
	CXCharacter::Update();

	// カプセルコライダの更新
	mCollider.Update();
}