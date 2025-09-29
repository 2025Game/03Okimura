#pragma once
#ifndef CVECTOR_H
#define CVECTOR_H

class CVector {
public:
	
	void Set(float x, float y, float z);
	float X() const;
	float Y() const;
	float Z() const;
private:
	float mX, mY, mZ;
};
#endif
