// ExplorerLikeTestDoc.cpp : CExplorerLikeTestDoc ���ʵ��
//

#include "stdafx.h"
#include "ExplorerLikeTest.h"

#include "ExplorerLikeTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerLikeTestDoc

IMPLEMENT_DYNCREATE(CExplorerLikeTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CExplorerLikeTestDoc, CDocument)
END_MESSAGE_MAP()


// CExplorerLikeTestDoc ����/����

CExplorerLikeTestDoc::CExplorerLikeTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CExplorerLikeTestDoc::~CExplorerLikeTestDoc()
{
}

BOOL CExplorerLikeTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExplorerLikeTestDoc ���л�

void CExplorerLikeTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CExplorerLikeTestDoc ���

#ifdef _DEBUG
void CExplorerLikeTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExplorerLikeTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExplorerLikeTestDoc ����
