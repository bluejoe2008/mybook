// MyCircleView.cpp : CMyCircleView ���ʵ��
//

#include "stdafx.h"
#include "MyCircle.h"

#include "MyCircleDoc.h"
#include "MyCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyCircleView

IMPLEMENT_DYNCREATE(CMyCircleView, CView)

BEGIN_MESSAGE_MAP(CMyCircleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_CREATE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMyCircleView ����/����

CMyCircleView::CMyCircleView()
{
	// TODO: �ڴ˴���ӹ������

}

CMyCircleView::~CMyCircleView()
{
}

BOOL CMyCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyCircleView ����

void CMyCircleView::OnDraw(CDC* pDC)
{
	//��ȡ���ߴ�
	CRect rt;
	GetClientRect(&rt);
	
	//���ư׵�
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pDC->FillRect(&rt, &brush);

	//����Բ
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen * pOldPen = pDC->SelectObject(&pen);
	pDC->Ellipse(100, 100, 300, 300);

	//�������
	CFont font;
	font.CreatePointFont(200, _T("Tahoma"));
	CFont * pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(350, 350, CString(_T("welcome to http://vcer.net")));

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont);
}


// CMyCircleView ��ӡ

BOOL CMyCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMyCircleView ���

#ifdef _DEBUG
void CMyCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCircleDoc* CMyCircleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCircleDoc)));
	return (CMyCircleDoc*)m_pDocument;
}
#endif //_DEBUG

void CMyCircleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
}
