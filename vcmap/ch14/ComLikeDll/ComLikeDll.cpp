// ComLikeDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ComLikeDll.h"
#include "Native.h"

bool _declspec(dllexport) CreateObject(int type, void ** ppObject)
{
	if(type == NATIVE_MOBILE_PHONE)
	{
		*ppObject = new NativeMobilePhone();
	}

	return true;
}
