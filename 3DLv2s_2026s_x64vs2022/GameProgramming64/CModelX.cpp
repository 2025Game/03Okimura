#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <cstdio>
#include <ctype.h>

bool CModelX::IsDelimiter(char c)
{
	if (isspace(c) != 0)
		return true;
	if (strchr(",;\"", c) != NULL)
		return true;
	return false;
}

char* CModelX::GetToken() {
	char* p = mpPointer;
	char* q = mToken;
	while (*p != '\0' && IsDelimiter(*p)) p++;
	if (*p == '{' || *p == '}') {
		*q++ = *p++;
	}
	else {
		while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
			*q++ = *p++;
	}

	*q = '\0';
	mpPointer = p;	
	if (!strcmp("//", mToken)) {
		while (*p != '\0' && !strchr("\r\n", *p)) p++;
		mpPointer = p;
		return GetToken();
	}
	return mToken;
}


CModelX::CModelX()
	:mpPointer(nullptr)
{
	memset(mToken, 0, sizeof(mToken));
}

void CModelX::Load(const char* file) {
	std::printf("CModelX::Load() called\n");
	FILE* fp;
	fp = fopen(file, "rb");
	if (fp == NULL) {
		printf("fopen error:%s\n", file);
		return;
	}

	fseek(fp, 0L, SEEK_END);
	int size = ftell(fp);
	char* buf = mpPointer = new char[size + 1];
	fseek(fp, 0L, SEEK_SET);
	fread(buf, size, 1, fp);
	buf[size] = '\0';
	fclose(fp);

	while (*mpPointer != '\0') {
		GetToken();
		if (strcmp(mToken, "Frame") == 0) {
			new CModelXFrame(this);
		}
	}
	SAFE_DELETE_ARRAY(buf);
}

CModelXFrame::~CModelXFrame()
{
	//子フレームを全て解放する
	std::vector<CModelXFrame*>::iterator itr;
	for (itr = mChild.begin(); itr != mChild.end(); itr++) {
		delete* itr;
	}
	//名前のエリアを解放する
	SAFE_DELETE_ARRAY(mpName);
}

CModelX::~CModelX()
{
	if (mFrame.size() > 0)
	{
		delete mFrame[0];
	}
}

void CModelX::SkipNode() {
	while (*mpPointer != '\0') {
		GetToken();
		if (strchr(mToken, '{')) break;
	}
	int count = 1;
	while (*mpPointer != '\0' && count > 0) {
		GetToken();
		if (strchr(mToken, '{')) count++;
		else if (strchr(mToken, '}')) count--;
	}
}

CModelXFrame::CModelXFrame(CModelX* model)
	: mpName(nullptr)
	, mIndex(0)
{
	mIndex = model->mFrame.size();
	model->mFrame.push_back(this);
	mTransformMatrix.Identity();
	model->GetToken();
	mpName = new char[strlen(model->mToken) + 1];
	strcpy(mpName, model->mToken);
	model->GetToken(); {
		while (*model->mpPointer != '\0') {
			model->GetToken();
			if (strchr(model->mToken, '}')) break;
			if (strcmp(model->mToken, "Frame") == 0) {
				mChild.push_back(
					new CModelXFrame(model));
			}
			else {
				model->SkipNode();
			}
		}

#ifdef _DEBUG
		printf("%s\n", mpName);
#endif
	}
}



