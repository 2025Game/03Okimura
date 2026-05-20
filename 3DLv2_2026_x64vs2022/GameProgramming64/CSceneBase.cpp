#include "CSceneBase.h"

// コンストラクタ
CSceneBase::CSceneBase(EScene scene)
    : mSceneType(scene)
{
}
// シーンの種類を取得
EScene CSceneBase::GetSceneType() const
{
    return mSceneType;
}