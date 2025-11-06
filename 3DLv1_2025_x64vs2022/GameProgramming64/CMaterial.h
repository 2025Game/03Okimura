#pragma once
#ifndef CMaterial_H
#define CMaterial_H
#define MATERIAL_NAME_LEN 64
#include "CTexture.h"

class CMaterial {
public:
	CTexture* Texture();
	void Disabled();
	CMaterial();
	void Enabled();
	char* Name();
	void Name(char* name);
	float* Diffuse();
private:
	CTexture mTexture;
	char mName[MATERIAL_NAME_LEN + 1];
	float mDiffuse[4];
};
#endif