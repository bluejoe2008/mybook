// MyCircleView.h : CMyCircleView ��Ľӿ�
//


#pragma once


class CMyCircleView : public CView
{
protected: // �������л�����
	CMyCircleView();
	DECLARE_DYNCREATE(CMyCircleView)

// ����
public:
	CMyCircleDoc* GetDocument() const;

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
	virtual ~CMyCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MyCircleView.cpp �еĵ��԰汾
inline CMyCircleDoc* CMyCircleView::GetDocument() const
   { return reinterpret_cast<CMyCircleDoc*>(m_pDocument); }
#endif

