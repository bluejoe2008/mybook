// OpenGLTest.h : OpenGLTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// COpenGLTestApp:
// �йش����ʵ�֣������ OpenGLTest.cpp
//

class COpenGLTestApp : public CWinApp
{
public:
	COpenGLTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpenGLTestApp theApp;