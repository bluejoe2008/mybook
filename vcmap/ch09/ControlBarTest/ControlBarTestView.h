// ControlBarTestView.h : CControlBarTestView ��Ľӿ�
//


#pragma once


class CControlBarTestView : public CView
{
protected: // �������л�����
	CControlBarTestView();
	DECLARE_DYNCREATE(CControlBarTestView)

// ����
public:
	CControlBarTestDoc* GetDocument() const;

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
	virtual ~CControlBarTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ControlBarTestView.cpp �еĵ��԰汾
inline CControlBarTestDoc* CControlBarTestView::GetDocument() const
   { return reinterpret_cast<CControlBarTestDoc*>(m_pDocument); }
#endif

