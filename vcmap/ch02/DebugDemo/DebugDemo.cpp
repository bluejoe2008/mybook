// DebugDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

float Divide(int a, int b)
{
	//����������Ϊ0
	ASSERT(b != 0);
	return (float)a / b;
}

int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	float c = Divide(a, b);
	printf("%d / %d = %f\r\n", a, b, c);

	return 0;
}
