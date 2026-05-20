#pragma once
#ifndef CSCENEBASE_H
#define CSCENEBASE_H
#include "EScene.h"
class CTask;

class CSceneBase
{
public:
	CSceneBase(EScene scene);
	virtual ~CSceneBase() {};
	virtual void Load() = 0;
	virtual void Update() = 0;
	EScene GetSceneType() const;
private:
	EScene mSceneType;
};

#endif