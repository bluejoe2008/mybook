// MyStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WM_PAINT.h"
#include "MyStatic.h"


// CMyStatic

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{

}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyStatic ��Ϣ�������



void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//ʲô���������������һ�����ο�
	CRect rc;
	GetClientRect(&rc);
	dc.DrawFrameControl(&rc, DFC_CAPTION, DFCS_CAPTIONHELP);
}
