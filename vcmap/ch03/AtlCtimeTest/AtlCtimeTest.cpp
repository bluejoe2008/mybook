#include "stdafx.h"
#include <atltime.h>

int main()
{
	int year, month, day;
	printf("�������ĳ�������(�� �� ��)��");
	scanf("%d%d%d", &year, &month, &day);

	CTime birthday(year, month, day, 0, 0, 0);
	CTime now = CTime::GetCurrentTime();

	CTimeSpan span = now - birthday;
	printf("��������%dСʱ��\r\n", span.GetTotalHours());

	return 0;
}
