// FakeButtonDoc.cpp : CFakeButtonDoc ���ʵ��
//

#include "stdafx.h"
#include "FakeButton.h"

#include "FakeButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFakeButtonDoc

IMPLEMENT_DYNCREATE(CFakeButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CFakeButtonDoc, CDocument)
END_MESSAGE_MAP()


// CFakeButtonDoc ����/����

CFakeButtonDoc::CFakeButtonDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CFakeButtonDoc::~CFakeButtonDoc()
{
}

BOOL CFakeButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CFakeButtonDoc ���л�

void CFakeButtonDoc::Serialize(CArchive& ar)
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


// CFakeButtonDoc ���

#ifdef _DEBUG
void CFakeButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFakeButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFakeButtonDoc ����
