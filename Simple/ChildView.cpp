
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
	m_xPos = m_yPos = 60;
	m_bFill = FALSE;
	m_bDrawMode = false;

	circleArr.SetSize(20);
	circleCount = 0;

	//CUIntArray array;
	//array.SetSize(10);
	//array[1];

	//array.InsertAt(인덱스, 값);
	//array.RemoveAt(인덱스);
	//array.AddTail(값);

	//CArray<Point3D, Point3D&> array;		



	//CList도 있다. (97p)(포인터로 연결되어 앞으로넣기, 뒤로넣기 기능 있음, 리스트 크기지정안해도됨)
	
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_WM_SETCURSOR()
ON_WM_SIZE()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);
	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	if(m_bDrawMode)
		dc.Ellipse(m_x1-20, m_y1-20, m_x1 + 20, m_y1 + 20);

	if (circleCount)
	{
		for (int i = 0; i < circleCount; i++)
		{
			dc.Ellipse(circleArr[i].x - 20, circleArr[i].y - 20, circleArr[i].x + 20, circleArr[i].y + 20);
		}
	}

	

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDrawMode = true;
	m_x1 = point.x;
	m_y1 = point.y;
	
	circleArr.InsertAt(circleCount, point);
	circleCount++;
	Invalidate();

	CWnd::OnLButtonDown(nFlags, point);
}



void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{


	
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{

}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDrawMode = false;

	CWnd::OnLButtonUp(nFlags, point);
}


BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{

	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}







void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	m_xMax = cx;
	m_yMax = cy;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar) {
	case VK_LEFT:
		m_xPos -= 20; 
		break;
	case VK_RIGHT: 
		m_xPos += 20; 
		break;
	case VK_UP: 
		m_yPos -= 20; 
		break;
	case VK_DOWN: 
		m_yPos += 20; 
		break;
	case VK_SPACE: 
		m_bFill = !m_bFill;
	}
	// 20 <= m_xPos <= m_xMax-20
	m_xPos = min(max(20, m_xPos), m_xMax - 20); 
	// 20 <= m_yPos <= m_yMax-20
	m_yPos = min(max(20, m_yPos), m_yMax - 20); 
	Invalidate();

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
