// ThreadMessageTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CThreadMessageTestApp:
// �йش����ʵ�֣������ ThreadMessageTest.cpp
//

class CThreadMessageTestApp : public CWinApp
{
public:
	CThreadMessageTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CThreadMessageTestApp theApp;