// Mixed.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char s1[4] = "65";
	int n1 = 65;

	//д
	CFile file;
	file.Open("test.out", CFile::modeWrite | CFile::modeCreate);
	
	//д���ı���65��
	file.Write(s1, sizeof(s1));
	//д����ֵ65
	file.Write(&n1, sizeof(n1));
	
	file.Close();

	//��
	file.Open("test.out", CFile::modeRead);
	char s2[4];
	int n2;

	file.Read(s2, sizeof(s2));
	file.Read(&n2, sizeof(n2));

	printf("s2=%s\r\n", s2);
	printf("n2=%d\r\n", n2);

	file.Close();

	return 0;
}

