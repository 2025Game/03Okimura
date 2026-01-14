#pragma once
#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
#include "CTask.h"

class CTaskManager {
public:
	void Remove(CTask *task);
	void Delete();
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