// PERSON.h : CPersonRecordset ���ʵ��
#include "stdafx.h"
#include "PERSON.h"



// CPersonRecordset ʵ��

// ���������� 2008��10��5��, 10:39

IMPLEMENT_DYNAMIC(CPersonRecordset, CRecordset)

CPersonRecordset::CPersonRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_NAME = L"";
	m_AGE = 0;
	m_GENDER = L"";
	m_WORDS = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

CString CPersonRecordset::GetDefaultConnect()
{
	return _T("DSN=hotel;DBQ=E:\\study\\keys\\hotel.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CPersonRecordset::GetDefaultSQL()
{
	return _T("[PERSON]");
}

void CPersonRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Long(pFX, _T("[AGE]"), m_AGE);
	RFX_Text(pFX, _T("[GENDER]"), m_GENDER);
	RFX_Text(pFX, _T("[WORDS]"), m_WORDS);

}
/////////////////////////////////////////////////////////////////////////////
// CPersonRecordset ���

#ifdef _DEBUG
void CPersonRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPersonRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


