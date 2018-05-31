#pragma once

// McdOcxCtrl.h : CMcdOcxCtrl ActiveX �ؼ����������


// CMcdOcxCtrl : �й�ʵ�ֵ���Ϣ������� McdOcxCtrl.cpp��

class CMcdOcxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMcdOcxCtrl)

// ���캯��
public:
	CMcdOcxCtrl();

// ��д
public:
	int _a;
	int _b;

	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CMcdOcxCtrl();

	DECLARE_OLECREATE_EX(CMcdOcxCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMcdOcxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMcdOcxCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMcdOcxCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidDirection = 2,
		dispidSetNumbers = 1L
	};
private:
	int _mcd(int a, int b);
protected:
	void SetNumbers(SHORT a, SHORT b);
	void OnDirectionChanged(void);
	SHORT m_Direction;
};

