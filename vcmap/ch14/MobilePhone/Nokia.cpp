#include "stdafx.h"
#include "Nokia.h"

NokiaMobilePhone::NokiaMobilePhone()
{
	cout << "��ӭʹ��ŵ���ǣ�" << endl;
}

NokiaMobilePhone::~NokiaMobilePhone()
{
	cout << "�ټ���" << endl;
}

void NokiaMobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "�绰�Ѳ�ͨ..." << endl;
}

void NokiaMobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
}

void NokiaMobilePhone::hangup()
{
	cout << "�������Ҷϣ�" << endl;
}