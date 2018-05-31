// PageListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PageList.h"
#include "Page1.h"
#include "Page2.h"
#include "PageListDlg.h"

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


// CPageListDlg �Ի���




CPageListDlg::CPageListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ActivePage = NULL;
}

void CPageListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TOOLBAR_CONTAINER, m_ToolBarContainer);
	DDX_Control(pDX, IDC_PAGE_CONTAINER, m_PageContainer);
}

BEGIN_MESSAGE_MAP(CPageListDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_COMMAND(ID_X_PAGE1, &CPageListDlg::OnXPage1)
	ON_COMMAND(ID_X_PAGE2, &CPageListDlg::OnXPage2)
END_MESSAGE_MAP()


// CPageListDlg ��Ϣ�������

BOOL CPageListDlg::OnInitDialog()
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

	//����������
	m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
      | CBRS_GRIPPER | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_RIGHT | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	//���ع�����
	m_ToolBar.LoadToolBar(IDR_TOOLBAR2);

	//��������
	m_ToolBar.GetToolBarCtrl().ModifyStyle(0, TBSTYLE_WRAPABLE);
	CRect rect;
	m_ToolBarContainer.GetWindowRect(&rect);
	ScreenToClient(rect);
	//�ڷŹ�����
	m_ToolBar.MoveWindow(&rect);

	//���ضԻ���
	m_Page1 = new CPage1();
	m_Page1->Create(CPage1::IDD);

	m_Page2 = new CPage2();
	m_Page2->Create(CPage2::IDD);

	//�ڷŶԻ���
	m_PageContainer.GetWindowRect(&rect);
	ScreenToClient(rect);

	m_Page1->MoveWindow(&rect);
	m_Page1->ShowWindow(SW_HIDE);

	m_Page2->MoveWindow(&rect);
	m_Page2->ShowWindow(SW_HIDE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPageListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPageListDlg::OnPaint()
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
HCURSOR CPageListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPageListDlg::OnDestroy()
{
	CDialog::OnDestroy();

	m_Page1->DestroyWindow();
	delete m_Page1;

	m_Page2->DestroyWindow();
	delete m_Page2;
}

void CPageListDlg::OnXPage1()
{
	ActivePage(m_Page1);
}

void CPageListDlg::OnXPage2()
{
	ActivePage(m_Page2);
}

void CPageListDlg::ActivePage(CDialog * pDialog)
{
	if(m_ActivePage != pDialog)
	{
		if(m_ActivePage != NULL)
		{
			//���ص�ǰ�����
			m_ActivePage->ShowWindow(SW_HIDE);
		}

		pDialog->ShowWindow(SW_SHOW);
		m_ActivePage = pDialog;
	}
}
