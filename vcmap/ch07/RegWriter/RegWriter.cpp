#include "stdafx.h"

//д���ı�
void WriteString(HKEY key, CStringW valueName, CStringW value)
{
	RegSetValueEx(key, valueName, 0, REG_SZ, (LPBYTE)(LPCTSTR)value, (value.GetLength() + 1) * sizeof(TCHAR));
}

//д��bool
void WriteBoolean(HKEY key, CStringW valueName, bool value)
{
	WriteString(key, valueName, value ? _T("true") : _T("false"));
}

//д��DWORD
void WriteNumber(HKEY key, CStringW valueName, DWORD value)
{
	RegSetValueEx(key, valueName, 0, REG_DWORD, (LPBYTE)&value, sizeof(value));
}

void WriteProps()
{
	HKEY key;
	//������
	RegCreateKey(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"), &key);
	
	WriteString(key, _T("hotelName"), _T("�����ջ"));
	WriteString(key, _T("boss"), _T("�����"));
	WriteNumber(key, _T("maxClients"), 5);
	WriteBoolean(key, _T("isOpen"), false);
	RegCloseKey(key);
}


int main()
{
	WriteProps();

	return 0;
}