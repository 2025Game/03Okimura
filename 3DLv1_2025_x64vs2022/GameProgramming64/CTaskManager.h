#pragma once
#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
#include "CTask.h"

class CTaskManager {
public:
	virtual~CTaskManager();
	void Add(CTask* addTask);
	void Update();

	void Render();
	CTaskManager();
protected:
	CTask mHead;
	CTask mTail;
};
#endif