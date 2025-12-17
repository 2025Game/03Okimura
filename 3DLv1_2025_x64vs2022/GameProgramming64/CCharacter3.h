#pragma once
#ifndef CCHARACTER3_H
#define CCHARACTER3_H
#include "CTransform.h"
#include "CModel.h"
#include "CTask.h"

class CCharacter3 :public CTransform,public CTask {
public:
	void Model(CModel* m);
	void Render();
protected:
	CModel* mpModel;
};
#endif