#pragma once
#ifndef CMaterial_H
#define CMaterial_H
#define MATERIAL_NAME_LEN 64

class CMaterial {
public:
	CMaterial();
	void Enabled();
	char* Name();
	void Name(char* name);
	float* Diffuse();
private:
	char mName[MATERIAL_NAME_LEN + 1];
	float mDiffuse[4];
};
#endif