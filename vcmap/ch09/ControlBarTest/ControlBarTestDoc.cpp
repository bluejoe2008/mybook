// ControlBarTestDoc.cpp : CControlBarTestDoc ���ʵ��
//

#include "stdafx.h"
#include "ControlBarTest.h"

#include "ControlBarTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlBarTestDoc

IMPLEMENT_DYNCREATE(CControlBarTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CControlBarTestDoc, CDocument)
END_MESSAGE_MAP()


// CControlBarTestDoc ����/����

CControlBarTestDoc::CControlBarTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CControlBarTestDoc::~CControlBarTestDoc()
{
}

BOOL CControlBarTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CControlBarTestDoc ���л�

void CControlBarTestDoc::Serialize(CArchive& ar)
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


// CControlBarTestDoc ���

#ifdef _DEBUG
void CControlBarTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControlBarTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CControlBarTestDoc ����
