// MfcTest.h : MfcTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMfcTestApp:
// �йش����ʵ�֣������ MfcTest.cpp
//

class CMfcTestApp : public CWinApp
{
public:
	CMfcTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMfcTestApp theApp;