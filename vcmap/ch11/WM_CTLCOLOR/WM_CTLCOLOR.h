// WM_CTLCOLOR.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWM_CTLCOLORApp:
// �йش����ʵ�֣������ WM_CTLCOLOR.cpp
//

class CWM_CTLCOLORApp : public CWinApp
{
public:
	CWM_CTLCOLORApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWM_CTLCOLORApp theApp;