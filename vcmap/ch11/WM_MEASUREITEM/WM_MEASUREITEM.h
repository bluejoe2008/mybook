// WM_MEASUREITEM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWM_MEASUREITEMApp:
// �йش����ʵ�֣������ WM_MEASUREITEM.cpp
//

class CWM_MEASUREITEMApp : public CWinApp
{
public:
	CWM_MEASUREITEMApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWM_MEASUREITEMApp theApp;