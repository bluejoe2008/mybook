// ClientAreaTestDoc.h : CClientAreaTestDoc ��Ľӿ�
//


#pragma once


class CClientAreaTestDoc : public CDocument
{
protected: // �������л�����
	CClientAreaTestDoc();
	DECLARE_DYNCREATE(CClientAreaTestDoc)

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
	virtual ~CClientAreaTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


