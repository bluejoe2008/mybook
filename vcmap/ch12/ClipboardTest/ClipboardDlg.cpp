// ClipboardDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clipboard.h"
#include "ClipboardDlg.h"

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


// CClipboardDlg �Ի���




CClipboardDlg::CClipboardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClipboardDlg::IDD, pParent)
	, m_Text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Text);
}

BEGIN_MESSAGE_MAP(CClipboardDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_COPY_DATA, &CClipboardDlg::OnBnClickedCopyData)
	ON_BN_CLICKED(IDC_PASTE_DATA, &CClipboardDlg::OnBnClickedPasteData)
END_MESSAGE_MAP()


// CClipboardDlg ��Ϣ�������

BOOL CClipboardDlg::OnInitDialog()
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

void CClipboardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClipboardDlg::OnPaint()
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
HCURSOR CClipboardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CClipboardDlg::OnBnClickedCopyData()
{
	//��ȡ�ı�����
	UpdateData(TRUE);
	if(OpenClipboard())
	{
		//����ȫ���ڴ��
		int size = m_Text.GetLength() * sizeof(TCHAR);
		HANDLE hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(TCHAR));
		TCHAR * buffer = (TCHAR *)GlobalLock(hMem);
		memset(buffer, 0, size + 1 * sizeof(TCHAR));
		memcpy(buffer, (LPCTSTR)m_Text, size);
		GlobalUnlock(hMem);

		//����ռ�����
		EmptyClipboard();
		//���ü����������
#ifdef UNICODE
		SetClipboardData(CF_UNICODETEXT, hMem);
#else
		SetClipboardData(CF_TEXT, hMem);
#endif
		CloseClipboard();
	}
}

void CClipboardDlg::OnBnClickedPasteData()
{
	if(OpenClipboard())
	{
		//ANSI����
		if(IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hMem = GetClipboardData(CF_TEXT);
			char * buffer = (char *)GlobalLock(hMem);
			GlobalUnlock(hMem);
			m_Text = buffer;
		}

		//UNICODE����
		if(IsClipboardFormatAvailable(CF_UNICODETEXT))
		{
			HANDLE hMem = GetClipboardData(CF_UNICODETEXT);
			wchar_t * buffer = (wchar_t *)GlobalLock(hMem);
			GlobalUnlock(hMem);
			m_Text = buffer;
		}

		CloseClipboard();
		UpdateData(FALSE);
	}
}