// MobilePhone.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Nokia.h"
#include "Native.h"

/*
IMobilePhone * buy(int money)
{
	if(money > 2000)
		return new NokiaMobilePhone();
	else
		return new NativeMobilePhone();
}

int main()
{
	int money;
	cout << "���뻨����Ǯ���ֻ���Ԫ��:";
	cin >> money;
	IMobilePhone * mp = buy(money);

	mp->dial("13800138000");
	mp->talk();
	mp->hangup();

	delete mp;
	return 0;
}
*/

int main()
{
	NativeMobilePhone nmp;
	IMobilePhone * pmp1 = &nmp;
	
	pmp1->dial("13800138000");
	pmp1->talk();
	pmp1->hangup();

	IMp3Player * pmp2 = &nmp;
	pmp2->play("���¹�");

	return 0;
}

