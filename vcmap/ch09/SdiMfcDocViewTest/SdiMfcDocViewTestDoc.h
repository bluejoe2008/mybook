// SdiMfcDocViewTestDoc.h : CSdiMfcDocViewTestDoc ��Ľӿ�
//


#pragma once


class CSdiMfcDocViewTestDoc : public CDocument
{
protected: // �������л�����
	CSdiMfcDocViewTestDoc();
	DECLARE_DYNCREATE(CSdiMfcDocViewTestDoc)

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
	virtual ~CSdiMfcDocViewTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


