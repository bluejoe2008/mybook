// SdiMfcDocViewTestView.h : CSdiMfcDocViewTestView ��Ľӿ�
//


#pragma once


class CSdiMfcDocViewTestView : public CView
{
protected: // �������л�����
	CSdiMfcDocViewTestView();
	DECLARE_DYNCREATE(CSdiMfcDocViewTestView)

// ����
public:
	CSdiMfcDocViewTestDoc* GetDocument() const;

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
	virtual ~CSdiMfcDocViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SdiMfcDocViewTestView.cpp �еĵ��԰汾
inline CSdiMfcDocViewTestDoc* CSdiMfcDocViewTestView::GetDocument() const
   { return reinterpret_cast<CSdiMfcDocViewTestDoc*>(m_pDocument); }
#endif

