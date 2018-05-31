// DebugDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//��0�����쳣
class DividedByZero
{
};

//������Χ
class OutOfRange
{
};

float Divide(int a, int b)
{
	if(b == 0)
		throw DividedByZero();

	if(b < 0)
		throw OutOfRange();

	return (float)a / b;
}

int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	try
	{
		float c = Divide(a, b);
		printf("%d / %d = %f\r\n", a, b, c);
	}
	catch(DividedByZero & e)
	{
		printf("ִ�г���ʱ������0������\r\n");
	}
	catch(...)
	{
		printf("ִ�г���ʱ��������\r\n");
	}

	return 0;
}
