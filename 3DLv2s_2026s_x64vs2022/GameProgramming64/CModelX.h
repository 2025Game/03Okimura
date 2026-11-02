#pragma once
#ifndef CMODELX_H
#define CMODELX_H
#include <vector>
#include "CMatrix.h"

#define MODEL_FILE "res\\sample.blend.x"

#define SAFE_DELETE_ARRAY(a){if(a)delete[]a;a=nullptr;}

class CModelX;
class CModelXFrame;

class CModelXFrame {
	friend CModelX;
public:
	CModelXFrame(CModelX* model);
	~CModelXFrame();
private:
	std::vector<CModelXFrame*> mChild;
	CMatrix mTransformMatrix;
	char* mpName;
	int mIndex;
};

class CModelX {
	friend CModelXFrame;
public:
	void SkipNode();
	char* GetToken();
	CModelX();
	~CModelX();
	void Load(const char* file);
private:
	std::vector<CModelXFrame*> mFrame;
	bool IsDelimiter(char c);
	char* mpPointer;
	char mToken[1024];
};

#endif