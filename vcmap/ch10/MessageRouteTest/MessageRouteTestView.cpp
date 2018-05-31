// MessageRouteTestView.cpp : CMessageRouteTestView ���ʵ��
//

#include "stdafx.h"
#include "MessageRouteTest.h"

#include "MessageRouteTestDoc.h"
#include "MessageRouteTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageRouteTestView

IMPLEMENT_DYNCREATE(CMessageRouteTestView, CView)

BEGIN_MESSAGE_MAP(CMessageRouteTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//ON_COMMAND(ID_FILE_OPEN, &CMessageRouteTestView::OnFileOpen)
END_MESSAGE_MAP()

// CMessageRouteTestView ����/����

CMessageRouteTestView::CMessageRouteTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CMessageRouteTestView::~CMessageRouteTestView()
{
}

BOOL CMessageRouteTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMessageRouteTestView ����

void CMessageRouteTestView::OnDraw(CDC* /*pDC*/)
{
	CMessageRouteTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMessageRouteTestView ��ӡ

BOOL CMessageRouteTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMessageRouteTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMessageRouteTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMessageRouteTestView ���

#ifdef _DEBUG
void CMessageRouteTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMessageRouteTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessageRouteTestDoc* CMessageRouteTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessageRouteTestDoc)));
	return (CMessageRouteTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessageRouteTestView ��Ϣ�������

void CMessageRouteTestView::OnFileOpen()
{
	::MessageBox(NULL, _T(__FUNCTION__), _T(""), MB_OK);
}
