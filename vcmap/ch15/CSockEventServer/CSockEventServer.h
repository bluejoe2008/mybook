// CSockEventServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCSockEventServerApp:
// �йش����ʵ�֣������ CSockEventServer.cpp
//

class CCSockEventServerApp : public CWinApp
{
public:
	CCSockEventServerApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCSockEventServerApp theApp;