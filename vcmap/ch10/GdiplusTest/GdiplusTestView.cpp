// GdiplusTestView.cpp : CGdiplusTestView ���ʵ��
//

#include "stdafx.h"

#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")

#include "GdiplusTest.h"

#include "GdiplusTestDoc.h"
#include "GdiplusTestView.h"
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTestView

IMPLEMENT_DYNCREATE(CGdiplusTestView, CView)

BEGIN_MESSAGE_MAP(CGdiplusTestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGdiplusTestView ����/����

CGdiplusTestView::CGdiplusTestView()
{
	GdiplusStartupInput input;
	GdiplusStartup(&m_gdiplusToken, &input, NULL);
}

CGdiplusTestView::~CGdiplusTestView()
{
	GdiplusShutdown(m_gdiplusToken);
}

BOOL CGdiplusTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGdiplusTestView ����

void CGdiplusTestView::OnDraw(CDC* pDC)
{
	Graphics g(pDC->m_hDC);
	CRect rt;
	GetClientRect(&rt);

	//���ư׵�
	SolidBrush brush(Color(255, 255, 255));
	g.FillRectangle(&brush, rt.left, rt.top, rt.right, rt.bottom);

	//����Բ
	Pen pen(Color(255, 0, 0), 2);
	g.DrawEllipse(&pen, 100, 100, 300, 300);

	//�������
	CString s(_T("welcome to http://vcer.net"));
	FontFamily ff(_T("Tahoma"));
	Font font(&ff, 24, FontStyleItalic, UnitPixel);
	
	SolidBrush blue(Color(0, 0, 255));
	g.DrawString(s, s.GetLength(), &font, PointF(350, 350), &blue);
}


// CGdiplusTestView ��ӡ

BOOL CGdiplusTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGdiplusTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGdiplusTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CGdiplusTestView ���

#ifdef _DEBUG
void CGdiplusTestView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusTestDoc* CGdiplusTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusTestDoc)));
	return (CGdiplusTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusTestView ��Ϣ�������
