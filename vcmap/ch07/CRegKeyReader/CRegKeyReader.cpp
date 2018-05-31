#include "stdafx.h"
#include "atlbase.h"

//��ȡ�ı�ֵ
bool ReadString(CRegKey & key, CStringW valueName, CStringW & value)
{
	TCHAR s[_MAX_PATH];
	DWORD len = _MAX_PATH;
	if(key.QueryStringValue(valueName, s, &len) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

//��ȡboolֵ
bool ReadBoolean(CRegKey & key, CStringW valueName, bool & value)
{
	CStringW s;
	//�ȶ�ȡ�ı�ֵ
	if(ReadString(key, valueName, s))
	{
		//�ж����Ƿ�Ϊtrue
		value = (CStringW("true").CompareNoCase(s) == 0);
		return true;
	}

	return false;
}

//��ȡDWORDֵ
bool ReadNumber(CRegKey & key, CStringW valueName, DWORD & value)
{
	DWORD s;
	if(key.QueryDWORDValue(valueName, s) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

void ReadProps()
{
	CRegKey key;
	key.Open(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"));

	CStringW hotelName, boss;
	DWORD maxClients;
	bool isOpen;

	ReadString(key, _T("hotelName"), hotelName);
	ReadString(key, _T("boss"), boss);
	ReadNumber(key, _T("maxClients"), maxClients);
	ReadBoolean(key, _T("isOpen"), isOpen);

	_tprintf(_T("�Ƶ�: %s\r\n�ϰ�: %s\r\n���˿���: %d\r\n״̬: %s\r\n"), hotelName, boss, maxClients, isOpen ? _T("����") : _T("�ر�")); 
}

int main()
{
	setlocale(LC_ALL, "chs");
	ReadProps();

	return 0;
}