// MyCircleDoc.cpp : CMyCircleDoc ���ʵ��
//

#include "stdafx.h"
#include "MyCircle.h"

#include "MyCircleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyCircleDoc

IMPLEMENT_DYNCREATE(CMyCircleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCircleDoc, CDocument)
END_MESSAGE_MAP()


// CMyCircleDoc ����/����

CMyCircleDoc::CMyCircleDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMyCircleDoc::~CMyCircleDoc()
{
}

BOOL CMyCircleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMyCircleDoc ���л�

void CMyCircleDoc::Serialize(CArchive& ar)
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


// CMyCircleDoc ���

#ifdef _DEBUG
void CMyCircleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCircleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyCircleDoc ����
