// CommDlgTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCommDlgTestApp:
// �йش����ʵ�֣������ CommDlgTest.cpp
//

class CCommDlgTestApp : public CWinApp
{
public:
	CCommDlgTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCommDlgTestApp theApp;