// ClientAreaTest.h : ClientAreaTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// CClientAreaTestApp:
// �йش����ʵ�֣������ ClientAreaTest.cpp
//

class CClientAreaTestApp : public CWinApp
{
public:
	CClientAreaTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CClientAreaTestApp theApp;