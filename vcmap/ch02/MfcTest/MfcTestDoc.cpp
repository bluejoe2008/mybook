// MfcTestDoc.cpp : CMfcTestDoc ���ʵ��
//

#include "stdafx.h"
#include "MfcTest.h"

#include "MfcTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcTestDoc

IMPLEMENT_DYNCREATE(CMfcTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcTestDoc, CDocument)
END_MESSAGE_MAP()


// CMfcTestDoc ����/����

CMfcTestDoc::CMfcTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMfcTestDoc::~CMfcTestDoc()
{
}

BOOL CMfcTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMfcTestDoc ���л�

void CMfcTestDoc::Serialize(CArchive& ar)
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


// CMfcTestDoc ���

#ifdef _DEBUG
void CMfcTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMfcTestDoc ����
