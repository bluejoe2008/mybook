// SdiMfcDocViewTestView.cpp : CSdiMfcDocViewTestView ���ʵ��
//

#include "stdafx.h"
#include "SdiMfcDocViewTest.h"

#include "SdiMfcDocViewTestDoc.h"
#include "SdiMfcDocViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiMfcDocViewTestView

IMPLEMENT_DYNCREATE(CSdiMfcDocViewTestView, CView)

BEGIN_MESSAGE_MAP(CSdiMfcDocViewTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiMfcDocViewTestView ����/����

CSdiMfcDocViewTestView::CSdiMfcDocViewTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CSdiMfcDocViewTestView::~CSdiMfcDocViewTestView()
{
}

BOOL CSdiMfcDocViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSdiMfcDocViewTestView ����

void CSdiMfcDocViewTestView::OnDraw(CDC* /*pDC*/)
{
	CSdiMfcDocViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSdiMfcDocViewTestView ��ӡ

BOOL CSdiMfcDocViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSdiMfcDocViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSdiMfcDocViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSdiMfcDocViewTestView ���

#ifdef _DEBUG
void CSdiMfcDocViewTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiMfcDocViewTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiMfcDocViewTestDoc* CSdiMfcDocViewTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiMfcDocViewTestDoc)));
	return (CSdiMfcDocViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiMfcDocViewTestView ��Ϣ�������
