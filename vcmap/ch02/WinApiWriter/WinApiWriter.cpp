#include "stdafx.h"
#include <windows.h>
#include <cstdio>

int main()
{
	HANDLE hFile;
	DWORD nBytes;

	//д���ļ�
	hFile = CreateFile( _T("test.out"),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		0,
		NULL );
	char msg[] = "���㶹����";
	if( hFile != INVALID_HANDLE_VALUE )
	{
		WriteFile( hFile, msg, sizeof(msg) - 1, &nBytes, NULL );
		CloseHandle(hFile);
	}

	//��ȡ�ļ�
	hFile = CreateFile( _T("test.out"),
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,
		0,
		NULL );
	if( hFile != INVALID_HANDLE_VALUE )
	{
		char line[256] = {0};
		BOOL bResult;
		bResult = ReadFile(hFile, 
			line, 
			sizeof(line), 
			&nBytes, 
			NULL) ; 

		if (nBytes != 0 ) 
		{
			printf("%s\r\n", line);
		}

		CloseHandle(hFile);
	}
}
