#include "CApplication.h"
#include "CRectangle.h"
#include "CInput.h"
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CMatrix.h"
#include "CTransform.h"


#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl"
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"

CCharacterManager CApplication::mCharacterManager;
CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

void CApplication::Start()
{
	mEye = CVector(1.0f, 2.0f, 3.0f);
	mModel.Load(MODEL_OBJ);
	mBackGround.Load(MODEL_BACKGROUND);
	CMatrix matrix;
	matrix.Print();
	
	mPlayer.Model(&mModel);
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f));
	mPlayer.Rotation(CVector(0.0f, 180.0f, 0.0f));

}

void CApplication::Update()
{
	//mPlayer.Update();
	mTaskManager.Update();
	CVector e, c, u;
	e = mPlayer.Position() + CVector(0, 1, -3) * mPlayer.MatrixRotate();
	c = mPlayer.Position();
	u = CVector(0, 1, 0) * mPlayer.MatrixRotate();
		gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	//mPlayer.Render();

	CVector v0, v1, v2, n;
	n.Set(0.0f, 1.0f, 0.0f);
	v0.Set(0.0f, 0.0f, 0.5f);
	v1.Set(1.0f, 0.0f, 0.0f);
	v2.Set(0.0f, 0.0f, -0.5f);
	if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('O'))
	{
		mEye = mEye + CVector(0.0f, 0.1f, 0.0f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye - CVector(0.0f, 0.1f, 0.0f);
	}



	
	/*CMatrix matrix, position, rotation, scale;
	position.Translate(0.5f, 1.8f, 0.5f);
	rotation.RotateY(180.0f);
	scale.Scale(0.1f, 0.1f, 0.1f);
	matrix = scale * rotation * position;*/
	/*CTransform trans;
	trans.Position(CVector(0.5f, 1.8f, 0.5f));
	trans.Rotation(CVector(-10.0f, -20.0f, -30.0f));
	trans.Scale(CVector(0.1f, 0.1f, 0.1f));
	trans.Update();
	mModel.Render(trans.Matrix());*/

	
	
	mBackGround.Render();
	/*mPlayer.bullet.Update();
	mPlayer.bullet.Render();*/
	mTaskManager.Update();
	mTaskManager.Render();
}

CTaskManager CApplication::mTaskManager;
CTaskManager* CApplication::TaskManager()
{
	return &mTaskManager;
}
 