// MessageRouteTestDoc.cpp : CMessageRouteTestDoc ���ʵ��
//

#include "stdafx.h"
#include "MessageRouteTest.h"

#include "MessageRouteTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageRouteTestDoc

IMPLEMENT_DYNCREATE(CMessageRouteTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMessageRouteTestDoc, CDocument)
	//ON_COMMAND(ID_FILE_OPEN, &CMessageRouteTestDoc::OnFileOpen)
END_MESSAGE_MAP()


// CMessageRouteTestDoc ����/����

CMessageRouteTestDoc::CMessageRouteTestDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMessageRouteTestDoc::~CMessageRouteTestDoc()
{
}

BOOL CMessageRouteTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMessageRouteTestDoc ���л�

void CMessageRouteTestDoc::Serialize(CArchive& ar)
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


// CMessageRouteTestDoc ���

#ifdef _DEBUG
void CMessageRouteTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMessageRouteTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMessageRouteTestDoc ����

void CMessageRouteTestDoc::OnFileOpen()
{
	::MessageBox(NULL, _T(__FUNCTION__), _T(""), MB_OK);
}
