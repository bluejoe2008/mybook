// MessageMapTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMessageMapTestApp:
// �йش����ʵ�֣������ MessageMapTest.cpp
//

class CMessageMapTestApp : public CWinApp
{
public:
	CMessageMapTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMessageMapTestApp theApp;