// CommDlgTestDlg.h : ͷ�ļ�
//

#pragma once


// CCommDlgTestDlg �Ի���
class CCommDlgTestDlg : public CDialog
{
// ����
public:
	CCommDlgTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CFindReplaceDialog * _pFindReplaceDlg;

// �Ի�������
	enum { IDD = IDD_COMMDLGTEST_DIALOG };

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
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnDestroy();
//	afx_msg void OnNcDestroy();
};
