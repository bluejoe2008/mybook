// MessageRouteTest.h : MessageRouteTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMessageRouteTestApp:
// �йش����ʵ�֣������ MessageRouteTest.cpp
//

class CMessageRouteTestApp : public CWinApp
{
public:
	CMessageRouteTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileOpen();
};

extern CMessageRouteTestApp theApp;