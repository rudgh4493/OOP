﻿
// FileDialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FileDialog.h"
#include "FileDialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(IDC_CHECK1, &CAboutDlg::OnClickedCheck1)
	ON_COMMAND(IDC_CHECK2, &CAboutDlg::OnClickedCheck2)
END_MESSAGE_MAP()


// CFileDialogDlg 대화 상자



CFileDialogDlg::CFileDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEDIALOG_DIALOG, pParent)
	, m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//변수 초기화
	m_bChecked[0] = m_bChecked[1] = false;
}

void CFileDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strEdit);
	DDX_Control(pDX, IDC_COMBO_AUTO, m_cbListItem);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_listBox);
}

BEGIN_MESSAGE_MAP(CFileDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK2, &CFileDialogDlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON3, &CFileDialogDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CFileDialogDlg::OnBnClickedButton4)
	ON_COMMAND(IDC_RADIO1, &CFileDialogDlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CFileDialogDlg::OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CFileDialogDlg::OnClickedButtonDelete)
END_MESSAGE_MAP()


// CFileDialogDlg 메시지 처리기

BOOL CFileDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창z이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFileDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileDialogDlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strSelText;
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR) {
		m_listBox.GetText(index, strSelText);
		m_listBox.AddString(strSelText);
		UpdateComboBox();
	}
	else {
		AfxMessageBox(_T("콤보 박스에서 삽입할 아이템을 선택하세요."));
	}

}


void CFileDialogDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileDialogDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFileDialogDlg::UpdateComboBox()
{
	// TODO: 여기에 구현 코드 추가.
	int nCnt = m_listBox.GetCount();	//리스트박스의 현재 아이템의 수 반환
	m_cbListItem.ResetContent();

	for (int i = 0; i < nCnt; i++) {
		CString strItem;
		strItem.Format(_T("리스트 항목 : %d"), i + 1);
		m_cbListItem.AddString(strItem);
	}
}

void CFileDialogDlg::OnRadio1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_listBox.AddString(_T("1번 라디오 버튼 선택"));
	UpdateComboBox();
}


void CFileDialogDlg::OnRadio2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_listBox.AddString(_T("1번 라디오 버튼 선택"));
	UpdateComboBox();
}


void CAboutDlg::OnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[0] == false) {
		m_bChecked[0] = true;
		m_listBox.AddString(_T("1번 체크박스 상태 TRUE"));
	}
	else {
		m_bChecked[0] = false;
		m_listBox.AddString(_T("1번 체크박스 상태 FALSE"));
	}
	UpdateComboBox();
}


void CAboutDlg::OnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bChecked[1] == false) {
		m_bChecked[1] = true;
		m_listBox.AddString(_T("2번 체크박스 상태 TRUE"));
	}
	else {
		m_bChecked[1] = false;
		m_listBox.AddString(_T("2번 체크박스 상태 FALSE"));
	}
	UpdateComboBox();
}


void CFileDialogDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR) {
		m_listBox.DeleteString(index);
		UpdateComboBox();
	}
	else {
		AfxMessageBox(_T("콤보 박스에서 삭제할 아이템을 선택하세요."));
	}
}
