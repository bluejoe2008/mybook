#include "stdafx.h"
#include "string"
#include "comutil.h"
#pragma comment( lib, "comsuppw.lib" )

using namespace std;

int main()
{
	char s1[] = "����ABC";
	wchar_t s2[] = L"����ABC";

	//ʹ��sizeof��ȡ�ַ�������
	printf("sizeof s1: %d\r\n", sizeof(s1));
	printf("sizeof s2: %d\r\n", sizeof(s2));

	//ʹ��strlen��ȡ�ַ�������
	printf("strlen(s1): %d\r\n", strlen(s1));
	printf("wcslen(s2): %d\r\n", wcslen(s2));

	//ʹ��CString::GetLength()��ȡ�ַ�������
	CStringA sa = s1;
	CStringW sw = s2;

	printf("sa.GetLength(): %d\r\n", sa.GetLength());
	printf("sw.GetLength(): %d\r\n", sw.GetLength());

	//ʹ��string::size()��ȡ�ַ�������
	string ss1 = s1;
	wstring ss2 = s2;

	printf("ss1.size(): %d\r\n", ss1.size());
	printf("ss2.size(): %d\r\n", ss2.size());

	//ʹ��_bstr_t::length()��ȡ�ַ�������
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);

	printf("bs1.length(): %d\r\n", bs1.length());
	printf("bs2.length(): %d\r\n", bs2.length());

	return 0;
}