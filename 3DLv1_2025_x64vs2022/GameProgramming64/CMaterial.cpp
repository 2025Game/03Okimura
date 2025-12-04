#include "CMaterial.h"
#include<string.h>
#include "glut.h"

char* strncpy(char* str1, const char* str2, int len)
{
	int i = 0;
	while (i < len && *str2 != '\0')
	{
		*(str1 + i) = *str2;
		str2++;
		i++;
	}
	str1[i] = '\0'; 
	return str1;
}

CMaterial::CMaterial() 
	:mVertexNum(0)
{
	memset(mName, 0, sizeof(mName));
	memset(mDiffuse, 0, sizeof(mDiffuse));
}
void CMaterial::Enabled() {
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuse);
	if (mTexture.Id())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, mTexture.Id());
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}
char* CMaterial::Name()
{
	return mName;
}
void CMaterial::Name(char* name)
{
	strncpy(mName, name, MATERIAL_NAME_LEN);
}
float* CMaterial::Diffuse()
{
	return mDiffuse;
}
void CMaterial::Disabled() {
	if (mTexture.Id())
	{
		glDisable(GL_BLEND);
		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}
}
void CMaterial::VertexNum(int num)
{
	mVertexNum = num;
}
int CMaterial::VertexNum()
{
	return mVertexNum;
}
CTexture* CMaterial::Texture()
{
	return &mTexture;
}