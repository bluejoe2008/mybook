#include "stdafx.h"
#include "atlbase.h"

//д���ı�
void WriteString(CRegKey & key, CStringW valueName, CStringW value)
{
	key.SetStringValue(valueName, value);
}

//д��bool
void WriteBoolean(CRegKey & key, CStringW valueName, bool value)
{
	WriteString(key, valueName, value ? _T("true") : _T("false"));
}

//д��DWORD
void WriteNumber(CRegKey & key, CStringW valueName, DWORD value)
{
	key.SetDWORDValue(valueName, value);
}

void WriteProps()
{
	CRegKey key;
	key.Create(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"));
	
	WriteString(key, _T("hotelName"), _T("�����ſ�ջ"));
	WriteString(key, _T("boss"), _T("������"));
	WriteNumber(key, _T("maxClients"), 5);
	WriteBoolean(key, _T("isOpen"), true);
}

int main()
{
	WriteProps();

	return 0;
}