#include "stdafx.h"
#include "sheet.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	CSheet sheet;

	//��csv�ļ�
	ifstream in("test.csv");
	//������CSheet
	sheet.loadFrom(in);

	for(int i = 0; i < sheet.getRowCount(); i++)
	{
		_tprintf(_T("[%02d] "), i);
		//��ȡָ����
		CRow row = sheet.getRow(i);
		for(int j = 0; j < row.getColumnCount(); j++)
		{
			//��ȡָ����
			CString s = row.getColumn(j);
			_tprintf(_T("%s/"), s);
		}
		_tprintf(_T("\r\n"), i);
	}

	return 0;
}