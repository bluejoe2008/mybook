#include "stdafx.h"
#include <windows.h>
#include <conio.h>

#define BUF_SIZE 1024

int _tmain()
{
	printf("hello������FileMapping�ͻ���...\r\n");

	HANDLE hMapFile;
	LPVOID pBuf;

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,		// read/write access
		FALSE,						// do not inherit the name
		_T("MyFileMapping"));		// name of mapping object 

	if (hMapFile == NULL) 
	{ 
		printf("���ļ�ӳ��ʧ�ܣ�\r\n");
		return -1;
	} 

	pBuf = MapViewOfFile(hMapFile,	// handle to map object
		FILE_MAP_ALL_ACCESS,		// read/write permission
		0,                    
		0,                    
		BUF_SIZE);           

	if (pBuf == NULL) 
	{ 
		printf("���ļ�ӳ��ʧ�ܣ�\r\n");
		return -1;
	}

	//д����������
	int * pIntBuf = (int *)pBuf;
	int a = 12;
	int b = 18;
	*pIntBuf = a;
	pIntBuf++;
	*pIntBuf = b;

	printf("����(%d, %d)��д�룬���������ȡ���...\r\n", a, b);
	_getch();

	pIntBuf++;
	int c = *pIntBuf;
	printf("��ȡ�������д���ļ�ӳ��Ľ��: %d\r\n", c);

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	return 0;
}