// TrueButtonDoc.cpp : CTrueButtonDoc ���ʵ��
//

#include "stdafx.h"
#include "TrueButton.h"

#include "TrueButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrueButtonDoc

IMPLEMENT_DYNCREATE(CTrueButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrueButtonDoc, CDocument)
END_MESSAGE_MAP()


// CTrueButtonDoc ����/����

CTrueButtonDoc::CTrueButtonDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CTrueButtonDoc::~CTrueButtonDoc()
{
}

BOOL CTrueButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CTrueButtonDoc ���л�

void CTrueButtonDoc::Serialize(CArchive& ar)
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


// CTrueButtonDoc ���

#ifdef _DEBUG
void CTrueButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrueButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTrueButtonDoc ����
