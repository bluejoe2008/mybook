// TrayIconTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTrayIconTestApp:
// �йش����ʵ�֣������ TrayIconTest.cpp
//

class CTrayIconTestApp : public CWinApp
{
public:
	CTrayIconTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTrayIconTestApp theApp;