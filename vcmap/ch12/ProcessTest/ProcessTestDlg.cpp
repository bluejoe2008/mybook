// ProcessTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ProcessTest.h"
#include "ProcessTestDlg.h"

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


// CProcessTestDlg �Ի���




CProcessTestDlg::CProcessTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CProcessTestDlg::IDD, pParent)
, m_FileContent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcessTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILE_CONTENT, m_FileContent);
}

BEGIN_MESSAGE_MAP(CProcessTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_OPEN_FILE, &CProcessTestDlg::OnBnClickedOpenFile)
	ON_BN_CLICKED(ID_EDIT_FILE, &CProcessTestDlg::OnBnClickedEditFile)
	ON_STN_CLICKED(IDC_FILE_CONTENT, &CProcessTestDlg::OnStnClickedFileContent)
END_MESSAGE_MAP()


// CProcessTestDlg ��Ϣ�������

BOOL CProcessTestDlg::OnInitDialog()
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

void CProcessTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProcessTestDlg::OnPaint()
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
HCURSOR CProcessTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CProcessTestDlg::OnBnClickedOpenFile()
{
	CFileDialog dlg(TRUE);
	dlg.DoModal();

	m_FilePath = dlg.GetPathName();
	LoadFileContent();
}

int CProcessTestDlg::LoadFileContent(void)
{
	//��ָ���ļ�
	CFile file(m_FilePath, CFile::modeRead);

	m_FileContent = "";
	char bytes[1024];
	while(true)
	{
		//ÿ1024���ֽ�һ��
		memset(bytes, 0, sizeof(bytes));
		int read = file.Read(bytes, sizeof(bytes));
		m_FileContent += bytes;

		//������β��
		if(read < sizeof(bytes))
			break;
	}

	UpdateData(FALSE);
	return 0;
}

void CProcessTestDlg::OnBnClickedEditFile()
{
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	TCHAR cCommandLine[_MAX_PATH];

	// ���±������������
	_stprintf(cCommandLine, _T("notepad.exe \"%s\""), m_FilePath);

	// �������±�
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{ 
		// �ȴ��ӽ��̵��˳� 
		WaitForSingleObject(pi.hProcess, INFINITE); 
		// �ر��ӽ��̾�� 
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);

		//���¼����ļ�����
		LoadFileContent();
	}
}

void CProcessTestDlg::OnStnClickedFileContent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
