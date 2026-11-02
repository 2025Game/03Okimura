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
			printf("%s", mToken);
			GetToken();
			printf("%s\n", mToken);
		}
		if (strcmp(mToken, "AnimationSet") == 0) {
			printf("%s ", mToken);
			GetToken();
			printf("%s\n", mToken);
		}
	}
	SAFE_DELETE_ARRAY(buf);
}

//CModelXクラスのLoadメソッドにprintf関数を追加