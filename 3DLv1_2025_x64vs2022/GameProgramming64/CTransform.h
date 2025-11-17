#pragma once
#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include "CVector.h"

class CTransform {
public:
	const CVector& Position() const;
	void Position(const CVector& v);
	void Rotation(const CVector& v);
	void Scale(const CVector& v);
	const CMatrix& Matrix()const;
	const CMatrix& MatrixRotate()const;
	void Update();
	void Update(const CVector& pos, const CVector& rot, const CVector& scale);
protected:
	CVector mPosition;
	CVector mRotation;
	CVector mScale;
	CMatrix mMatrixTranslate;
	CMatrix mMatrixRotate;
	CMatrix mMatrixScale;
	CMatrix mMatrix;
};
#endif