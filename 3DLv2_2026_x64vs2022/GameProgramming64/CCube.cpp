#include "CCube.h"
#define MODEL_CUBE "res\\cube.obj", "res\\cube.mtl"
CModel CCube::msModel;

CCube::CCube()
{
	if (msModel.Triangles().empty()) {
		msModel.Load(MODEL_CUBE);
	}
	mpModel = &msModel;
	mCollider[0].Set(
		this,
		&mMatrix,
		CVector(-1.0f, 2.0f, -1.0f), 
		CVector(1.0f, 2.0f, 1.0f),
		CVector(1.0f, 2.0f, -1.0f)
		);
	mCollider[1].Set(
		this,
		&mMatrix,
		CVector(-1.0f, 2.0f, -1.0f),
		CVector(-1.0f, 2.0f, 1.0f),
		CVector(1.0f, 2.0f, 1.0f)
		);
}
void CCube::Update()
{
	Rotation(Rotation() + CVector(0.0f, 1.0f, 0.0f));
	CTransform::Update();
}