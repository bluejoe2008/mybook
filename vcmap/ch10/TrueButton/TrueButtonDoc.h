// TrueButtonDoc.h : CTrueButtonDoc ��Ľӿ�
//


#pragma once


class CTrueButtonDoc : public CDocument
{
protected: // �������л�����
	CTrueButtonDoc();
	DECLARE_DYNCREATE(CTrueButtonDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CTrueButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


