// GdiplusTestDoc.h : CGdiplusTestDoc ��Ľӿ�
//


#pragma once


class CGdiplusTestDoc : public CDocument
{
protected: // �������л�����
	CGdiplusTestDoc();
	DECLARE_DYNCREATE(CGdiplusTestDoc)

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
	virtual ~CGdiplusTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


