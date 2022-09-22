
// AddrAddressBookView.h: CAddrAddressBookView 클래스의 인터페이스
//

#pragma once


class CAddrAddressBookView : public CView
{
protected: // serialization에서만 만들어집니다.
	CAddrAddressBookView() noexcept;
	DECLARE_DYNCREATE(CAddrAddressBookView)

// 특성입니다.
public:
	CAddrAddressBookDoc* GetDocument() const;

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
	virtual ~CAddrAddressBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
private:
	CListBox m_wndList;
	int AddCount;	//추가버튼 클릭한 횟수(구조화해야함)(프로그램 종료 전에 값 저장해서 로드하는 방법?)
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnNewAddr();
};

#ifndef _DEBUG  // AddrAddressBookView.cpp의 디버그 버전
inline CAddrAddressBookDoc* CAddrAddressBookView::GetDocument() const
   { return reinterpret_cast<CAddrAddressBookDoc*>(m_pDocument); }
#endif

