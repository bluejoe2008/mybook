// MfcTestDoc.h : CMfcTestDoc ��Ľӿ�
//


#pragma once


class CMfcTestDoc : public CDocument
{
protected: // �������л�����
	CMfcTestDoc();
	DECLARE_DYNCREATE(CMfcTestDoc)

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
	virtual ~CMfcTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


