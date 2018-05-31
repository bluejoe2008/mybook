// TrueButtonView.h : CTrueButtonView ��Ľӿ�
//


#pragma once


class CTrueButtonView : public CView
{
protected: // �������л�����
	CTrueButtonView();
	DECLARE_DYNCREATE(CTrueButtonView)

// ����
public:
	CTrueButtonDoc* GetDocument() const;
	CButton m_Button;
	CStatic m_Static;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTrueButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // TrueButtonView.cpp �еĵ��԰汾
inline CTrueButtonDoc* CTrueButtonView::GetDocument() const
   { return reinterpret_cast<CTrueButtonDoc*>(m_pDocument); }
#endif

