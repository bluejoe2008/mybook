#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello������Mailslot�ͻ���...\r\n");

	HANDLE hMailslot;
	hMailslot = CreateFile(_T("\\\\.\\mailslot\\MyMailslot"), GENERIC_WRITE | GENERIC_READ, 
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(INVALID_HANDLE_VALUE == hMailslot)
	{
		printf("�Ҳ���MyMailslot���ǲ���û�������������ˣ�\r\n");
		return -1;
	}

	//д�����
	DWORD dwWrite;
	int args[] = {12, 18};
	WriteFile(hMailslot, args, sizeof(args), &dwWrite, NULL);
	printf("����(%d, %d)��д���ʲ�...\r\n", args[0], args[1]);

	CloseHandle(hMailslot);
	return 0;
}