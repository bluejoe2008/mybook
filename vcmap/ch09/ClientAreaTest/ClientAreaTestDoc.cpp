// ClientAreaTestDoc.cpp : CClientAreaTestDoc ���ʵ��
//

#include "stdafx.h"
#include "ClientAreaTest.h"

#include "ClientAreaTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientAreaTestDoc

IMPLEMENT_DYNCREATE(CClientAreaTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CClientAreaTestDoc, CDocument)
END_MESSAGE_MAP()


// CClientAreaTestDoc ����/����

CClientAreaTestDoc::CClientAreaTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CClientAreaTestDoc::~CClientAreaTestDoc()
{
}

BOOL CClientAreaTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CClientAreaTestDoc ���л�

void CClientAreaTestDoc::Serialize(CArchive& ar)
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


// CClientAreaTestDoc ���

#ifdef _DEBUG
void CClientAreaTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClientAreaTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CClientAreaTestDoc ����
