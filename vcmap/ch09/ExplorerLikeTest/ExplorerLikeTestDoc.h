// ExplorerLikeTestDoc.h : CExplorerLikeTestDoc ��Ľӿ�
//


#pragma once


class CExplorerLikeTestDoc : public CDocument
{
protected: // �������л�����
	CExplorerLikeTestDoc();
	DECLARE_DYNCREATE(CExplorerLikeTestDoc)

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
	virtual ~CExplorerLikeTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


