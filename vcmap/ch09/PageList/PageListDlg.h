// PageListDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CPageListDlg �Ի���
class CPageListDlg : public CDialog
{
// ����
public:
	CPageListDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PAGELIST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_ToolBarContainer;
	CStatic m_PageContainer;

	CToolBar m_ToolBar;
	CDialog * m_ActivePage;
	CDialog * m_Page1;
	CDialog * m_Page2;
	afx_msg void OnDestroy();
	afx_msg void OnXPage1();
	afx_msg void OnXPage2();
	void ActivePage(CDialog * pDialog);
};
