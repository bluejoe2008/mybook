// SdiTest.h : SdiTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSdiTestApp:
// �йش����ʵ�֣������ SdiTest.cpp
//

class CSdiTestApp : public CWinApp
{
public:
	CSdiTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSdiTestApp theApp;