#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello������Pipe�����...\r\n");

	//��ȡ��׼����������
	HANDLE hStdIn = ::GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD dwRead = 0;

	//�ӱ�׼�����ж�ȡ����
	int args[2];
	ReadFile(hStdIn, args, sizeof(args), &dwRead, NULL);
	if(dwRead > 0)
	{
		//����mcd
		int a = args[0];
		int b = args[1];
		int c = mcd(a, b);
		DWORD dwWrite = 0;
		WriteFile(hStdOut, &c, sizeof(c), &dwWrite, NULL);
	}

	return 0;
}