// CSockEventServerDlg.h : ͷ�ļ�
//

#pragma once
#include "McdListenSocket.h"

// CMcdServerDlg �Ի���
class CMcdServerDlg : public CDialog
{
// ����
public:
	CMcdServerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMcdListenSocket * m_pListenSocket;

// �Ի�������
	enum { IDD = IDD_CSOCKEVENTSERVER_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	~CMcdServerDlg(void);
};
