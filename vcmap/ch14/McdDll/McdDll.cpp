#include "stdafx.h"

//�����Լ��
_declspec(dllexport) int mcd(int a, int b)
{
	if (b == 0)
		return a;

	return mcd(b, a % b);
}