// MyView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SdiSpiltTest.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
END_MESSAGE_MAP()


// CMyView ��ͼ

void CMyView::OnDraw(CDC* pDC)
{
	//���رհ�ť
	CRect rt;
	this->GetClientRect(&rt);
	pDC->DrawFrameControl(&rt, DFC_CAPTION, DFCS_CAPTIONCLOSE);
}


// CMyView ���

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView ��Ϣ�������
