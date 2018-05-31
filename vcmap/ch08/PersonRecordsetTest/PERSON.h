// PERSON.h : CPersonRecordset ������

#pragma once

// ���������� 2008��10��5��, 10:39

class CPersonRecordset : public CRecordset
{
public:
	CPersonRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPersonRecordset)

	long	m_ID;
	CStringW	m_NAME;
	long	m_AGE;
	CStringW	m_GENDER;
	CStringW	m_WORDS;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


