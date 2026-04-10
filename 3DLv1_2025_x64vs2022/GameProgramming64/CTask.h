#pragma once
#ifndef CTASK_H
#define CTASK_H
class CCollisionManager;
class CTaskManager;
class CTask {
	friend CCollisionManager;
	friend CTaskManager;
public:
	CTask()
		:mpNext(nullptr), mpPrev(nullptr), mPriority(0), mEnabled(true)
	{}
	virtual~CTask() {}
	virtual void Update() {}
	virtual void Render() {}
protected:
	int mPriority;
	bool mEnabled;
private:
	CTask* mpNext;
	CTask* mpPrev;
};

#endif