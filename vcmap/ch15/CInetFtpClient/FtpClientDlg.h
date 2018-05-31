// FtpClientDlg.h : ͷ�ļ�
//

#include "FtpClient.h"
#pragma once


// CFtpClientDlg �Ի���
class CFtpClientDlg : public CDialog
{
// ����
public:
	CFtpClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CFtpClientDlg();

// �Ի�������
	enum { IDD = IDD_HTTP_DIALOG };

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
	CString m_sUrl;
	CString m_sResponse;

	void ShowResponse(CString msg);
	CString m_sStatus;
	void ShowStatus(CString msg);
	afx_msg void OnBnClickedButton1();
};
