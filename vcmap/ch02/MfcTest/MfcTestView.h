// MfcTestView.h : CMfcTestView ��Ľӿ�
//


#pragma once


class CMfcTestView : public CView
{
protected: // �������л�����
	CMfcTestView();
	DECLARE_DYNCREATE(CMfcTestView)

// ����
public:
	CMfcTestDoc* GetDocument() const;

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
	virtual ~CMfcTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MfcTestView.cpp �еĵ��԰汾
inline CMfcTestDoc* CMfcTestView::GetDocument() const
   { return reinterpret_cast<CMfcTestDoc*>(m_pDocument); }
#endif

