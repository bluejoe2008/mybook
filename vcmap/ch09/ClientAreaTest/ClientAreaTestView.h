// ClientAreaTestView.h : CClientAreaTestView ��Ľӿ�
//


#pragma once


class CClientAreaTestView : public CView
{
protected: // �������л�����
	CClientAreaTestView();
	DECLARE_DYNCREATE(CClientAreaTestView)

// ����
public:
	CClientAreaTestDoc* GetDocument() const;

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
	virtual ~CClientAreaTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseLeave();
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

#ifndef _DEBUG  // ClientAreaTestView.cpp �еĵ��԰汾
inline CClientAreaTestDoc* CClientAreaTestView::GetDocument() const
   { return reinterpret_cast<CClientAreaTestDoc*>(m_pDocument); }
#endif

