
// MDITestView.h : CMDITestView Ŭ������ �������̽�
//

#pragma once
#include <afxtempl.h>

class CMDITestView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMDITestView();
	DECLARE_DYNCREATE(CMDITestView)

// Ư���Դϴ�.
public:
	CMDITestDoc* GetDocument() const;
	
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMDITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MDITestView.cpp�� ����� ����
inline CMDITestDoc* CMDITestView::GetDocument() const
   { return reinterpret_cast<CMDITestDoc*>(m_pDocument); }
#endif

