// NM_CUSTOMDRAWDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CNM_CUSTOMDRAWDlg �Ի���
class CNM_CUSTOMDRAWDlg : public CDialog
{
// ����
public:
	CNM_CUSTOMDRAWDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NM_CUSTOMDRAW_DIALOG };

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
	afx_msg void OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_ListCtrl;
};
