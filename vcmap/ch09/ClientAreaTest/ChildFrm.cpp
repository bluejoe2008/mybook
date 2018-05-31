// ChildFrm.cpp : CChildFrame ���ʵ��
//
#include "stdafx.h"
#include "ClientAreaTest.h"

#include "ChildFrm.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_WM_NCMOUSEMOVE()
	//ON_WM_NCMOUSELEAVE()
	//ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame ��Ϣ�������

void CChildFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CMDIChildWnd::OnNcMouseMove(nHitTest, point);
}

void CChildFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CMDIChildWnd::OnMouseMove(nFlags, point);
}
