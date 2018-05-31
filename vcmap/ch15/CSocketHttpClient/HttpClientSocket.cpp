// HttpClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpClient.h"
#include "HttpClient.h"
#include "HttpClientDlg.h"


// CHttpClientSocket

CHttpClientSocket::CHttpClientSocket(CHttpClientDlg * pDlg)
{
	m_pDlg = pDlg;
}

CHttpClientSocket::~CHttpClientSocket()
{
}


// CHttpClientSocket ��Ա����

void CHttpClientSocket::OnReceive(int nErrorCode)
{
	//���յ���HTTP��Ӧ
	char buffer[1024] = {0};
	while(true)
	{
		//��ζ�ȡ
		int read = this->CAsyncSocket::Receive(buffer, 1024);
		if(read <= 0)
			break;

		buffer[read - 1] = 0;
		m_Response += buffer;
	}

	//��ʾ��Ӧ
	m_pDlg->ShowResponse(m_Response);

	CString msg;
	msg.Format(_T("�ɹ�����%d�ֽڣ�"), m_Response.GetLength());
	m_pDlg->ShowStatus(msg);
}

//����url����
void CHttpClientSocket::Request(CString sHost, UINT nPort, CString sPath)
{
	this->Connect(sHost, nPort);
	m_Response = "";

	CString request;
	request.Format(_T("GET %s HTTP/1.1\r\nhost:%s\r\n\r\n"), sPath, sHost);
	int send = this->Send((LPCTSTR)request, request.GetLength() * sizeof(TCHAR));
	if(send <= 0)
	{
		m_pDlg->ShowStatus(_T("�޷�����ҳ��"));
	}
	else
	{
		CString msg;
		msg.Format(_T("�ɹ�����%d�ֽڣ�"), send);
		m_pDlg->ShowStatus(msg);
	}
}
