// CommDlgTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CommDlgTest.h"
#include "CommDlgTestDlg.h"

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


// CCommDlgTestDlg �Ի���




CCommDlgTestDlg::CCommDlgTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCommDlgTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	_pFindReplaceDlg = NULL;
}

void CCommDlgTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCommDlgTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2, &CCommDlgTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCommDlgTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CCommDlgTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CCommDlgTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCommDlgTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCommDlgTestDlg::OnBnClickedButton6)
	ON_WM_DESTROY()
	//	ON_WM_NCDESTROY()
END_MESSAGE_MAP()


// CCommDlgTestDlg ��Ϣ�������

BOOL CCommDlgTestDlg::OnInitDialog()
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


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCommDlgTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommDlgTestDlg::OnPaint()
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
HCURSOR CCommDlgTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCommDlgTestDlg::OnBnClickedButton2()
{
	CFindReplaceDialog *pDlg = new CFindReplaceDialog();
	pDlg->Create(TRUE, _T(""), _T(""), FR_DOWN, this); 
}

void CCommDlgTestDlg::OnBnClickedButton3()
{
	CColorDialog cd;
	cd.DoModal();
}

void CCommDlgTestDlg::OnBnClickedButton1()
{
	CFileDialog cd(TRUE);
	cd.DoModal();
}

void CCommDlgTestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fd;
	fd.DoModal();
}

void CCommDlgTestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPrintDialog pd(TRUE);
	pd.DoModal();
}

void CCommDlgTestDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPageSetupDialog psd;
	psd.DoModal();
}

void CCommDlgTestDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}
