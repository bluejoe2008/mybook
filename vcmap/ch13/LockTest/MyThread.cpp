// MyThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UIThreadTest.h"
#include "MyThread.h"
#include "MyDialog.h"


// CCopyFileThread

IMPLEMENT_DYNCREATE(CCopyFileThread, CWinThread)

CCopyFileThread::CCopyFileThread()
{
}

CCopyFileThread::~CCopyFileThread()
{
}

BOOL CCopyFileThread::InitInstance()
{
	m_pMainWnd = &m_dialog; 

	m_dialog.Create(IDD_DIALOG1);
	m_dialog.ShowWindow(SW_SHOW);
	return TRUE;
}

int CCopyFileThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CCopyFileThread, CWinThread)
END_MESSAGE_MAP()


// CCopyFileThread ��Ϣ�������
