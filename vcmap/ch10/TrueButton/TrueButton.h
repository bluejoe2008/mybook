// TrueButton.h : TrueButton Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTrueButtonApp:
// �йش����ʵ�֣������ TrueButton.cpp
//

class CTrueButtonApp : public CWinApp
{
public:
	CTrueButtonApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTrueButtonApp theApp;