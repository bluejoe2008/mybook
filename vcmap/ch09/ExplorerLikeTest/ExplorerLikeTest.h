// ExplorerLikeTest.h : ExplorerLikeTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExplorerLikeTestApp:
// �йش����ʵ�֣������ ExplorerLikeTest.cpp
//

class CExplorerLikeTestApp : public CWinApp
{
public:
	CExplorerLikeTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExplorerLikeTestApp theApp;