// ProcessTestDlg.h : ͷ�ļ�
//

#pragma once


// CProcessTestDlg �Ի���
class CProcessTestDlg : public CDialog
{
// ����
public:
	CProcessTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PROCESSTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CString m_FilePath;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_FileContent;
	afx_msg void OnBnClickedOpenFile();
	int LoadFileContent(void);
	afx_msg void OnBnClickedEditFile();
	afx_msg void OnStnClickedFileContent();
};
