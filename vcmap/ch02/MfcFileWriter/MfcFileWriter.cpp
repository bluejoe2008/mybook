#include "stdafx.h"

#include <afx.h>

int main()
{
	//д���ļ�
	CFile file;
	if(file.Open(_T("test.out"), CFile::modeCreate | CFile::modeWrite))
	{
		char line[256] = "���㶹����";
		file.Write(line, sizeof(line));
		file.Close();
	}

	//��ȡ�ļ�
	if(file.Open(_T("test.out"), CFile::modeRead))
	{
		char line[256];
		if(file.Read(line, 256) != 0)
		{
			printf("%s\r\n", line);
		}

		file.Close();
	}

	return 0;
}