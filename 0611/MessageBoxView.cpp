
// MessageBoxView.cpp: CMessageBoxView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MessageBox.h"
#endif

#include "MessageBoxDoc.h"
#include "MessageBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageBoxView

IMPLEMENT_DYNCREATE(CMessageBoxView, CView)

BEGIN_MESSAGE_MAP(CMessageBoxView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMessageBoxView 생성/소멸

CMessageBoxView::CMessageBoxView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMessageBoxView::~CMessageBoxView()
{
}

BOOL CMessageBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMessageBoxView 그리기

void CMessageBoxView::OnDraw(CDC* /*pDC*/)
{
	CMessageBoxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMessageBoxView 인쇄

BOOL CMessageBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMessageBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMessageBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMessageBoxView 진단

#ifdef _DEBUG
void CMessageBoxView::AssertValid() const
{
	CView::AssertValid();
}

void CMessageBoxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessageBoxDoc* CMessageBoxView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessageBoxDoc)));
	return (CMessageBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessageBoxView 메시지 처리기


int CMessageBoxView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	// 윈도우가 생성될 때 메시지 박스 출력
	AfxMessageBox(_T("윈도우가 생성되었습니다."), MB_OKCANCEL | MB_ICONINFORMATION);

	return 0;
}


void CMessageBoxView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 윈도우가 종료될 때 메시지 박스 출력
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_OK | MB_ICONWARNING);
}


void CMessageBoxView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 마우스 왼쪽 버튼을 더블 클릭할 때 메시지 박스 출력
	AfxMessageBox(_T("왼쪽 마우스를 더블클릭했습니까?"), MB_YESNO | MB_ICONQUESTION);

	CView::OnLButtonDblClk(nFlags, point);
}
