// TrayIconTestDlg.h : ͷ�ļ�
//

#pragma once


// CTrayIconTestDlg �Ի���
class CTrayIconTestDlg : public CDialog
{
// ����
public:
	CTrayIconTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TRAYICONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	NOTIFYICONDATA m_Nid;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
