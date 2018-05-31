// TrayIconTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TrayIconTest.h"
#include "TrayIconTestDlg.h"

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


// CTrayIconTestDlg �Ի���




CTrayIconTestDlg::CTrayIconTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrayIconTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrayIconTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrayIconTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTrayIconTestDlg ��Ϣ�������

BOOL CTrayIconTestDlg::OnInitDialog()
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
	m_Nid.cbSize = sizeof(NOTIFYICONDATA);
	m_Nid.hWnd = GetSafeHwnd();
	m_Nid.uID = 0;
	m_Nid.hIcon = m_hIcon; //����ͼ��
	m_Nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	m_Nid.uCallbackMessage = WM_COMMAND;

	CString sTitle = _T("����[bluejoe2008@gmail.com]");
	_tcscpy(m_Nid.szTip, sTitle); //������ʾ�ı�
	Shell_NotifyIcon(NIM_ADD, &m_Nid);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTrayIconTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTrayIconTestDlg::OnPaint()
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
HCURSOR CTrayIconTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTrayIconTestDlg::OnDestroy()
{
	CDialog::OnDestroy();
	Shell_NotifyIcon(NIM_DELETE, &m_Nid);	
}

BOOL CTrayIconTestDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if(!wParam)
	{
		switch(lParam)
		{
		case WM_RBUTTONUP:
			//��ʾ�����˵�
			CMenu Menu, *pMenu;
			Menu.LoadMenu(IDR_MENU1);
			pMenu=Menu.GetSubMenu(0);

			SetForegroundWindow();
			POINT Pt;
			//���ò˵���ʾλ��
			GetCursorPos(&Pt);
			pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_BOTTOMALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, Pt.x, Pt.y, this);
			break;
		}
	}		
	return CDialog::OnCommand(wParam, lParam);
}
