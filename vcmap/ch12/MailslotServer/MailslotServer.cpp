#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello������Mailslot�����...\r\n");

	//�����ʲ�
	HANDLE hMailslot;
	hMailslot = CreateMailslot(_T("\\\\.\\mailslot\\MyMailslot"), 0, 
		MAILSLOT_WAIT_FOREVER, NULL);
	if(INVALID_HANDLE_VALUE == hMailslot)
	{
		printf("�����ʲ�ʧ�ܣ�\r\n");
		return -1;
	}

	printf("���������ȡ�ͻ���д���ʲ۵Ĳ���...\r\n");
	_getch();

	int args[2];
	DWORD dwRead;
	ReadFile(hMailslot, args, sizeof(args), &dwRead, NULL);

	//�ӿͻ��˶�ȡ����
	int a, b, c;
	int * pIntBuf = args;
	a = *(pIntBuf);
	pIntBuf++;
	b = *(pIntBuf);

	printf("��ȡ������(%d, %d)\r\n", a, b);

	//���������
	c = mcd(a, b);
	printf("�����mcd=%d\r\n", c);

	CloseHandle(hMailslot);
	return 0;
}