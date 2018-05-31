// SwordManDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CSwordManDlg �Ի���
class CSwordManDlg : public CDialog
{
// ����
public:
	CSwordManDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SWORDMAN_DIALOG };

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
	CListCtrl m_ActorList;
public:
	CString m_Name;
public:
	int m_Age;
public:
	CString m_Words;

	CBitmap m_Faces;
	CImageList m_ImageList;
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
