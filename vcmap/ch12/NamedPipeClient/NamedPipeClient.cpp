#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello������NamedPipe�ͻ���...\r\n");

	//WaitNamedPipe�൱��Connect
	if(!WaitNamedPipe(_T("\\\\.\\pipe\\MyPipe"), NMPWAIT_WAIT_FOREVER))
	{
		printf("�Ҳ���MyPipe���ǲ���û�������������ˣ�\r\n");
		return -1;
	}

	HANDLE hPipe = CreateFile(_T("\\\\.\\pipe\\MyPipe"), GENERIC_READ | GENERIC_WRITE, 
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(INVALID_HANDLE_VALUE==hPipe)
	{
		printf("�������ܵ�ʧ�ܣ�\r\n");
		return -1;
	}

	DWORD dwWrite = 0;
	int args[] = {121, 33};
	WriteFile(hPipe, args, sizeof(args), &dwWrite, NULL);
	printf("����(%d, %d)��д�룬���������ȡ���...\r\n", args[0], args[1]);
	_getch();

	int c;
	DWORD dwRead;
	ReadFile(hPipe, &c, sizeof(c), &dwRead, NULL);
	printf("��ȡ�������д�������ܵ��Ľ��: %d\r\n", c);

	return 0;
}