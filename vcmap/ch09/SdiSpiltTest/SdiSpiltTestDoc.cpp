// SdiSpiltTestDoc.cpp : CSdiSpiltTestDoc ���ʵ��
//

#include "stdafx.h"
#include "SdiSpiltTest.h"

#include "SdiSpiltTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSpiltTestDoc

IMPLEMENT_DYNCREATE(CSdiSpiltTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiSpiltTestDoc, CDocument)
END_MESSAGE_MAP()


// CSdiSpiltTestDoc ����/����

CSdiSpiltTestDoc::CSdiSpiltTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CSdiSpiltTestDoc::~CSdiSpiltTestDoc()
{
}

BOOL CSdiSpiltTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSdiSpiltTestDoc ���л�

void CSdiSpiltTestDoc::Serialize(CArchive& ar)
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


// CSdiSpiltTestDoc ���

#ifdef _DEBUG
void CSdiSpiltTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiSpiltTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiSpiltTestDoc ����
