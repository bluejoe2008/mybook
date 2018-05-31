// OpenGLTestView.h : COpenGLTestView ��Ľӿ�
//


#pragma once

class COpenGLTestView : public CView
{
protected: // �������л�����
	COpenGLTestView();
	DECLARE_DYNCREATE(COpenGLTestView)

// ����
public:
	int m_GLPixelIndex;
	HGLRC m_hGLContext;
	COpenGLTestDoc* GetDocument() const;

// ����
public:
	BOOL SetWindowPixelFormat(HDC hDC);
	BOOL CreateViewGLContext(HDC hDC);
	void RenderScene(void);

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
	virtual ~COpenGLTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // OpenGLTestView.cpp �еĵ��԰汾
inline COpenGLTestDoc* COpenGLTestView::GetDocument() const
   { return reinterpret_cast<COpenGLTestDoc*>(m_pDocument); }
#endif

