// WM_ERASEBKGND.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWM_ERASEBKGNDApp:
// �йش����ʵ�֣������ WM_ERASEBKGND.cpp
//

class CWM_ERASEBKGNDApp : public CWinApp
{
public:
	CWM_ERASEBKGNDApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWM_ERASEBKGNDApp theApp;