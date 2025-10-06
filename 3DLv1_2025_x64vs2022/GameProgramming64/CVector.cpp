#include "CVector.h"




CVector::CVector()
:mX(0)
,mY(0)
, mZ(0)
{
}


CVector::CVector(float x, float y, float z)
	:mX(x)
	, mY(y)
	, mZ(z)
{
}



void CVector::Set(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

float CVector::X() const
{
	return mX;
}

float CVector::Y() const
{
	return mY;
}

float CVector::Z() const
{
	return mZ;
}
