// WM_DRAWITEM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWM_DRAWITEMApp:
// �йش����ʵ�֣������ WM_DRAWITEM.cpp
//

class CWM_DRAWITEMApp : public CWinApp
{
public:
	CWM_DRAWITEMApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWM_DRAWITEMApp theApp;