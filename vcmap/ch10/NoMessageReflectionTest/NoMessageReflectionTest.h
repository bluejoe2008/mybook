// NoMessageReflectionTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNoMessageReflectionTestApp:
// �йش����ʵ�֣������ NoMessageReflectionTest.cpp
//

class CNoMessageReflectionTestApp : public CWinApp
{
public:
	CNoMessageReflectionTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNoMessageReflectionTestApp theApp;