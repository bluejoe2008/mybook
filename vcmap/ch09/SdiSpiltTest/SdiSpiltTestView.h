// SdiSpiltTestView.h : CSdiSpiltTestView ��Ľӿ�
//


#pragma once


class CSdiSpiltTestView : public CView
{
protected: // �������л�����
	CSdiSpiltTestView();
	DECLARE_DYNCREATE(CSdiSpiltTestView)

// ����
public:
	CSdiSpiltTestDoc* GetDocument() const;

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
	virtual ~CSdiSpiltTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SdiSpiltTestView.cpp �еĵ��԰汾
inline CSdiSpiltTestDoc* CSdiSpiltTestView::GetDocument() const
   { return reinterpret_cast<CSdiSpiltTestDoc*>(m_pDocument); }
#endif

