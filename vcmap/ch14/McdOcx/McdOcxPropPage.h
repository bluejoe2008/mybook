#pragma once

// McdOcxPropPage.h : CMcdOcxPropPage ����ҳ���������


// CMcdOcxPropPage : �й�ʵ�ֵ���Ϣ������� McdOcxPropPage.cpp��

class CMcdOcxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMcdOcxPropPage)
	DECLARE_OLECREATE_EX(CMcdOcxPropPage)

// ���캯��
public:
	CMcdOcxPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MCDOCX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

