
// MoveStrView.cpp: CMoveStrView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MoveStr.h"
#endif

#include "MoveStrDoc.h"
#include "MoveStrView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMoveStrView

IMPLEMENT_DYNCREATE(CMoveStrView, CView)

BEGIN_MESSAGE_MAP(CMoveStrView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMoveStrView 생성/소멸

CMoveStrView::CMoveStrView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	strOutput = _T("");
	ptLocation = (0, 0);
	fDrag = false;
}

CMoveStrView::~CMoveStrView()
{
}

BOOL CMoveStrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMoveStrView 그리기

void CMoveStrView::OnDraw(CDC* pDC)
{
	CMoveStrDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(ptLocation.x, ptLocation.y, strOutput);
}


// CMoveStrView 인쇄

BOOL CMoveStrView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMoveStrView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMoveStrView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMoveStrView 진단

#ifdef _DEBUG
void CMoveStrView::AssertValid() const
{
	CView::AssertValid();
}

void CMoveStrView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMoveStrDoc* CMoveStrView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMoveStrDoc)));
	return (CMoveStrDoc*)m_pDocument;
}
#endif //_DEBUG


// CMoveStrView 메시지 처리기


void CMoveStrView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = strOutput.GetLength();	//입력된 데이터의 길이를 얻는다.

	if (nChar == VK_BACK)
		strOutput.Delete(nCharIndex - 1, 1);	//백스페이스가 눌러지면 한번에 하나씩 지움
	else
		strOutput += (WCHAR)nChar;				//키보드로 입력된 문자를 문자열에 추가

	Invalidate();								//화면 갱신 OnDraw()호출
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMoveStrView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:
		ptLocation.x--;
		break;
	case VK_RIGHT:
		ptLocation.x++;
		break;
	case VK_UP:
		ptLocation.y--;
		break;
	case VK_DOWN:
		ptLocation.y++;
		break;
	case VK_PRIOR:				//Pg up
		ptLocation.y -= 50;
		break;
	case VK_NEXT:				//Pg dn
		ptLocation.y += 50;
		break;
	case VK_HOME:				//Home
		ptLocation = CPoint(0, 0);
		break;
	}
	if (ptLocation.x < 0) {
		ptLocation.x = 0;
		AfxMessageBox(_T("왼쪽으로 더 이상 이동할 수 없습니다."));
	}
	if (ptLocation.y < 0) {
		ptLocation.y = 0;
		AfxMessageBox(_T("위쪽으로 더 이상 이동할 수 없습니다."));
	}
	if (ptLocation.x > ptClientSize.x) {
		ptLocation.x = ptClientSize.x;
		AfxMessageBox(_T("오른쪽으로 더 이상 이동할 수 없습니다."));
	}
	if (ptLocation.y > ptClientSize.y) {
		ptLocation.y = ptClientSize.y;
		AfxMessageBox(_T("아래쪽으로 더 이상 이동할 수 없습니다."));
	}
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMoveStrView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	ptClientSize.x = cx;
	ptClientSize.y = cy;

	Invalidate();
}

void CMoveStrView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		// 문자열 위치에서 오차 30픽셀정도 이내이면 드래그 가능하게 함
	if (point.x >= ptLocation.x - 30 && point.x <= ptLocation.x + 30 &&
		point.y >= ptLocation.y - 30 && point.y <= ptLocation.y + 30)
		fDrag = true;
	ptLocation = point;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CMoveStrView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (fDrag) {
		ptLocation = point;
	}
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CMoveStrView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (fDrag == true) {
		fDrag = false;
		ptLocation = point;
	}
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}

void CMoveStrView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (strOutput.IsEmpty() == false) {
		if (AfxMessageBox(_T("문자열을 지우시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
			strOutput.Empty();
	}
	else {
		if (AfxMessageBox(_T("문자열을 입력하십시오.")));
	}
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}