#include "CTransform.h"

const CVector& CTransform::Position()const
{
	return mPosition;
}
void CTransform::Position(const CVector& v)
{
	mPosition = v;
}
void CTransform::Rotation(const CVector& v)
{
	mRotation = v;
}
void CTransform::Scale(const CVector& v)
{
	mScale = v;
}
const CMatrix& CTransform::Matrix()const
{
	return mMatrix;
}
const CMatrix& CTransform::MatrixRotate()const
{
	return mMatrixRotate;
}
void CTransform::Update(const CVector& pos, const CVector& rot, const CVector& scale)
{
	mPosition = pos;
	mRotation = rot;
	mScale = scale;
	Update();
}
void CTransform::Update() {
	mMatrixScale.Scale(mScale.X(), mScale.Y(), mScale.Z());
	mMatrixRotate =
		CMatrix().RotateZ(mRotation.Z())*
		CMatrix().RotateX(mRotation.X())*
		CMatrix().RotateY(mRotation.Y());
	mMatrixTranslate.Translate(mPosition.X(), mPosition.Y(), mPosition.Z());
	mMatrix = mMatrixScale * mMatrixRotate * mMatrixTranslate;
}