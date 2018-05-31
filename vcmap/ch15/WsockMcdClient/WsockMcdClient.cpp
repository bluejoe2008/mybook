#include "stdafx.h"

#include <winsock2.h>
#include <stdio.h>
#include <locale.h>
#pragma comment( lib, "Ws2_32.lib" )

int main()
{
	setlocale(LC_ALL, "chs");

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR) 
	{
		_tprintf(_T("WSAStartup()����ʧ�ܣ�\r\n"));
		return -1;
	}

	SOCKET ConnectSocket;
	ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ConnectSocket == INVALID_SOCKET) 
	{
		_tprintf(_T("����socketʧ�ܣ�\r\n"));
		WSACleanup();
		return -1;
	}

	sockaddr_in clientService; 
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
	clientService.sin_port = htons( 0x1224 );

	if ( connect( ConnectSocket, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR)
	{
		_tprintf(_T("���ӷ���������ʧ�ܣ�\r\n"));
		WSACleanup();
		return -1;
	}

	_tprintf(_T("�ɹ����ӷ�������\r\n"));
	int params[2] = {12, 18};
	int bytes;
	int m;
	bytes = send(ConnectSocket, (const char *)params, sizeof(params), 0);
	_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d, %d\r\n"), bytes, params[0], params[1]);
	bytes = recv(ConnectSocket, (char *)&m, sizeof(m), 0);
	_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d\r\n"), bytes, m);
	_tprintf(_T("mcd(%d, %d) = %d\r\n"), params[0], params[1], m);

	WSACleanup();
	return 0;
}
