#include "CTaskManager.h"
CTaskManager::CTaskManager()
{
	mHead.mpNext = &mTail;
	mTail.mpPrev = &mHead;
}
CTaskManager::~CTaskManager()
{
}
void CTaskManager::Add(CTask* addTask)
{
	CTask* task = &mTail;
	addTask->mpNext = task;
	addTask->mpPrev = task->mpPrev;
	addTask->mpPrev->mpNext = addTask;
	task->mpPrev = addTask;
}
void CTaskManager::Update()
{
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		task->Update();
		task = task->mpNext;
	}
}
void CTaskManager::Render()
{
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		task->Render();
		task = task->mpNext;
	}
}