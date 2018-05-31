#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

#define BUF_SIZE 1024

int _tmain()
{
	printf("hello������FileMapping�����...\r\n");

	HANDLE hMapFile;
	LPVOID pBuf;

	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,		// use paging file
		NULL,						// default security 
		PAGE_READWRITE,				// read/write access
		0,							// max. object size 
		BUF_SIZE,					// buffer size  
		_T("MyFileMapping"));		// name of mapping object

	if (hMapFile == NULL) 
	{ 
		printf("�����ļ�ӳ��ʧ�ܣ�\r\n");
		return -1;
	}

	pBuf = MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,                   
		0,                   
		BUF_SIZE);           

	if (pBuf == NULL) 
	{ 
		printf("�����ļ�ӳ��ʧ�ܣ�\r\n");
		return 2;
	}

	printf("���������ȡ�ͻ���д���ļ�ӳ��Ĳ���...\r\n");
	_getch();

	//�ӿͻ��˶�ȡ����
	int a, b, c;
	int * pIntBuf = (int *)pBuf;
	a = *(pIntBuf);
	pIntBuf++;
	b = *(pIntBuf);
	c = mcd(a, b);

	printf("��ȡ������(%d, %d)\r\n", a, b);

	//д�ؼ�����
	pIntBuf++;
	*pIntBuf = c;

	printf("�����mcd=%d�������д���ļ�ӳ��\r\n", c);

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	return 0;
}