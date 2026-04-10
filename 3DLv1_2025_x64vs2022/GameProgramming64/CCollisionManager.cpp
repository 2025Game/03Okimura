#include "CCollisionManager.h"
#include "CCollider.h"

void CCollisionManager::Collision() {
	CCollider* task = (CCollider*)mHead.mpNext;
	while (task->mpNext) {
		CCollider* next = (CCollider*)task->mpNext;
		while (next->mpNext) {
			if (task->mpParent)
				task->mpParent->Collision(task, next);
			if (next->mpParent)
				next->mpParent->Collision(next, task);
			next = (CCollider*)next->mpNext;
		}
		task = (CCollider*)task->mpNext;
	}
}

CCollisionManager* CCollisionManager::mpInstance = nullptr;
CCollisionManager* CCollisionManager::Instance()
{
	if (mpInstance == nullptr)
	{
		mpInstance = new CCollisionManager();
	}
	return mpInstance;
}