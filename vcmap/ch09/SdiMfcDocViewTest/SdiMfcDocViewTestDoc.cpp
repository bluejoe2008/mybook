// SdiMfcDocViewTestDoc.cpp : CSdiMfcDocViewTestDoc ���ʵ��
//

#include "stdafx.h"
#include "SdiMfcDocViewTest.h"

#include "SdiMfcDocViewTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiMfcDocViewTestDoc

IMPLEMENT_DYNCREATE(CSdiMfcDocViewTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiMfcDocViewTestDoc, CDocument)
END_MESSAGE_MAP()


// CSdiMfcDocViewTestDoc ����/����

CSdiMfcDocViewTestDoc::CSdiMfcDocViewTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSdiMfcDocViewTestDoc::~CSdiMfcDocViewTestDoc()
{
}

BOOL CSdiMfcDocViewTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSdiMfcDocViewTestDoc ���л�

void CSdiMfcDocViewTestDoc::Serialize(CArchive& ar)
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


// CSdiMfcDocViewTestDoc ���

#ifdef _DEBUG
void CSdiMfcDocViewTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiMfcDocViewTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiMfcDocViewTestDoc ����
