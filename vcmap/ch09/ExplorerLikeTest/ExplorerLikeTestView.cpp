// ExplorerLikeTestView.cpp : CExplorerLikeTestView ���ʵ��
//

#include "stdafx.h"
#include "ExplorerLikeTest.h"

#include "ExplorerLikeTestDoc.h"
#include "ExplorerLikeTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerLikeTestView

IMPLEMENT_DYNCREATE(CExplorerLikeTestView, CListView)

BEGIN_MESSAGE_MAP(CExplorerLikeTestView, CListView)
	ON_WM_STYLECHANGED()
END_MESSAGE_MAP()

// CExplorerLikeTestView ����/����

CExplorerLikeTestView::CExplorerLikeTestView()
{
	// TODO: �ڴ˴���ӹ������

}

CExplorerLikeTestView::~CExplorerLikeTestView()
{
}

BOOL CExplorerLikeTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void CExplorerLikeTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}


// CExplorerLikeTestView ���

#ifdef _DEBUG
void CExplorerLikeTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CExplorerLikeTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CExplorerLikeTestDoc* CExplorerLikeTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExplorerLikeTestDoc)));
	return (CExplorerLikeTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CExplorerLikeTestView ��Ϣ�������
void CExplorerLikeTestView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: ��Ӵ�������Ӧ�û��Դ�����ͼ��ʽ�ĸ���	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
