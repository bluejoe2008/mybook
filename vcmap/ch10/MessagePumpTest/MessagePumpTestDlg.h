// MessagePumpTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CMessagePumpTestDlg �Ի���
class CMessagePumpTestDlg : public CDialog
{
// ����
public:
	CMessagePumpTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MESSAGEPUMPTEST_DIALOG };

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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CString m_sClock;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
