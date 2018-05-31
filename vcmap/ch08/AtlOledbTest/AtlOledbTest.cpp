#include "stdafx.h"
#include "PersonCommand.h"
#include <clocale>

int main()
{
	setlocale(LC_ALL, "chs");
	CoInitialize(NULL);

	CPersonCommand persons;
	persons.OpenAll();

	//���ζ�ȡÿһ��
	while(persons.MoveNext() != DB_S_ENDOFROWSET)
	{
		//���
		CString line;
		line.Format(_T("%d\t%s\t%d\t%s\t%s\r\n"), persons.m_ID, persons.m_NAME, persons.m_AGE, persons.m_GENDER, persons.m_WORDS);
		_tprintf(line);
	}

	CoUninitialize();
	return 0;
}