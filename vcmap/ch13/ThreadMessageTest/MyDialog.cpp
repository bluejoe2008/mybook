// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadMessageTest.h"
#include "../../shared/mcd.h"
#include "MyDialog.h"


// CMyDialog �Ի���

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
	, m_Msg(_T(""))
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Msg);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_MESSAGE(WM_MCD_REQUEST, OnMcdRequest)
END_MESSAGE_MAP()


// CMyDialog ��Ϣ�������
LRESULT CMyDialog::OnMcdRequest(WPARAM wParam, LPARAM lParam)
{
	UpdateData(TRUE);
	int a = wParam;
	int b = lParam;
	int c = mcd(a, b);

	CString msg;
	msg.Format(_T("mcd(%d, %d) = %d\r\n"), a, b, c);
	m_Msg += msg;

	UpdateData(FALSE);
	return 0;
}
