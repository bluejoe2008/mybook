// SdiSpiltTestDoc.h : CSdiSpiltTestDoc ��Ľӿ�
//


#pragma once


class CSdiSpiltTestDoc : public CDocument
{
protected: // �������л�����
	CSdiSpiltTestDoc();
	DECLARE_DYNCREATE(CSdiSpiltTestDoc)

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
	virtual ~CSdiSpiltTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


