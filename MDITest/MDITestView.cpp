
// MDITestView.cpp : CMDITestView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MDITest.h"
#endif

#include "MDITestDoc.h"
#include "MDITestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDITestView

IMPLEMENT_DYNCREATE(CMDITestView, CView)

BEGIN_MESSAGE_MAP(CMDITestView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMDITestView ����/�Ҹ�

CMDITestView::CMDITestView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMDITestView::~CMDITestView()
{
}

BOOL CMDITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMDITestView �׸���

void CMDITestView::OnDraw(CDC* pDC)
{
	CMDITestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, _T("�ü�"));

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->m_str.GetData(),
		pDoc->m_str.GetSize(), &rect, DT_LEFT);
}


// CMDITestView �μ�

BOOL CMDITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMDITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMDITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMDITestView ����

#ifdef _DEBUG
void CMDITestView::AssertValid() const
{
	CView::AssertValid();
}

void CMDITestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDITestDoc* CMDITestView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITestDoc)));
	return (CMDITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDITestView �޽��� ó����


void CMDITestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMDITestDoc* pDoc = GetDocument();

	if (nChar == _T('\b')){
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
	}
	else{
		pDoc->m_str.Add(nChar);

		pDoc->UpdateAllViews(NULL);
	}
}
