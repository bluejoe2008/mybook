// HtmlDialogTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHtmlDialogTestApp:
// �йش����ʵ�֣������ HtmlDialogTest.cpp
//

class CHtmlDialogTestApp : public CWinApp
{
public:
	CHtmlDialogTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHtmlDialogTestApp theApp;