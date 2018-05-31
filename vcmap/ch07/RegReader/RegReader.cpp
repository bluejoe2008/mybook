#include "stdafx.h"

//��ȡ�ı�ֵ
bool ReadString(HKEY key, CStringW valueName, CStringW & value)
{
	DWORD type;
	BYTE s[_MAX_PATH];
	DWORD len = _MAX_PATH;
	if(RegQueryValueEx(key, valueName, 0, &type, s, &len) == ERROR_SUCCESS)
	{
		value = (TCHAR *)s;
		return true;
	}

	return false;
}

//��ȡboolֵ
bool ReadBoolean(HKEY key, CStringW valueName, bool & value)
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
bool ReadNumber(HKEY key, CStringW valueName, DWORD & value)
{
	DWORD type;
	DWORD s;
	DWORD len = sizeof(DWORD);
	if(RegQueryValueEx(key, valueName, 0, &type, (LPBYTE)&s, &len) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

void ReadProps()
{
	HKEY key;
	//�򿪼�
	RegOpenKey(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"), &key);
	
	CStringW hotelName, boss;
	DWORD maxClients;
	bool isOpen;

	ReadString(key, _T("hotelName"), hotelName);
	ReadString(key, _T("boss"), boss);
	ReadNumber(key, _T("maxClients"), maxClients);
	ReadBoolean(key, _T("isOpen"), isOpen);
	RegCloseKey(key);

	_tprintf(_T("�Ƶ�: %s\r\n�ϰ�: %s\r\n���˿���: %d\r\n״̬: %s\r\n"), hotelName, boss, maxClients, isOpen ? _T("����") : _T("�ر�")); 
}

int main()
{
	setlocale(LC_ALL, "chs");
	ReadProps();

	return 0;
}
