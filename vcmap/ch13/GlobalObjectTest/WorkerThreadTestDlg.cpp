// WorkerThreadTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WorkerThreadTest.h"
#include "WorkerThreadTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CWorkerThreadTestDlg 对话框




CWorkerThreadTestDlg::CWorkerThreadTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CWorkerThreadTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWorkerThreadTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
	DDX_Control(pDX, IDC_PROGREASS_TEXT, m_ProgressText);
}

BEGIN_MESSAGE_MAP(CWorkerThreadTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CWorkerThreadTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CWorkerThreadTestDlg 消息处理程序

BOOL CWorkerThreadTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWorkerThreadTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWorkerThreadTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWorkerThreadTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

struct WorkerStatus
{
	CString message;	//显示信息
	int count;			//当前计数
	bool isRunning;		//是否在运行？
};

WorkerStatus globalWorkerStatus;

UINT WorkerThreadA(LPVOID pParam)
{
	CWorkerThreadTestDlg * pDialog = (CWorkerThreadTestDlg *)pParam;

	for(int i = 0; i <= 100; i++)
	{
		//设定进度
		::globalWorkerStatus.count++;
		::globalWorkerStatus.message.Format(_T("%d%%"), i);

		//休息100毫秒
		Sleep(100);
	}

	pDialog->MessageBox(_T("WorkerThreadA线程结束！"));
	::globalWorkerStatus.isRunning = false;

	return 0;
}

UINT WorkerThreadB(LPVOID pParam)
{
	CWorkerThreadTestDlg * pDialog = (CWorkerThreadTestDlg *)pParam;

	while(globalWorkerStatus.isRunning)
	{
		pDialog->m_ProgressCtrl.SetPos(::globalWorkerStatus.count);
		pDialog->m_ProgressText.SetWindowText(::globalWorkerStatus.message);

		//休息100毫秒，否则文字会闪烁
		Sleep(100);
	}

	pDialog->MessageBox(_T("WorkerThreadB线程结束！"));
	return 0;
}

void CWorkerThreadTestDlg::OnBnClickedButton1()
{
	m_ProgressCtrl.SetRange(0, 100);

	::globalWorkerStatus.count = 0;
	::globalWorkerStatus.isRunning = true;

	//传递当前窗口指针至线程函数
	AfxBeginThread(WorkerThreadA, (LPVOID)this);
	AfxBeginThread(WorkerThreadB, (LPVOID)this);
}
