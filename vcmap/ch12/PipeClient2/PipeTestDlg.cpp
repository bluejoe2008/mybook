// PipeTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PipeTest.h"
#include "PipeTestDlg.h"

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


// CPipeTestDlg �Ի���




CPipeTestDlg::CPipeTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPipeTestDlg::IDD, pParent)
, m_radius(0)
, m_cir(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPipeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_radius);
	DDX_Text(pDX, IDC_EDIT2, m_cir);
}

BEGIN_MESSAGE_MAP(CPipeTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RUN_IT, &CPipeTestDlg::OnBnClickedRunIt)
END_MESSAGE_MAP()


// CPipeTestDlg ��Ϣ�������

BOOL CPipeTestDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPipeTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPipeTestDlg::OnPaint()
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
HCURSOR CPipeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPipeTestDlg::OnBnClickedRunIt()
{
	UpdateData(TRUE);

	HANDLE hChildStdInRead, hChildStdInWrite;
	HANDLE hChildStdOutRead, hChildStdOutWrite;

	//��ȫ����
	SECURITY_ATTRIBUTES sa; 

	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
	sa.bInheritHandle = TRUE; //�ӽ��̿��Լ̳и����̴����ܵ��Ķ�д���
	sa.lpSecurityDescriptor = NULL; 

	//������׼����ܵ�
	if(!CreatePipe(&hChildStdInRead, &hChildStdInWrite, &sa, 0))
	{
		MessageBox(_T("������׼����ܵ�ʧ�ܣ�"));
		return;
	}

	//������׼����ܵ�
	if(!CreatePipe(&hChildStdOutRead, &hChildStdOutWrite, &sa, 0))
	{
		MessageBox(_T("������׼����ܵ�ʧ�ܣ�"));
		return;
	}

	//�߳�����
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	si.wShowWindow = SW_HIDE;
	si.hStdInput = hChildStdInRead;
	si.hStdOutput = hChildStdOutWrite;
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES; //ʹ����ʾ���ںͱ�׼����ı�־

	TCHAR cCommandLine[_MAX_PATH] = _T("PipeServer.exe");

	// ����PipeServer.exe
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		DWORD count;
		count = 0;
		//���Ͱ뾶ֵ
		WriteFile(hChildStdInWrite, &m_radius, sizeof(m_radius), &count, NULL);

		count = 0;
		//��ȡԲ��ֵ
		ReadFile(hChildStdOutRead, &m_cir, sizeof(m_cir), &count, NULL);

		UpdateData(FALSE);
	}
}
