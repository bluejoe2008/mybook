// CObjectRttiTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int main()
{
	CDialog dlg;
	printf("%s\r\n", dlg.IsKindOf(RUNTIME_CLASS(CDialog)) ? "true" : "false");
	printf("%s\r\n", dlg.IsKindOf(RUNTIME_CLASS(CWnd)) ? "true" : "false");
	printf("%s\r\n", dlg.IsKindOf(RUNTIME_CLASS(CObject)) ? "true" : "false");

	printf("%s\r\n", dlg.IsKindOf(RUNTIME_CLASS(CFileDialog)) ? "true" : "false");
	printf("%s\r\n", dlg.IsKindOf(RUNTIME_CLASS(CFile)) ? "true" : "false");
}
