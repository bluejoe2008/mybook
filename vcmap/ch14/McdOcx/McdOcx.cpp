// McdOcx.cpp : CMcdOcxApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "McdOcx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMcdOcxApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x120FBE77, 0x6E6D, 0x49E0, { 0xBF, 0xC1, 0xB9, 0x1E, 0xB1, 0xFD, 0x8D, 0x14 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMcdOcxApp::InitInstance - DLL ��ʼ��

BOOL CMcdOcxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CMcdOcxApp::ExitInstance - DLL ��ֹ

int CMcdOcxApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
