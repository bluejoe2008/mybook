// OpenGLTestDoc.cpp : COpenGLTestDoc ���ʵ��
//

#include "stdafx.h"
#include "OpenGLTest.h"

#include "OpenGLTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLTestDoc

IMPLEMENT_DYNCREATE(COpenGLTestDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLTestDoc, CDocument)
END_MESSAGE_MAP()


// COpenGLTestDoc ����/����

COpenGLTestDoc::COpenGLTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

COpenGLTestDoc::~COpenGLTestDoc()
{
}

BOOL COpenGLTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	glNewList(ArmPart2, GL_COMPILE);

	GLfloat sgenparams[]={1.0,1.0,1.0,0.0};
	#define TEXTUREWIDTH 64
	GLubyte Texture[3*TEXTUREWIDTH];
	int i;
	for(i=0;i<TEXTUREWIDTH;i++)
	{
		Texture[3*i] =255;
		Texture[3*i+1] =255-2*i;
		Texture[3*i+2] =255;
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_1D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage1D(GL_TEXTURE_1D,0,3,TEXTUREWIDTH,0,
		GL_RGB,GL_UNSIGNED_BYTE,Texture);

	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
	glTexGenfv(GL_S,GL_OBJECT_PLANE,sgenparams);

	glEnable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_GEN_S);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glMaterialf(GL_FRONT,GL_SHININESS,64.0);
	glRotatef(30.0,1.0,0.0,0.0);

	auxSolidTeapot(1.5);
	glEndList();
	return TRUE;
}




// COpenGLTestDoc ���л�

void COpenGLTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// COpenGLTestDoc ���

#ifdef _DEBUG
void COpenGLTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

void COpenGLTestDoc::RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslated(0.0, 0.0, -8.0);
	glCallList(ArmPart2);
	glPopMatrix();
	glFlush();
}

// COpenGLTestDoc ����
