// MessageRouteTestView.h : CMessageRouteTestView ��Ľӿ�
//


#pragma once


class CMessageRouteTestView : public CView
{
protected: // �������л�����
	CMessageRouteTestView();
	DECLARE_DYNCREATE(CMessageRouteTestView)

// ����
public:
	CMessageRouteTestDoc* GetDocument() const;

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
	virtual ~CMessageRouteTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MessageRouteTestView.cpp �еĵ��԰汾
inline CMessageRouteTestDoc* CMessageRouteTestView::GetDocument() const
   { return reinterpret_cast<CMessageRouteTestDoc*>(m_pDocument); }
#endif

