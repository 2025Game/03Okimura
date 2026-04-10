#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H
#include "CMatrix.h"

class CVector {
public:
	float Length() const;
	CVector operator*(const CMatrix& m)const;
	CVector operator-(const CVector& v)const;
	CVector operator+(const CVector& v)const;
	CVector();
	CVector(float x, float y, float z);
	void Set(float x, float y, float z);
	float X() const;
	float Y() const;
	float Z() const;
private:
	float mX, mY, mZ;
};
#endif
