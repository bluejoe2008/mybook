// SkinMagicTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "SkinMagicTest.h"
#include "SkinMagicTestDlg.h"


#include "SkinMagicLib.h"
#pragma comment(lib, "SkinMagicTrial.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSkinMagicTestApp

BEGIN_MESSAGE_MAP(CSkinMagicTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSkinMagicTestApp ����

CSkinMagicTestApp::CSkinMagicTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CSkinMagicTestApp ����

CSkinMagicTestApp theApp;


// CSkinMagicTestApp ��ʼ��

BOOL CSkinMagicTestApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	VERIFY( 1 == InitSkinMagicLib( AfxGetInstanceHandle(), _T("SkinMagicTest") , 
		NULL,
		NULL ) );

	VERIFY( 1 == LoadSkinFile(_T("LightBlue.smf"))); 
	VERIFY( 1 == SetDialogSkin(_T("Dialog")));

	CSkinMagicTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CSkinMagicTestApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	ExitSkinMagicLib();
	return CWinApp::ExitInstance();
}
