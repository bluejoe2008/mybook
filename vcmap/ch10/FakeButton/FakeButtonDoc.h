// FakeButtonDoc.h : CFakeButtonDoc ��Ľӿ�
//


#pragma once


class CFakeButtonDoc : public CDocument
{
protected: // �������л�����
	CFakeButtonDoc();
	DECLARE_DYNCREATE(CFakeButtonDoc)

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
	virtual ~CFakeButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


