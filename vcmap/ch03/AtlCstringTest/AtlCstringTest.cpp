#include "stdafx.h"

int main()
{
	CString src(_T("(100 + 200) / 50 - 20 * 8"));
	CString token;

	int i = 0;
	int m = 1;

	while(true)
	{
		//ʹ��Tokenize����Ӵ�
		token = src.Tokenize(_T(" +-*/()"), i);
		if(token == _T(""))
			break;

		CString out;
		//ʹ��Format��ʽ���ַ���
		out.Format(_T("token %02d: %s\r\n"), m, token);
		_tprintf(out);
		m++;
	}

	return 0;
}
