// MessageReflectionTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMessageReflectionTestApp:
// �йش����ʵ�֣������ MessageReflectionTest.cpp
//

class CMessageReflectionTestApp : public CWinApp
{
public:
	CMessageReflectionTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMessageReflectionTestApp theApp;