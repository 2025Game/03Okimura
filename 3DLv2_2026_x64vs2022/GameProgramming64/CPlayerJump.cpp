#include "CPlayerJump.h"
#include "CXCharacter.h"
#define GRAVITY CVector(0.0f, -0.0312f, 0.0f) // 重力加速度
#define JUMP_V CVector(0.0f, 0.6f, 0.0f) // ジャンプ初速
void CPlayerJump::Start(CXCharacter* parent)
{
    // 親ポインタを保存
    mpParent = parent;

    // ジャンプアニメーション
    // アニメーション番号7
    // 繰り返しなし
    // 60フレームで再生
    mpParent->ChangeAnimation(7, false, 60);

    // 状態をジャンプにする
    mState = EState::EJUMP;
    mJumpV = JUMP_V; //ジャンプの初速度
}
void CPlayerJump::Update()
{
    mpParent->Position(mpParent->Position() + mJumpV);
    mJumpV = mJumpV + GRAVITY;
}
void CPlayerJump::Collision(CCollider* m, CCollider* o)
{
    switch (m->Type()) {
    case CCollider::EType::ELINE:
        if (o->Type() ==
            CCollider::EType::ETRIANGLE)
        {
            CVector adjust;
            if (CCollider::CollisionTriangleLine(
                o, m, &adjust))

            {
                mState = EState::EIDLE;
            }
        }
        break;
    }
}