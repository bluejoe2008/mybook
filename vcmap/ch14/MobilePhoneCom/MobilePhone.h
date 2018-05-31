// MobilePhone.h : CMobilePhone ������

#pragma once
#include "resource.h"       // ������

#include "MobilePhoneCom.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CMobilePhone

class ATL_NO_VTABLE CMobilePhone :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMobilePhone, &CLSID_MobilePhone>,
	public IDispatchImpl<IMobilePhone, &IID_IMobilePhone, &LIBID_MobilePhoneComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMobilePhone();
	~CMobilePhone();

DECLARE_REGISTRY_RESOURCEID(IDR_MOBILEPHONE)


BEGIN_COM_MAP(CMobilePhone)
	COM_INTERFACE_ENTRY(IMobilePhone)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

public:
	STDMETHOD(talk)(void);
public:
	STDMETHOD(getName)(BSTR* name);
};

OBJECT_ENTRY_AUTO(__uuidof(MobilePhone), CMobilePhone)
