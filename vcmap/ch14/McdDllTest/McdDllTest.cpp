#include "stdafx.h"
#include "windows.h"

//���庯��ԭ��
typedef int (*FUNCTION)(int, int);

int _tmain()
{
	HINSTANCE hLib;
	hLib = ::LoadLibrary(_T("E:\\study\\keys\\ch15\\Debug\\McdDll.dll"));
	FUNCTION mcd = (FUNCTION)::GetProcAddress(hLib, "?mcd@@YAHHH@Z");
	_tprintf(_T("%d\r\n"), mcd(18, 24));

	::FreeLibrary(hLib);
	return 0;
}
