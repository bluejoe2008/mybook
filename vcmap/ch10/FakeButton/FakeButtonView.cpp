// FakeButtonView.cpp : CFakeButtonView ���ʵ��
//

#include "stdafx.h"
#include "FakeButton.h"

#include "FakeButtonDoc.h"
#include "FakeButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFakeButtonView

IMPLEMENT_DYNCREATE(CFakeButtonView, CView)

BEGIN_MESSAGE_MAP(CFakeButtonView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFakeButtonView ����/����

CFakeButtonView::CFakeButtonView()
{
	// TODO: �ڴ˴���ӹ������

}

CFakeButtonView::~CFakeButtonView()
{
}

BOOL CFakeButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFakeButtonView ����

void CFakeButtonView::OnDraw(CDC* pDC)
{
	//�������ť
	CRect rt(100, 110, 220, 150);
	pDC->DrawFrameControl(rt, DFC_BUTTON, DFCS_BUTTONPUSH);

	//�������
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(120, 120, _T("Hello, World!"));
	rt.DeflateRect(3, 3);
	pDC->DrawFocusRect(rt);

	//��ѡ��
	pDC->DrawFrameControl(CRect(100, 180, 220, 194), DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
	//��ѡ��
	pDC->DrawFrameControl(CRect(100, 200, 220, 214), DFC_BUTTON, DFCS_BUTTONRADIO | DFCS_CHECKED);

	//������
	pDC->DrawFrameControl(CRect(100, 220, 220, 240), DFC_SCROLL, DFCS_SCROLLUP);
	pDC->DrawFrameControl(CRect(100, 240, 220, 260), DFC_SCROLL, DFCS_SCROLLDOWN);
}


// CFakeButtonView ��ӡ

BOOL CFakeButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFakeButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFakeButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFakeButtonView ���

#ifdef _DEBUG
void CFakeButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CFakeButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFakeButtonDoc* CFakeButtonView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFakeButtonDoc)));
	return (CFakeButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CFakeButtonView ��Ϣ�������
