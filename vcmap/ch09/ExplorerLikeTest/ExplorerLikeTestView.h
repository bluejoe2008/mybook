// ExplorerLikeTestView.h : CExplorerLikeTestView ��Ľӿ�
//


#pragma once


class CExplorerLikeTestView : public CListView
{
protected: // �������л�����
	CExplorerLikeTestView();
	DECLARE_DYNCREATE(CExplorerLikeTestView)

// ����
public:
	CExplorerLikeTestDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CExplorerLikeTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ExplorerLikeTestView.cpp �еĵ��԰汾
inline CExplorerLikeTestDoc* CExplorerLikeTestView::GetDocument() const
   { return reinterpret_cast<CExplorerLikeTestDoc*>(m_pDocument); }
#endif

