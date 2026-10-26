#pragma once
#ifndef CMODELX_H
#define CMODELX_H

#define MODEL_FILE "res\\sample.blend.x"

#define SAFE_DELETE_ARRAY(a){if(a)delete[]a;a=nullptr;}

class CModelX {
public:
	CModelX();
	void Load(const char* file);
private:
	char* mpPointer;
	char mToken[1024];
};

#endif