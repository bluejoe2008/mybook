// ChildView.h : CChildView ��Ľӿ�
//
#pragma once

#include <Mmsystem.h>
#include <d3dx9.h>
#include <string>

#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")

// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

// ����
public:
	IDirect3DDevice9* m_Device; 
	ID3DXMesh* m_Teapot;
	float m_Angle;

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int InitDX(void);
};

