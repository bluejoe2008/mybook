// MobilePhone.cpp : CMobilePhone ��ʵ��

#include "stdafx.h"
#include "MobilePhone.h"
#include <iostream>

using namespace std;

// CMobilePhone

CMobilePhone::CMobilePhone()
{
	cout << "ding...��ӭʹ��ɽկ��COM�����" << endl;
}

CMobilePhone::~CMobilePhone()
{
	cout << "��лʹ��ɽկ��COM�����dang..." << endl;
}

STDMETHODIMP CMobilePhone::talk(void)
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;

	return S_OK;
}


STDMETHODIMP CMobilePhone::getName(BSTR* name)
{
	*name = _T("ɽկ��B920");
	return S_OK;
}
