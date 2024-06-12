
// MoveStrView.h: CMoveStrView 클래스의 인터페이스
//

#pragma once


class CMoveStrView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMoveStrView() noexcept;
	DECLARE_DYNCREATE(CMoveStrView)

// 특성입니다.
public:
	CMoveStrDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMoveStrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString strOutput;
	CPoint ptLocation;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CPoint ptClientSize;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool fDrag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MoveStrView.cpp의 디버그 버전
inline CMoveStrDoc* CMoveStrView::GetDocument() const
   { return reinterpret_cast<CMoveStrDoc*>(m_pDocument); }
#endif

