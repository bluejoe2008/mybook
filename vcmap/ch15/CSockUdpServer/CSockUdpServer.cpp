#include "stdafx.h"
#include "../../shared/mcd.h"
#include <afxsock.h>

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
		ListenSocket.Create(0x1224, SOCK_DGRAM, _T("127.0.0.1"));
		ListenSocket.Bind(0x1224);
		_tprintf(_T("���ڼ���...\r\n"));

		CString address;
		UINT port;
		int params[2];
		int bytes;

		bytes = ListenSocket.ReceiveFrom((char *)params, sizeof(params), address, port);
		_tprintf(_T("���пͻ������ӽ��룡����%s:%d\r\n"), address, port);
		_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d, %d\r\n"), bytes, params[0], params[1]);
		int m = mcd(params[0], params[1]);
		bytes = ListenSocket.SendTo((const char *)&m, sizeof(m), port, address);
		_tprintf(_T("�ɹ��ظ�%d���ֽڣ����ݣ�%d\r\n"), bytes, m);
		ListenSocket.Close();
	}

	return nRetCode;
}