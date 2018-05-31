#include "stdafx.h"
#include "Native.h"

void _MobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "dudu..." << endl;
	cout << "�绰�Ѳ�ͨ..." << endl;
}

void _MobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;
}

void _MobilePhone::hangup()
{
	cout << "�������Ҷϣ�" << endl;
	cout << "ͨ��ʱ�䣺xx��xx��" << endl;
}

void _Mp3Player::play(string movie)
{
	cout << "���ڲ��š�" << movie << "��..." << endl;
}	

bool NativeMobilePhone::QueryInterface(int interfaceType, void ** ppObject)
{
	if(interfaceType == MOBILE_PHONE_PART)
		*ppObject = &_phone;

	if(interfaceType == MP3_PLAYER_PART)
		*ppObject = &_mp3;

	return true;
}

NativeMobilePhone::NativeMobilePhone()
{
	cout << "ding...��ӭʹ��ɽկ����" << endl;
	_ref = 1;
}

NativeMobilePhone::~NativeMobilePhone()
{
	cout << "�ټ���dang..." << endl;
}

void NativeMobilePhone::AddRef()
{
	_ref++;
}

void NativeMobilePhone::Release()
{
	_ref--;
	if(_ref == 0)
		delete this;
}
