#include "CTaskManager.h"
CTaskManager* CTaskManager::mpInstance = nullptr;
CTaskManager* CTaskManager::Instance()
{
	if (mpInstance == nullptr)
	{
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}
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
void CTaskManager::Remove(CTask* task) {
	task->mpPrev->mpNext = task->mpNext;
	task->mpNext->mpPrev = task->mpPrev;
}
void CTaskManager::Delete() {
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		CTask* del = task;
		task = task->mpNext;
		if (del->mEnabled == false) {
			delete del;
		}
	}
}