#include "stdafx.h"
#include "Native.h"

NativeMobilePhone::NativeMobilePhone()
{
	cout << "ding...��ӭʹ��ɽկ����" << endl;
}

NativeMobilePhone::~NativeMobilePhone()
{
	cout << "�ټ���dang..." << endl;
}

void NativeMobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "dudu..." << endl;
	cout << "�绰�Ѳ�ͨ..." << endl;
}

void NativeMobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;
}

void NativeMobilePhone::hangup()
{
	cout << "�������Ҷϣ�" << endl;
	cout << "ͨ��ʱ�䣺xx��xx��" << endl;
}

void NativeMobilePhone::play(string movie)
{
	cout << "���ڲ��š�" << movie << "��..." << endl;
}
