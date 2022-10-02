
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
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style |= WS_VSCROLL | WS_HSCROLL;

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), (HBRUSH)GetStockObject(GRAY_BRUSH), /*reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1)*/ nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//dc.TextOutW(50, 50, CString(_T("안녕하세요.")));
	// 클라이언트 영역의 좌표를 얻는다
	// 다양한 펜 종류를 연습한다

	for (int x = 0; x < 256; x++)
		for (int y = 0; y < 256; y++)
			dc.SetPixelV(x, y, RGB(x, y, 0));

	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}









void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다
	/*COLORREF color = dc.GetPixel(point.x, point.y);*/
	COLORREF color = dc.GetPixel(point.x, point.y);
	int R = 0, G = 0, B = 0;
	R = GetRValue(color);
	G = GetGValue(color);
	B = GetBValue(color);
	/*TCHAR msg[50]*/
	/*(_T("R:%d, G:%d, B:%d"), R, G, B);
	AfxMessageBox(msg);*/
	CString strTemp;
	/*strTemp.Format(_T("R = %d, G = %d, B = %d"), R, G, B);*/
	strTemp.Format(_T("%d, %d"), point.x, point.y);
	AfxMessageBox(strTemp);

	CWnd::OnLButtonDown(nFlags, point);
}
