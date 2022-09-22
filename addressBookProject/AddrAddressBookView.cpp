
// AddrAddressBookView.cpp: CAddrAddressBookView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "AddrAddressBook.h"
#endif

#include "AddrAddressBookDoc.h"
#include "AddrAddressBookView.h"
#include "CDlgNewAddr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAddrAddressBookView

IMPLEMENT_DYNCREATE(CAddrAddressBookView, CView)

BEGIN_MESSAGE_MAP(CAddrAddressBookView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_New_Addr, &CAddrAddressBookView::OnNewAddr)
END_MESSAGE_MAP()

// CAddrAddressBookView 생성/소멸

CAddrAddressBookView::CAddrAddressBookView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAddrAddressBookView::~CAddrAddressBookView()
{
	GetDocument()->ReleaseList();
}

BOOL CAddrAddressBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CAddrAddressBookView 그리기

void CAddrAddressBookView::OnDraw(CDC* /*pDC*/)
{
	CAddrAddressBookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CAddrAddressBookView 인쇄

BOOL CAddrAddressBookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAddrAddressBookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAddrAddressBookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CAddrAddressBookView 진단

#ifdef _DEBUG
void CAddrAddressBookView::AssertValid() const
{
	CView::AssertValid();
}

void CAddrAddressBookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAddrAddressBookDoc* CAddrAddressBookView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAddrAddressBookDoc)));
	return (CAddrAddressBookDoc*)m_pDocument;
}
#endif //_DEBUG


// CAddrAddressBookView 메시지 처리기


int CAddrAddressBookView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	AddCount = 0;

	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	//리스트 박스 윈도우 생성
	m_wndList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL,
		CRect(0, 0, 300, 400), this, 1234);

	return 0;
}


void CAddrAddressBookView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_wndList.MoveWindow(0, 0, 300, cy);
}


void CAddrAddressBookView::OnNewAddr()		//주소 추가 버튼 이벤트 처리
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
	// 대화상자 띄움
	CDlgNewAddr dlg;
	//dlg.Create(ID_DIALOG_NEW_ADDR, this);
	if (dlg.DoModal() == IDOK)
	{
		AddCount++;
		/*
		CString strName;
		CString strPhone;
		strName.Format(_T("%d 이름 : %s"), AddCount, dlg.m_strName);
		strPhone.Format(_T("%d 전화번호 : %s"), AddCount, dlg.m_strPhone);
		m_wndList.AddString(strName);
		m_wndList.AddString(strPhone);
		*/

		GetDocument()->NewAddr(dlg.m_strName, dlg.m_strPhone);

	}
	

}
