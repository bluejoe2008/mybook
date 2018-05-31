// McdOcxCtrl.cpp : CMcdOcxCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "McdOcx.h"
#include "McdOcxCtrl.h"
#include "McdOcxPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMcdOcxCtrl, COleControl)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMcdOcxCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// ����ӳ��

BEGIN_DISPATCH_MAP(CMcdOcxCtrl, COleControl)
	DISP_FUNCTION_ID(CMcdOcxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMcdOcxCtrl, "SetNumbers", dispidSetNumbers, SetNumbers, VT_EMPTY, VTS_I2 VTS_I2)
	DISP_PROPERTY_NOTIFY_ID(CMcdOcxCtrl, "Direction", dispidDirection, m_Direction, OnDirectionChanged, VT_I2)
END_DISPATCH_MAP()



// �¼�ӳ��

BEGIN_EVENT_MAP(CMcdOcxCtrl, COleControl)
END_EVENT_MAP()



// ����ҳ

// TODO: ����Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMcdOcxCtrl, 1)
	PROPPAGEID(CMcdOcxPropPage::guid)
END_PROPPAGEIDS(CMcdOcxCtrl)



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMcdOcxCtrl, "MCDOCX.McdOcxCtrl.1",
	0x1a1b254e, 0xd5aa, 0x406f, 0xa8, 0xb6, 0xa0, 0x21, 0x8e, 0x88, 0x43, 0xcc)



// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMcdOcxCtrl, _tlid, _wVerMajor, _wVerMinor)



// �ӿ� ID

const IID BASED_CODE IID_DMcdOcx =
		{ 0xF7C37EC0, 0xEA78, 0x45D9, { 0x8F, 0x6, 0x82, 0x4E, 0xBD, 0xAA, 0x52, 0xE5 } };
const IID BASED_CODE IID_DMcdOcxEvents =
		{ 0x39D92FC9, 0x5F9D, 0x452F, { 0x92, 0x3F, 0x83, 0xE7, 0xB8, 0x3A, 0xD3, 0xEB } };



// �ؼ�������Ϣ

static const DWORD BASED_CODE _dwMcdOcxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMcdOcxCtrl, IDS_MCDOCX, _dwMcdOcxOleMisc)



// CMcdOcxCtrl::CMcdOcxCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMcdOcxCtrl ��ϵͳע�����

BOOL CMcdOcxCtrl::CMcdOcxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MCDOCX,
			IDB_MCDOCX,
			afxRegApartmentThreading,
			_dwMcdOcxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMcdOcxCtrl::CMcdOcxCtrl - ���캯��

CMcdOcxCtrl::CMcdOcxCtrl()
{
	InitializeIIDs(&IID_DMcdOcx, &IID_DMcdOcxEvents);
	_a = 12;
	_b = 16;
	m_Direction = 0;
}



// CMcdOcxCtrl::~CMcdOcxCtrl - ��������

CMcdOcxCtrl::~CMcdOcxCtrl()
{
	// TODO: �ڴ�����ؼ���ʵ�����ݡ�
}



// CMcdOcxCtrl::OnDraw - ��ͼ����

void CMcdOcxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	//��ӡmcd()������
	CBrush brush1, brush2;
	//��ձ���
	brush1.CreateSolidBrush(0xFFFFFF);
	pdc->FillRect(rcBounds, &brush1);

	brush2.CreateSolidBrush(0x000000);
	pdc->SelectObject(brush2);

	//3��Բ��
	POINT p1 = {35, m_Direction == 1 ? 100 : 40};
	POINT p2 = {195, p1.y};
	POINT p3 = {(p1.x + p2.x) / 2, m_Direction == 1 ? p1.y - 60 : p1.y + 60};
	int radius = 15;

	//����3��Բ
	pdc->Ellipse(p1.x - radius, p1.y - radius, p1.x + radius, p1.y + radius);
	pdc->Ellipse(p2.x - radius, p2.y - radius, p2.x + radius, p2.y + radius);
	pdc->Ellipse(p3.x - radius, p3.y - radius, p3.x + radius, p3.y + radius);

	//����
	pdc->MoveTo(p1);
	pdc->LineTo(p3);
	pdc->LineTo(p2);

	CString msg;
	pdc->SetBkMode(TRANSPARENT);
	pdc->SetTextAlign(TA_CENTER);

	//�������
	pdc->SetTextColor(0xFFFFFF);
	msg.Format(_T("%d"), _a);
	pdc->TextOut(p1.x, p1.y - 9, msg, msg.GetLength());
	msg.Format(_T("%d"), _b);
	pdc->TextOut(p2.x, p2.y - 9, msg, msg.GetLength());
	msg.Format(_T("%d"), _mcd(_a, _b));
	pdc->TextOut(p3.x, p3.y - 9, msg, msg.GetLength());
}


// CMcdOcxCtrl::DoPropExchange - �־���֧��

void CMcdOcxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}



// CMcdOcxCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMcdOcxCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO: �ڴ��������������ؼ�״̬��
}



// CMcdOcxCtrl::AboutBox - ���û���ʾ�����ڡ���

void CMcdOcxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MCDOCX);
	dlgAbout.DoModal();
}



// CMcdOcxCtrl ��Ϣ�������

int CMcdOcxCtrl::_mcd(int a, int b)
{
	if (b == 0)
		return a;

	return _mcd(b, a % b);
}

void CMcdOcxCtrl::SetNumbers(SHORT a, SHORT b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	_a = a;
	_b = b;
	Invalidate();
}

void CMcdOcxCtrl::OnDirectionChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	Invalidate();
	SetModifiedFlag();
}
