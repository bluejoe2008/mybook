#include "stdafx.h"
#include "windows.h"
#include "atltime.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "chs");
	WIN32_FIND_DATA FindFileData;

	TCHAR FileName[] = _T("c:\\*.*");
	//��ʼ����
	HANDLE hFind = FindFirstFile(FileName, &FindFileData);
	if(hFind != INVALID_HANDLE_VALUE)
	{
		while(true)
		{
			CTime CreationTime(FindFileData.ftCreationTime);
			
			//��Ŀ¼
			if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				_tprintf(_T("<%s>\t"), FindFileData.cFileName);
			else
				_tprintf(_T("%s\t"), FindFileData.cFileName);
			
			//����ʱ��
			_tprintf(_T("\t\t%s\r\n"), CreationTime.Format(_T("%Y��%m��%d��%Hʱ")));

			if(!FindNextFile(hFind, &FindFileData))
				break;
		}
		FindClose(hFind);
	}

	return 0;
}

