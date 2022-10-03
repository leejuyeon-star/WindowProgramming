
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_CLOSE()
//ON_WM_CLOSE()
//ON_WM_DESTROY()
//ON_WM_CLOSE()
//ON_WM_LBUTTONDOWN()
//ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
//ON_WM_ERASEBKGND()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), /*(HBRUSH)GetStockObject(GRAY_BRUSH)*/ reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	CPaintDC dc(this);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush3(&bitmap);
	dc.SelectObject(&brush3);
	brush3.CreatePatternBrush(&bitmap);
	/*dc.RoundRect(450, 50, 6000, 2000, 50, 50);*/



	return TRUE;
}

void CChildView::OnPaint() 
{



	/*CPaintDC dc(this); // 그릴 수 있는 디바이스 컨텍스트
	dc.TextOut(100, 50, CString(" OPAQUE 모드 [1] "));
	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(100, 100, CString(" TRANSPARENT 모드 "));
	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(0, 255, 0)); // 
	dc.TextOut(100, 150, CString(" OPAQUE 모드 [2] "));*/
	
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPaintDC dc(this); // 그릴 수 있는 디바이스 컨텍스트
	dc.SetBkMode(OPAQUE); // 배경모드 불투명
	Invalidate();		//화면 갱신
	//dc.SetBkColor(RGB(10, 250, 0)); // 배경색 설정
	

	CWnd::OnLButtonDown(nFlags, point);
}



void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CPaintDC dc(this); // 그릴 수 있는 디바이스 컨텍스트
	dc.SetBkMode(TRANSPARENT); // 배경모드 투명
	Invalidate();		//화면 갱신
	

	CWnd::OnRButtonDown(nFlags, point);
}
