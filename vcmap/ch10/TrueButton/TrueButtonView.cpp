// TrueButtonView.cpp : CTrueButtonView ���ʵ��
//

#include "stdafx.h"
#include "TrueButton.h"

#include "TrueButtonDoc.h"
#include "TrueButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrueButtonView

IMPLEMENT_DYNCREATE(CTrueButtonView, CView)

BEGIN_MESSAGE_MAP(CTrueButtonView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTrueButtonView ����/����

CTrueButtonView::CTrueButtonView()
{
	// TODO: �ڴ˴���ӹ������

}

CTrueButtonView::~CTrueButtonView()
{
}

BOOL CTrueButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTrueButtonView ����

void CTrueButtonView::OnDraw(CDC* /*pDC*/)
{
	CTrueButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTrueButtonView ��ӡ

BOOL CTrueButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTrueButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTrueButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CTrueButtonView ���

#ifdef _DEBUG
void CTrueButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CTrueButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrueButtonDoc* CTrueButtonView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrueButtonDoc)));
	return (CTrueButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CTrueButtonView ��Ϣ�������

int CTrueButtonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//����һ�������İ�ť��
	m_Button.Create(_T("Hello, World!"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 110, 220, 150), this, 1000);
	//����һ���������ı���ǩ��
	m_Static.Create(_T("welcome to http://vcer.net"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, CRect(350, 350, 450, 400), this);

	return 0;
}
