// WorkerThreadTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWorkerThreadTestApp:
// �йش����ʵ�֣������ WorkerThreadTest.cpp
//

class CWorkerThreadTestApp : public CWinApp
{
public:
	CWorkerThreadTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWorkerThreadTestApp theApp;