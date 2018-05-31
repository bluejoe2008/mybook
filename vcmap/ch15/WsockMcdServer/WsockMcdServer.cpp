#include "stdafx.h"
#include "../../shared/mcd.h"

#include <winsock2.h>
#include <stdio.h>
#include <locale.h>
#pragma comment( lib, "Ws2_32.lib" )

int _tmain()
{
	setlocale(LC_ALL, "chs");

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR) 
	{
		_tprintf(_T("WSAStartup()����ʧ�ܣ�\r\n"));
		return -1;
	}

	//����һ��socket
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET)
	{
		_tprintf(_T("����socketʧ�ܣ�\r\n"));
		WSACleanup();
		return -1;
	}

	//���ò���
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(0x1224);

	if (bind( ListenSocket, 
		(SOCKADDR*) &service, 
		sizeof(service)) == SOCKET_ERROR)
	{
		_tprintf(_T("�󶨵�ַʱ����\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}

	//��ʼ����
	if (listen( ListenSocket, 1 ) == SOCKET_ERROR)
	{
		_tprintf(_T("����ʱ����\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}

	_tprintf(_T("���ڼ���...\r\n"));
	SOCKET AcceptSocket;

	AcceptSocket = accept( ListenSocket, NULL, NULL );
	if (AcceptSocket == INVALID_SOCKET)
	{
		_tprintf(_T("����������ʱ����\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}
	else 
	{
		_tprintf(_T("���пͻ������ӽ��룡\r\n"));
		int params[2];
		int bytes;
		bytes = recv(AcceptSocket, (char *)params, sizeof(params), 0);
		_tprintf(_T("�ɹ�����%d���ֽڣ����ݣ�%d, %d\r\n"), bytes, params[0], params[1]);
		int m = mcd(params[0], params[1]);
		bytes = send(AcceptSocket, (const char *)&m, sizeof(m), 0);
		_tprintf(_T("�ɹ��ظ�%d���ֽڣ����ݣ�%d\r\n"), bytes, m);
	}

	closesocket(ListenSocket);
	_tprintf(_T("�رտͻ����ӣ�\r\n"));

	WSACleanup();
	return 0;
}