#include "stdafx.h"
#include <cstdio>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "chs");

	//д���ļ�
	FILE * fp = _wfopen(L"test.out", L"w,ccs=UNICODE");
	fwprintf(fp, L"%s", L"���㶹����");
	fclose(fp);

	//��ȡ�ļ�
	fp = _wfopen(L"test.out", L"r,ccs=UNICODE");
	wchar_t line[256];
	fwscanf(fp, L"%s", line);
	wprintf(L"%s\r\n", line);
	fclose(fp);

	return 0;
}