#pragma once
#ifndef CMATRIX_H
#define CMATRIX_H

class CMatrix {
public:
	void Print();
	CMatrix();
	CMatrix Identity();
private:
	float mM[4][4];
};
#endif