// MyThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadMessageTest.h"
#include "MyThread.h"


// CMyThread

IMPLEMENT_DYNCREATE(CMyThread, CWinThread)

CMyThread::CMyThread()
{
}

CMyThread::~CMyThread()
{
}

BOOL CMyThread::InitInstance()
{
	m_dialog.Create(IDD_DIALOG1);
	m_dialog.ShowWindow(SW_SHOW);
	return TRUE;
}

int CMyThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread, CWinThread)
END_MESSAGE_MAP()


// CMyThread ��Ϣ�������
