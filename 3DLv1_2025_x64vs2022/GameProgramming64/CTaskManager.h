#pragma once
#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
#include "CTask.h"

class CTaskManager {
public:
	static CTaskManager* Instance();
	void Remove(CTask *task);
	void Delete();
	virtual~CTaskManager();
	void Add(CTask* addTask);
	void Update();

	void Render();
	
protected:
	CTaskManager();
	CTask mHead;
	CTask mTail;
private:
	static CTaskManager* mpInstance;
};
#endif