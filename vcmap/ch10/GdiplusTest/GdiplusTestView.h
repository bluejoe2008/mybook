// GdiplusTestView.h : CGdiplusTestView ��Ľӿ�
//


#pragma once


class CGdiplusTestView : public CView
{
protected: // �������л�����
	CGdiplusTestView();
	DECLARE_DYNCREATE(CGdiplusTestView)

// ����
public:
	CGdiplusTestDoc* GetDocument() const;
	ULONG_PTR m_gdiplusToken;

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
	virtual ~CGdiplusTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // GdiplusTestView.cpp �еĵ��԰汾
inline CGdiplusTestDoc* CGdiplusTestView::GetDocument() const
   { return reinterpret_cast<CGdiplusTestDoc*>(m_pDocument); }
#endif

