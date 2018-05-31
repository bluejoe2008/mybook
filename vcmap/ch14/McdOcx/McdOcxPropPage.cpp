// McdOcxPropPage.cpp : CMcdOcxPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "McdOcx.h"
#include "McdOcxPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMcdOcxPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMcdOcxPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMcdOcxPropPage, "MCDOCX.McdOcxPropPage.1",
	0xdf11e68d, 0xbd46, 0x4c95, 0x9e, 0x31, 0x19, 0x31, 0x8d, 0x99, 0x65, 0x47)



// CMcdOcxPropPage::CMcdOcxPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMcdOcxPropPage ��ϵͳע�����

BOOL CMcdOcxPropPage::CMcdOcxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MCDOCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CMcdOcxPropPage::CMcdOcxPropPage - ���캯��

CMcdOcxPropPage::CMcdOcxPropPage() :
	COlePropertyPage(IDD, IDS_MCDOCX_PPG_CAPTION)
{
}



// CMcdOcxPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMcdOcxPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CMcdOcxPropPage ��Ϣ�������
