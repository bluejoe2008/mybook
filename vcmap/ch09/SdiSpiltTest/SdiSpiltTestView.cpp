// SdiSpiltTestView.cpp : CSdiSpiltTestView ���ʵ��
//

#include "stdafx.h"
#include "SdiSpiltTest.h"

#include "SdiSpiltTestDoc.h"
#include "SdiSpiltTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSpiltTestView

IMPLEMENT_DYNCREATE(CSdiSpiltTestView, CView)

BEGIN_MESSAGE_MAP(CSdiSpiltTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiSpiltTestView ����/����

CSdiSpiltTestView::CSdiSpiltTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CSdiSpiltTestView::~CSdiSpiltTestView()
{
}

BOOL CSdiSpiltTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSdiSpiltTestView ����

void CSdiSpiltTestView::OnDraw(CDC* pDC)
{
	//��Բ
	CRect rt;
	this->GetClientRect(&rt);
	pDC->Ellipse(&rt);
}


// CSdiSpiltTestView ��ӡ

BOOL CSdiSpiltTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSdiSpiltTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSdiSpiltTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSdiSpiltTestView ���

#ifdef _DEBUG
void CSdiSpiltTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiSpiltTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiSpiltTestDoc* CSdiSpiltTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSpiltTestDoc)));
	return (CSdiSpiltTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSpiltTestView ��Ϣ�������
