// MyCircle.h : MyCircle Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyCircleApp:
// �йش����ʵ�֣������ MyCircle.cpp
//

class CMyCircleApp : public CWinApp
{
public:
	CMyCircleApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyCircleApp theApp;