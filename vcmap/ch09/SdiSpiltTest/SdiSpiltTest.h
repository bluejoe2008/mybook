// SdiSpiltTest.h : SdiSpiltTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSdiSpiltTestApp:
// �йش����ʵ�֣������ SdiSpiltTest.cpp
//

class CSdiSpiltTestApp : public CWinApp
{
public:
	CSdiSpiltTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSdiSpiltTestApp theApp;