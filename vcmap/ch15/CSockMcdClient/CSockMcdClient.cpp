#include "stdafx.h"
#include "afxsock.h"
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
		CSocket ConnectSocket;

		//ע�ⲻ�����ö˿�
		ConnectSocket.Create();

		ConnectSocket.Connect(_T("127.0.0.1"), 0x1224);
		_tprintf(_T("�ɹ����ӷ�������\r\n"));

		int params[2] = {12, 18};
		int bytes;
		int m;

		bytes = ConnectSocket.Send((const char *)params, sizeof(params));
		_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d, %d\r\n"), bytes, params[0], params[1]);
		bytes = ConnectSocket.Receive((char *)&m, sizeof(m));
		_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d\r\n"), bytes, m);
		_tprintf(_T("mcd(%d, %d) = %d\r\n"), params[0], params[1], m);

		ConnectSocket.Close();
	}

	return nRetCode;
}
