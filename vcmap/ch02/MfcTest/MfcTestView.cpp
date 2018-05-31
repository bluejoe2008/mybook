// MfcTestView.cpp : CMfcTestView ���ʵ��
//

#include "stdafx.h"
#include "MfcTest.h"

#include "MfcTestDoc.h"
#include "MfcTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcTestView

IMPLEMENT_DYNCREATE(CMfcTestView, CView)

BEGIN_MESSAGE_MAP(CMfcTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMfcTestView ����/����

CMfcTestView::CMfcTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CMfcTestView::~CMfcTestView()
{
}

BOOL CMfcTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMfcTestView ����

void CMfcTestView::OnDraw(CDC* /*pDC*/)
{
	CMfcTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMfcTestView ��ӡ

BOOL CMfcTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMfcTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMfcTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMfcTestView ���

#ifdef _DEBUG
void CMfcTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMfcTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfcTestDoc* CMfcTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcTestDoc)));
	return (CMfcTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMfcTestView ��Ϣ�������
