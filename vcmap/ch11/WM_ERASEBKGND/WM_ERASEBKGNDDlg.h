// WM_ERASEBKGNDDlg.h : ͷ�ļ�
//

#include <atlimage.h>
#pragma once


// CWM_ERASEBKGNDDlg �Ի���
class CWM_ERASEBKGNDDlg : public CDialog
{
// ����
public:
	CWM_ERASEBKGNDDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WM_ERASEBKGND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CImage m_Image;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
