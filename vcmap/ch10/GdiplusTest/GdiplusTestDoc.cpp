// GdiplusTestDoc.cpp : CGdiplusTestDoc ���ʵ��
//

#include "stdafx.h"
#include "GdiplusTest.h"

#include "GdiplusTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTestDoc

IMPLEMENT_DYNCREATE(CGdiplusTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusTestDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusTestDoc ����/����

CGdiplusTestDoc::CGdiplusTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CGdiplusTestDoc::~CGdiplusTestDoc()
{
}

BOOL CGdiplusTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGdiplusTestDoc ���л�

void CGdiplusTestDoc::Serialize(CArchive& ar)
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


// CGdiplusTestDoc ���

#ifdef _DEBUG
void CGdiplusTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusTestDoc ����
