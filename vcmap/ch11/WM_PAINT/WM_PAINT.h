// WM_PAINT.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWM_PAINTApp:
// �йش����ʵ�֣������ WM_PAINT.cpp
//

class CWM_PAINTApp : public CWinApp
{
public:
	CWM_PAINTApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWM_PAINTApp theApp;