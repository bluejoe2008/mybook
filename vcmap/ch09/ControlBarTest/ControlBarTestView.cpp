// ControlBarTestView.cpp : CControlBarTestView ���ʵ��
//

#include "stdafx.h"
#include "ControlBarTest.h"

#include "ControlBarTestDoc.h"
#include "ControlBarTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlBarTestView

IMPLEMENT_DYNCREATE(CControlBarTestView, CView)

BEGIN_MESSAGE_MAP(CControlBarTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CControlBarTestView ����/����

CControlBarTestView::CControlBarTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CControlBarTestView::~CControlBarTestView()
{
}

BOOL CControlBarTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CControlBarTestView ����

void CControlBarTestView::OnDraw(CDC* /*pDC*/)
{
	CControlBarTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CControlBarTestView ��ӡ

BOOL CControlBarTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CControlBarTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CControlBarTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CControlBarTestView ���

#ifdef _DEBUG
void CControlBarTestView::AssertValid() const
{
	CView::AssertValid();
}

void CControlBarTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControlBarTestDoc* CControlBarTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlBarTestDoc)));
	return (CControlBarTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CControlBarTestView ��Ϣ�������
