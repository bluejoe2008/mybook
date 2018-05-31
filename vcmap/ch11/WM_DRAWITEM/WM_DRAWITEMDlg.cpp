// WM_DRAWITEMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WM_DRAWITEM.h"
#include "WM_DRAWITEMDlg.h"

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


// CWM_DRAWITEMDlg �Ի���




CWM_DRAWITEMDlg::CWM_DRAWITEMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWM_DRAWITEMDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWM_DRAWITEMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWM_DRAWITEMDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CWM_DRAWITEMDlg ��Ϣ�������

BOOL CWM_DRAWITEMDlg::OnInitDialog()
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

void CWM_DRAWITEMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWM_DRAWITEMDlg::OnPaint()
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
HCURSOR CWM_DRAWITEMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWM_DRAWITEMDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if(nIDCtl == IDC_BUTTON1)
	{
		//���ư�ť���

		UINT uStyle = DFCS_BUTTONPUSH;
		//�Ƿ���ȥ�ˣ�
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
			uStyle |= DFCS_PUSHED;

		CDC dc;
		dc.Attach(lpDrawItemStruct->hDC);
		dc.DrawFrameControl(&lpDrawItemStruct->rcItem, DFC_BUTTON, uStyle);

		//��ȡ���ı�
		CWnd * pCtrl = GetDlgItem(nIDCtl);
		CString sText;
		pCtrl->GetWindowText(sText);
		//���Ц��
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			sText += ":(";
		}
		else
		{
			sText += ":)";
		}


		//�������
		dc.TextOut(lpDrawItemStruct->rcItem.left + 20, lpDrawItemStruct->rcItem.top + 20, sText);

		//�Ƿ�õ�����
		if(lpDrawItemStruct->itemState & ODS_FOCUS)
		{
			//�����
			CRect rtFocus = lpDrawItemStruct->rcItem;
			rtFocus.DeflateRect(3, 3);
			dc.DrawFocusRect(&rtFocus);
		}

		return;
	}
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
