// FakeButton.h : FakeButton Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFakeButtonApp:
// �йش����ʵ�֣������ FakeButton.cpp
//

class CFakeButtonApp : public CWinApp
{
public:
	CFakeButtonApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFakeButtonApp theApp;