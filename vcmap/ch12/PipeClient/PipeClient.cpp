#include "stdafx.h"
#include <windows.h>

int _tmain()
{
	printf("hello������Pipe�ͻ���...\r\n");

	HANDLE hChildStdInRead, hChildStdInWrite;
	HANDLE hChildStdOutRead, hChildStdOutWrite;

	//��ȫ����
	SECURITY_ATTRIBUTES sa; 

	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
	sa.bInheritHandle = TRUE; //�ӽ��̿��Լ̳и����̴����ܵ��Ķ�д���
	sa.lpSecurityDescriptor = NULL; 

	//������׼����ܵ�
	if(!CreatePipe(&hChildStdInRead, &hChildStdInWrite, &sa, 0))
	{
		printf("������׼����ܵ�ʧ�ܣ�");
		return -1;
	}

	//������׼����ܵ�
	if(!CreatePipe(&hChildStdOutRead, &hChildStdOutWrite, &sa, 0))
	{
		printf("������׼����ܵ�ʧ�ܣ�");
		return -1;
	}

	//��������
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	si.wShowWindow = SW_HIDE;
	si.hStdInput = hChildStdInRead;
	si.hStdOutput = hChildStdOutWrite;
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES; //ʹ����ʾ���ںͱ�׼����ı�־

	TCHAR cCommandLine[_MAX_PATH] = _T("PipeServer.exe");

	// ����PipeServer.exe
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		DWORD dwWrite = 0;
		int args[] = {121, 33};
		//���Ͳ���ֵ
		WriteFile(hChildStdInWrite, args, sizeof(args), &dwWrite, NULL);
		printf("д��ܵ��Ĳ���: (%d, %d)\r\n", args[0], args[1]);

		DWORD dwRead = 0;
		int c;
		ReadFile(hChildStdOutRead, &c, sizeof(c), &dwRead, NULL);
		printf("��ȡ�������д��ܵ��Ľ��: mcd=%d\r\n", c);
	}

	return 0;
}