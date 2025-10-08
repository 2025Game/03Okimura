#include "CModel.h"
#include <stdio.h>

void CModel::Load(const char* obj, const char* mtl) {
	FILE* fp;
	char buf[256];
	fp = fopen(mtl, "r");
	if (fp == NULL) {
		printf("%s file open error\n,mtl");
		return;
	}
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		printf("%s", buf);
	}
	fp = fopen(obj, "r");
	if (fp == NULL) {
		printf("%s file open error\n,obj");
		return;
	}
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		printf("%s", buf);
	}
	fclose(fp);
}