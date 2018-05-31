#pragma once

#include "MyDialog.h"

// CCopyFileThread

class CCopyFileThread : public CWinThread
{
	DECLARE_DYNCREATE(CCopyFileThread)

protected:
	CCopyFileThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CCopyFileThread();

public:
	CCopyFileDialog m_dialog;
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CEvent m_FileCopiedEvent;

protected:
	DECLARE_MESSAGE_MAP()
};


