#pragma once

#include "MyDialog.h"

// CMyThread

class CMyThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyThread)

protected:
	CMyThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyThread();

public:
	CMyDialog m_dialog;
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


