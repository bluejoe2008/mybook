#include "stdafx.h"
#include <cstdio>

int main()
{
	//д���ļ�
	FILE * fp = fopen("test.out", "w");
	fprintf(fp, "���㶹����");
	fclose(fp);

	//��ȡ�ļ�
	fp = fopen("test.out", "r");
	char line[256];
	fscanf(fp, "%s", line);
	printf("%s\r\n", line);
	fclose(fp);

	return 0;
}