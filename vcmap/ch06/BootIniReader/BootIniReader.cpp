#include "stdafx.h"

int _tmain()
{
	TCHAR buffer[256];
	TCHAR path[] = _T("c:\\boot.ini");
	int len = GetPrivateProfileSectionNames(buffer, sizeof(buffer), path);

	TCHAR *names = buffer;
	TCHAR *end = names + len;

	//���ص�sectionNames��null�ָ�

	while(names < end)
	{
		CString name = names;
		_tprintf(_T("======%s======\r\n"), name);
		names += name.GetLength();
		names ++;

		//��ȡ��section�������е�����
		TCHAR buffer2[1024];
		len = GetPrivateProfileSection(name, buffer2, sizeof(buffer2), path);
		//����������
		TCHAR *lines = buffer2;
		while(*lines)
		{
			CString line = lines; 
			_tprintf(_T("\t%s\r\n"), line);

			lines += line.GetLength();
			lines ++;
		}
	}

	return 0;
}