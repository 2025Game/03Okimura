#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <cstdio>

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

	printf("%s", buf);
	SAFE_DELETE_ARRAY(buf);
}
//CModelXクラスのLoadメソッドにprintf関数を追加