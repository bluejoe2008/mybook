#include "stdafx.h"
#include "afxsock.h"
#include "../../shared/mcd.h"
#include <locale.h>

int _tmain()
{
	setlocale(LC_ALL, "chs");

	int nRetCode = 0;

	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0) ||
		!AfxSocketInit())
	{
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		CSocket ListenSocket;
		ListenSocket.Create(0x1224, SOCK_STREAM, _T("127.0.0.1"));
		ListenSocket.Listen();
		_tprintf(_T("���ڼ���...\r\n"));

		CSocket ClientSocket;
		ListenSocket.Accept(ClientSocket);

		CString address;
		UINT port;
		ClientSocket.GetSockNameEx(address, port);
		_tprintf(_T("���пͻ������ӽ��룡����%s:%d\r\n"), address, port);
		int params[2];
		int bytes;

		bytes = ClientSocket.Receive((char *)params, sizeof(params));
		_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d, %d\r\n"), bytes, params[0], params[1]);
		int m = mcd(params[0], params[1]);
		bytes = ClientSocket.Send((const char *)&m, sizeof(m));
		_tprintf(_T("�ɹ��ظ�%d���ֽڣ����ݣ�%d\r\n"), bytes, m);
		ListenSocket.Close();
	}

	return nRetCode;
}
