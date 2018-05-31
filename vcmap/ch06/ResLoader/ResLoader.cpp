#include "stdafx.h"
#include "ResLoader.h"

CWinApp theApp;

int _tmain()
{
	int nRetCode = 0;

	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		HRSRC hRes = FindResource(theApp.m_hInstance, MAKEINTRESOURCE(IDR_WORD1), _T("WORD"));
		//��ȡ����
		DWORD len  = SizeofResource(theApp.m_hInstance, hRes);
		HGLOBAL hg = LoadResource(theApp.m_hInstance, hRes);
		LPVOID lp = (LPSTR)LockResource(hg); 

		//����Դ�е����ݱ�����ĳ��WORD�ļ���
		CFile file;
		file.Open(_T("out.doc"), CFile::modeWrite | CFile::modeCreate);

		char * cp = (char *)lp;
		for(int i = 0; i < len; i++)
		{
			file.Write(cp++, 1);
		}

		CString filePath = file.GetFilePath();
		file.Close();

		//�򿪸��ļ�
		ShellExecute(NULL, _T("open"), filePath, NULL, NULL, SW_SHOW);
		FreeResource(hg); 
	}

	return nRetCode;
}
