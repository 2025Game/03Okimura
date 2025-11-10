#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H

class CMatrix {
public:
	void Print();
	CMatrix();
	CMatrix Identity();
	CMatrix Scale(float sx, float sy,float sz);
	float M(int r, int c)const;
private:
	float mM[4][4];
};
#endif