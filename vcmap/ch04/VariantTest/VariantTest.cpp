// VariantTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "VariantTest.h"

int main()
{
	VARIANT v1;
	v1.vt = VT_BSTR;
	v1.bstrVal = _T("hello, world!");

	COleVariant v3 = _T("hello, world!");
	COleVariant v4 = (long)100;
	CString str = (BSTR)v3.pbstrVal;
	long i = v4.lVal;

	return 0;
}
