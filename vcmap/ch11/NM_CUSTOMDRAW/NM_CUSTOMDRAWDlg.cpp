// NM_CUSTOMDRAWDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NM_CUSTOMDRAW.h"
#include "NM_CUSTOMDRAWDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CNM_CUSTOMDRAWDlg �Ի���




CNM_CUSTOMDRAWDlg::CNM_CUSTOMDRAWDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNM_CUSTOMDRAWDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNM_CUSTOMDRAWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CNM_CUSTOMDRAWDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST1, &CNM_CUSTOMDRAWDlg::OnNMCustomdrawList1)
END_MESSAGE_MAP()


// CNM_CUSTOMDRAWDlg ��Ϣ�������

BOOL CNM_CUSTOMDRAWDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_ListCtrl.InsertColumn(0, _T("����"), 0, 200);
	m_ListCtrl.InsertItem(0, _T("����"));
	m_ListCtrl.InsertItem(1, _T("���"));
	m_ListCtrl.InsertItem(2, _T("��ͷ"));
	m_ListCtrl.InsertItem(3, _T("����"));
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNM_CUSTOMDRAWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNM_CUSTOMDRAWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNM_CUSTOMDRAWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNM_CUSTOMDRAWDlg::OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	if(pNMHDR->idFrom == IDC_LIST1)
	{
		//���Ͱ�ȫת��
		NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
		*pResult = 0;

		if(CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage)
		{
			//ÿ��item����Ҫ������Ϣ����
			*pResult = CDRF_NOTIFYITEMDRAW;
			return;
		}
		else if(CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage)
		{
			//������
			if(pLVCD->nmcd.dwItemSpec % 2)
				pLVCD->clrTextBk = RGB(255, 255, 128);
			//ż����
			else
				pLVCD->clrTextBk = RGB(128, 255, 255);
			//����
			*pResult = CDRF_DODEFAULT;
			return;
		}
	}

	*pResult = 0;
}
