#include "stdafx.h"
#include <cstdio>

int main()
{
	//д���ļ�
	FILE * fp;
	fopen_s(&fp, "test.out", "w");
	fprintf_s(fp, "���㶹����");
	fclose(fp);

	//��ȡ�ļ�
	fopen_s(&fp, "test.out", "r");
	char line[256];
	fscanf_s(fp, "%s", line, 256);
	printf_s("%s\r\n", line);
	fclose(fp);

	return 0;
}