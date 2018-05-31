// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "UIThreadTest.h"
#include "MyDialog.h"
#include "MyThread.h"


// CCopyFileDialog �Ի���

IMPLEMENT_DYNAMIC(CCopyFileDialog, CDialog)

CCopyFileDialog::CCopyFileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCopyFileDialog::IDD, pParent)
{
}

CCopyFileDialog::~CCopyFileDialog()
{
}

void CCopyFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
	DDX_Control(pDX, IDC_PROGREASS_TEXT, m_ProgressText);
}


BEGIN_MESSAGE_MAP(CCopyFileDialog, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CCopyFileDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

void CCopyFileDialog::OnTimer(UINT_PTR nIDEvent)
{
	//��ʾ������
	m_Ticks++;
	m_ProgressCtrl.SetPos(m_Ticks);

	CString s;
	s.Format(_T("%d%%"), m_Ticks);
	//��ʾ���Ȱٷֱ�
	m_ProgressText.SetWindowText(s);

	//�������
	if(m_Ticks == 100)
	{
		((CCopyFileThread *)AfxGetThread())->m_FileCopiedEvent.SetEvent();
		OnCancel();
	}
}

BOOL CCopyFileDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_Ticks = 0;
	SetTimer(1, 100, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CCopyFileDialog::OnBnClickedCancel()
{
	((CCopyFileThread *)AfxGetThread())->m_FileCancelledEvent.SetEvent();
	OnCancel();
}
