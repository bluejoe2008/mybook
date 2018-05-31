// McdListenSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CSockEventServer.h"
#include "McdServerSocket.h"
#include "McdListenSocket.h"


// CMcdListenSocket

CMcdListenSocket::CMcdListenSocket(CMcdServerDlg * pDialog)
{
	m_pDialog = pDialog;
}

CMcdListenSocket::~CMcdListenSocket()
{
	//��������m_Sockets�б����CMcdServerSocket
	for(POSITION p = m_Sockets.GetHeadPosition(); p != m_Sockets.GetTailPosition(); m_Sockets.GetNext(p))
	{
		CMcdServerSocket *pServerSocket = (CMcdServerSocket *)m_Sockets.GetAt(p);
		delete pServerSocket;
	}

	m_Sockets.RemoveAll();
}


// CMcdListenSocket ��Ա����

void CMcdListenSocket::OnAccept(int nErrorCode)
{
	//��¼�´�����CMcdServerSocket�������޷���������
	CMcdServerSocket *pServerSocket = new CMcdServerSocket(m_pDialog);
	m_Sockets.AddTail(pServerSocket);
	this->Accept(*pServerSocket);

	CString msg;
	CString address;
	UINT port;
	pServerSocket->GetSockNameEx(address, port);
	msg.Format(_T("���յ��µ����ӣ�����������%s:%d"), address, port);
	m_pDialog->MessageBox(msg);
}
