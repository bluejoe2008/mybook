// MessageRouteTestDoc.h : CMessageRouteTestDoc ��Ľӿ�
//


#pragma once


class CMessageRouteTestDoc : public CDocument
{
protected: // �������л�����
	CMessageRouteTestDoc();
	DECLARE_DYNCREATE(CMessageRouteTestDoc)

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
	virtual ~CMessageRouteTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};


