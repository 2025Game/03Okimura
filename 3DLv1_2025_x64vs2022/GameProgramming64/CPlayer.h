#pragma once
#ifndef CPLAYER_H
#define CPLAYER_H
#include "CCharacter3.h"
#include "CCharacter.h"
#include "CInput.h"
#include "CBullet.h"
class CPlayer :public CCharacter3 {
public:
	//CBullet bullet;
	CPlayer(){}
	CPlayer(const CVector& pos, const CVector& rot, const CVector& scale);
	void Update();
private:
	CInput mInput;
};
#endif
/*class CPlayer : public CCharacter
{
public:
	void Update();
private:
	CInput mInput;


};*/
