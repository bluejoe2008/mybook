// OpenGLTestDoc.h : COpenGLTestDoc ��Ľӿ�
//


#pragma once


class COpenGLTestDoc : public CDocument
{
protected: // �������л�����
	COpenGLTestDoc();
	DECLARE_DYNCREATE(COpenGLTestDoc)

// ����
public:
	void RenderScene(void);
	enum GLDisplayListNames { ArmPart1, ArmPart2 };
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~COpenGLTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


