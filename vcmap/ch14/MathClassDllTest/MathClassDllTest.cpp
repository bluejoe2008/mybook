// MathClassDllTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../MathClassDll/Math.h"
#pragma comment(lib, "../Debug/MathClassDll.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	CMath math(18, 24);
	_tprintf(_T("%d\r\n"), math.mcd());
	_tprintf(_T("%d\r\n"), math.lcm());

	return 0;
}

