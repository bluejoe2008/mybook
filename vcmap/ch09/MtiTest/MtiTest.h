// MtiTest.h : MtiTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMtiTestApp:
// �йش����ʵ�֣������ MtiTest.cpp
//

class CMtiTestApp : public CWinApp
{
public:
	CMtiTestApp();

	CArray<HWND, HWND> m_aryFrames;
public:

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	DECLARE_MESSAGE_MAP()
};

extern CMtiTestApp theApp;