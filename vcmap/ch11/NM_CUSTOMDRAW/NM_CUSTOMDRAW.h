// NM_CUSTOMDRAW.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNM_CUSTOMDRAWApp:
// �йش����ʵ�֣������ NM_CUSTOMDRAW.cpp
//

class CNM_CUSTOMDRAWApp : public CWinApp
{
public:
	CNM_CUSTOMDRAWApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNM_CUSTOMDRAWApp theApp;