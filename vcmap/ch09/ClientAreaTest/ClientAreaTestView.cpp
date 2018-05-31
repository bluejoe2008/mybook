// ClientAreaTestView.cpp : CClientAreaTestView ���ʵ��
//

#include "stdafx.h"
#include "ClientAreaTest.h"
#include "MainFrm.h"

#include "ClientAreaTestDoc.h"
#include "ClientAreaTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientAreaTestView

IMPLEMENT_DYNCREATE(CClientAreaTestView, CView)

BEGIN_MESSAGE_MAP(CClientAreaTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CClientAreaTestView ����/����

CClientAreaTestView::CClientAreaTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CClientAreaTestView::~CClientAreaTestView()
{
}

BOOL CClientAreaTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CClientAreaTestView ����

void CClientAreaTestView::OnDraw(CDC* /*pDC*/)
{
	CClientAreaTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CClientAreaTestView ��ӡ

BOOL CClientAreaTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CClientAreaTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CClientAreaTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CClientAreaTestView ���

#ifdef _DEBUG
void CClientAreaTestView::AssertValid() const
{
	CView::AssertValid();
}

void CClientAreaTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClientAreaTestDoc* CClientAreaTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientAreaTestDoc)));
	return (CClientAreaTestDoc*)m_pDocument;
}
#endif //_DEBUG

void CClientAreaTestView::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CView::OnNcMouseMove(nHitTest, point);
}

void CClientAreaTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CView::OnMouseMove(nFlags, point);
}