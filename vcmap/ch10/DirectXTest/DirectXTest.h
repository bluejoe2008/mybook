// DirectXTest.h : DirectXTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDirectXTestApp:
// �йش����ʵ�֣������ DirectXTest.cpp
//

class CDirectXTestApp : public CWinApp
{
public:
	CDirectXTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDirectXTestApp theApp;