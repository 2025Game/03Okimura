#pragma once
#ifndef CSCENEBASE_H
#define CSCENEBASE_H
#include "EScene.h"

class CSceneBase
{
public:
	CSceneBase(EScene scene);
	virtual ~CSceneBase() {};
	virtual void Losd() = 0;
	virtual void Update() = 0;
	EScene GetSceneType() const;
private:
	EScene mSceneType;
};

#endif