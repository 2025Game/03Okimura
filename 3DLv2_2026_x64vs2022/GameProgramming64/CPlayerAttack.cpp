#include "CPlayerAttack.h"
#include "CXCharacter.h"

void CPlayerAttack::Start(CXCharacter* parent)
{
    // 親ポインタを保存
    mpParent = parent;

    // 攻撃アニメーションへ変更
    // アニメーション番号3
    // 繰り返しなし
    // 30フレームで再生
    mpParent->ChangeAnimation(3, false, 30);

    // 状態を攻撃にする
    mState = EState::EATTACK;
}
void CPlayerAttack::Update()
{
    if (mpParent->IsAnimationFinished())
    {
        mState = EState::EIDLE;
    }
}