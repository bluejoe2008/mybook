// AdodcTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAdodcTestApp:
// �йش����ʵ�֣������ AdodcTest.cpp
//

class CAdodcTestApp : public CWinApp
{
public:
	CAdodcTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAdodcTestApp theApp;