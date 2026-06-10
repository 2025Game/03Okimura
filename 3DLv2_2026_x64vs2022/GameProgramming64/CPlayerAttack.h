#pragma once

#ifndef CPLAYERATTACK_H
#define CPLAYERATTACK_H

#include "CState.h"

class CXCharacter;

class CPlayerAttack : public CState
{
public:
    // 状態開始
    void Start(CXCharacter* parent);

    // 状態更新
    void Update();
};

#endif
