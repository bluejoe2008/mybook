#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "chs");

	CTime now = CTime::GetCurrentTime();
	CString s = now.Format("%Y��%m��%d�� %Hʱ%M��%S��\r\n���ر�ʾ: %c\r\n");
	_tprintf(_T("%s"), s);

	return 0;
}
