#pragma once
#include "CSockEventServerDlg.h"

// CMcdServerSocket ����Ŀ��

class CMcdServerSocket : public CSocket
{
public:
	CMcdServerDlg * m_pDialog;
	CMcdServerSocket(CMcdServerDlg * pDialog);
	virtual ~CMcdServerSocket();
	virtual void OnReceive(int nErrorCode);
};


