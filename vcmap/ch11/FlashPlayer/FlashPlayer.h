// FlashPlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFlashPlayerApp:
// �йش����ʵ�֣������ FlashPlayer.cpp
//

class CFlashPlayerApp : public CWinApp
{
public:
	CFlashPlayerApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFlashPlayerApp theApp;