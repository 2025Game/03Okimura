#pragma once
#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H

#include "CTaskManager.h"

class CCollisionManager:public CTaskManager
{
public:
	void Collision();
	static CCollisionManager* Instance();
private:
	static CCollisionManager* mpInstance;
};
#endif