// ControlBarTestDoc.h : CControlBarTestDoc ��Ľӿ�
//


#pragma once


class CControlBarTestDoc : public CDocument
{
protected: // �������л�����
	CControlBarTestDoc();
	DECLARE_DYNCREATE(CControlBarTestDoc)

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
	virtual ~CControlBarTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


