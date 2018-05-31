// HttpSocketDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpClient.h"
#include "HttpClientDlg.h"

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


// CHttpClientDlg �Ի���




CHttpClientDlg::CHttpClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHttpClientDlg::IDD, pParent)
	, m_sUrl(_T("http://vcer.net"))
	, m_sResponse(_T(""))
	, m_sStatus(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHttpClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sUrl);
	DDX_Text(pDX, IDC_EDIT2, m_sResponse);
	DDX_Text(pDX, IDC_STATUS, m_sStatus);
}

BEGIN_MESSAGE_MAP(CHttpClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CHttpClientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHttpClientDlg ��Ϣ�������

BOOL CHttpClientDlg::OnInitDialog()
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

void CHttpClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHttpClientDlg::OnPaint()
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
HCURSOR CHttpClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CHttpClientDlg::~CHttpClientDlg()
{
}


void CHttpClientDlg::ShowResponse(CString msg)
{
	this->m_sResponse = msg;
	UpdateData(FALSE);
}

void CHttpClientDlg::ShowStatus(CString msg)
{
	this->m_sStatus = msg;
	UpdateData(FALSE);
}

void CHttpClientDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString sHost;
	INTERNET_PORT nPort;
	CString sPath;

	DWORD serviceType;
	//����URL��
	if(AfxParseURL(m_sUrl, serviceType, sHost, sPath, nPort)
		&& serviceType == AFX_INET_SERVICE_HTTP)
	{
		//session
		CInternetSession session;
		//connection
		CHttpConnection * pConnection = session.GetHttpConnection(sHost, nPort);
		if(pConnection)
		{
			CString sObjectName;
			//file
			CHttpFile * pFile = pConnection->OpenRequest("GET", sObjectName);
			pFile->SendRequest();
			DWORD code;
			pFile->QueryInfoStatusCode(code);
			if(code == HTTP_STATUS_OK)
			{
				//��ȡ�ļ�
				CString body;
				char block[1024];
				DWORD read;
				while(true)
				{
					read = pFile->Read(block, 1024);
					block[read - 1] = 0;
					body += block;

					if(read < 1024)
						break;
				}
				//��ȡ��ϣ���ʾ֮
				ShowResponse(body);
			}
		}
	}
}