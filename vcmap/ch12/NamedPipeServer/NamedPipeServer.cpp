#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello������NamedPipe�����...\r\n");

	//�����ùܵ�MyPipe
	HANDLE hPipe = CreateNamedPipe(_T("\\\\.\\pipe\\MyPipe"), 
		PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 
		0, 1, 1024, 1024, 0, NULL);
	if(INVALID_HANDLE_VALUE == hPipe)
	{
		printf("���������ܵ�ʧ�ܣ�\r\n");
		return -1;
	}

	HANDLE hEvent;
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	OVERLAPPED ovlap;
	ZeroMemory(&ovlap, sizeof(OVERLAPPED));
	ovlap.hEvent = hEvent;

	//ConnectNamedPipe�൱��Accept
	ConnectNamedPipe(hPipe, &ovlap);
	//һֱ�ȵ��пͻ��˵�����
	WaitForSingleObject(hEvent, INFINITE);
	CloseHandle(hEvent);

	int args[2];
	DWORD dwRead, dwWrite;

	//��ȡ
	ReadFile(hPipe, args, 100, &dwRead, NULL);
	int a = args[0];
	int b = args[1];
	printf("��ȡ������(%d, %d)\r\n", a, b);

	int c = mcd(a, b);

	//д��
	WriteFile(hPipe, &c, sizeof(c), &dwWrite, NULL);
	printf("�����mcd=%d�������д�������ܵ�\r\n", c);

	printf("��������رճ���...\r\n");
	_getch();

	return 0;
}