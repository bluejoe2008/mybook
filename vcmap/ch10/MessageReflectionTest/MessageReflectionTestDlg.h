// MessageReflectionTestDlg.h : ͷ�ļ�
//

#pragma once
#include "hitcounter.h"


// CMessageReflectionTestDlg �Ի���
class CMessageReflectionTestDlg : public CDialog
{
// ����
public:
	CMessageReflectionTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MESSAGEREFLECTIONTEST_DIALOG };

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
	CHitCounter m_HitCounter;
	afx_msg void OnBnClickedButton1();
};
