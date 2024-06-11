
// HelloMFCView.cpp: CHelloMFCView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HelloMFC.h"
#endif

#include "HelloMFCDoc.h"
#include "HelloMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloMFCView

IMPLEMENT_DYNCREATE(CHelloMFCView, CView)

BEGIN_MESSAGE_MAP(CHelloMFCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CHelloMFCView 생성/소멸

CHelloMFCView::CHelloMFCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHelloMFCView::~CHelloMFCView()
{
}

BOOL CHelloMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
		// TODO: CREATESTRUCT cs를 수정하여 여기에서
		//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHelloMFCView 그리기

void CHelloMFCView::OnDraw(CDC* pDC)
{
	CHelloMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(10, 10, m_strWindowSize);	//(10,10)에 사이즈 출력하기
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CHelloMFCView 인쇄

BOOL CHelloMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHelloMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHelloMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CHelloMFCView 진단

#ifdef _DEBUG
void CHelloMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloMFCDoc* CHelloMFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloMFCDoc)));
	return (CHelloMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloMFCView 메시지 처리기


void CHelloMFCView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// 윈도우 크기가 변경될 때 윈도우 크기를 나타내는 문자열 생성
	m_strWindowSize.Format(_T("윈도우 크기는 넓이 %d, 높이 %d입니다."), cx, cy);
	//화면 갱신
	Invalidate();
}


void CHelloMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = true;
	m_strOutput = _T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CHelloMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE) {
		m_strOutput = _T("마우스를 드래그하고 있습니다.");
	}
	else {
		m_strOutput = _T("마우스를 이동중입니다.");
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CHelloMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}
