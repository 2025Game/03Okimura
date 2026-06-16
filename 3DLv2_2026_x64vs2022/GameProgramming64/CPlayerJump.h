#pragma once
#ifndef CPLAYERJUMP_H
#define CPLAYERJUMP_H
#include "CCollider.h"
#include "CState.h"

class CXCharacter;

// ジャンプ状態クラス
class CPlayerJump : public CState
{
public:
    // 状態開始
    void Start(CXCharacter* parent);

    // 状態更新
    void Update();
    void Collision(CCollider* m, CCollider* o) override;
private:
    CVector mJumpV; //ジャンプの速度
};

#endif