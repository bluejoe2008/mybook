#pragma once

// CMcdClientSocket ����Ŀ��

class CMcdClientDlg;

class CMcdClientSocket : public CSocket
{
public:
	CMcdClientDlg * m_pDialog;
	CMcdClientSocket(CMcdClientDlg * pDialog);
	virtual ~CMcdClientSocket();
	virtual void OnReceive(int nErrorCode);
	int SendNumbers(int a, int b);
};


