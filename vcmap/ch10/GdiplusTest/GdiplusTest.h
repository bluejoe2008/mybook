// GdiplusTest.h : GdiplusTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGdiplusTestApp:
// �йش����ʵ�֣������ GdiplusTest.cpp
//

class CGdiplusTestApp : public CWinApp
{
public:
	CGdiplusTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGdiplusTestApp theApp;