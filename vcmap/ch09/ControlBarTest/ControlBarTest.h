// ControlBarTest.h : ControlBarTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CControlBarTestApp:
// �йش����ʵ�֣������ ControlBarTest.cpp
//

class CControlBarTestApp : public CWinApp
{
public:
	CControlBarTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CControlBarTestApp theApp;