========================================================================
    �ģ��⣺MobilePhoneCom ��Ŀ����
========================================================================

Ӧ�ó�������Ϊ�������˴� MobilePhoneCom ��Ŀ���������ڴ˻���֮��
��д�Լ��Ķ�̬���ӿ� (DLL)��


���ļ������������Ŀ��ÿ���ļ�
�����ݡ�

MobilePhoneCom.vcproj
    ����ʹ��Ӧ�ó��������ɵ� VC++ ��Ŀ������Ŀ�ļ��� 
    �������й����ɸ��ļ���ʹ�õ� Visual C++ �汾����Ϣ���Լ�
    �й���Ӧ�ó�������ѡ���ƽ̨�����ú���Ŀ����
    ����Ϣ��

MobilePhoneCom.idl
    ���ļ�������������Ŀ�ж�������Ϳ⡢�ӿ�
    �� coclass �� IDL ���塣
    ���ļ����� MIDL ���������������ɣ�
        C++ �ӿڶ���� GUID ����                 (MobilePhoneCom.h)
        GUID ����                                (MobilePhoneCom_i.c)
        һ�����Ϳ�                               (MobilePhoneCom.tlb)
        ���ʹ���                                 (MobilePhoneCom_p.c �� dlldata.c)

MobilePhoneCom.h
    ���ļ������� MobilePhoneCom.idl �ж������� C++ �ӿڶ���
    �� GUID �����������ڱ���������� MIDL �������ɡ�

MobilePhoneCom.cpp
    ���ļ���������ӳ��� DLL ������ʵ�֡�

MobilePhoneCom.rc
    ���ǳ���ʹ�õ����� Microsoft Windows ��Դ����
    ����

MobilePhoneCom.def
    ��ģ�鶨���ļ�Ϊ�������ṩ�й� DLL ��Ҫ���
    ��������Ϣ�������������������ݵĵ�����
        DllGetClassObject  
        DllCanUnloadNow    
        GetProxyDllInfo    
        DllRegisterServer	
        DllUnregisterServer

/////////////////////////////////////////////////////////////////////////////
������׼�ļ���

StdAfx.h��StdAfx.cpp
    ��Щ�ļ�����������Ϊ MobilePhoneCom.pch ��Ԥ����ͷ (PCH) �ļ�
    ����Ϊ StdAfx.obj ��Ԥ���������ļ���

Resource.h
    �������ڶ�����Դ ID �ı�׼ͷ�ļ���

/////////////////////////////////////////////////////////////////////////////
����/��� (stub) DLL ��Ŀ��ģ�鶨���ļ���

MobilePhoneComps.vcproj
    ���ļ����������ɴ���/��� (stub) DLL ����Ŀ�ļ������б�Ҫ����
	����Ŀ�е� IDL �ļ��������ٰ���һ���ӿڣ�����
	�����ɴ���/��� (stub) DLL ֮ǰ�����ȱ��� IDL �ļ���	�˽�������
	dlldata.c��MobilePhoneCom_i.c �� MobilePhoneCom_p.c�����ǡ�
	�����ɴ���/��� (stub) DLL ������ġ�

MobilePhoneComps.def
    ��ģ�鶨���ļ�Ϊ�������ṩ�йش���/��� (stub) ��Ҫ���
    ��������Ϣ��

/////////////////////////////////////////////////////////////////////////////
