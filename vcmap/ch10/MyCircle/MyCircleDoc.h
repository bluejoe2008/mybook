// MyCircleDoc.h : CMyCircleDoc ��Ľӿ�
//


#pragma once


class CMyCircleDoc : public CDocument
{
protected: // �������л�����
	CMyCircleDoc();
	DECLARE_DYNCREATE(CMyCircleDoc)

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
	virtual ~CMyCircleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


