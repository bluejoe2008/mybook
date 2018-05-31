// HitCounter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MessageReflectionTest.h"
#include "HitCounter.h"


// CHitCounter

IMPLEMENT_DYNAMIC(CHitCounter, CStatic)

CHitCounter::CHitCounter()
{
	m_hits = 0;
}

CHitCounter::~CHitCounter()
{
}


BEGIN_MESSAGE_MAP(CHitCounter, CStatic)
	ON_CONTROL_REFLECT(STN_CLICKED, &CHitCounter::OnStnClicked)
END_MESSAGE_MAP()



// CHitCounter ��Ϣ�������



void CHitCounter::OnStnClicked()
{
	m_hits++;
	CString s;
	s.Format(_T("�������: %d"), m_hits);
	
	this->SetWindowText(s);
}
