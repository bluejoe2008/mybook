#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxmt.h"

// CCopyFileDialog �Ի���
class CCopyFileThread;

class CCopyFileDialog : public CDialog
{
	DECLARE_DYNAMIC(CCopyFileDialog)

public:
	int m_Ticks;

	CCopyFileThread * m_pThread;
	CCopyFileDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCopyFileDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	CProgressCtrl m_ProgressCtrl;
	CStatic m_ProgressText;
public:
	afx_msg void OnBnClickedCancel();
};
