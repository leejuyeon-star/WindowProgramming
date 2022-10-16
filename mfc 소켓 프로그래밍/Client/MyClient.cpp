// MyClient.cpp: 구현 파일
//

#include "pch.h"
#include "ValueClient.h"
#include "MyClient.h"


// MyClient

MyClient::MyClient()
{
}

MyClient::~MyClient()
{
}




// MyClient 멤버 함수

//서버로부터 수신 받으면 호출됨
void MyClient::OnReceive(int nErrorCode)
{
	//받은 값을 int형(4byte) 크기로 받아 value에 받는다.
	int value;
	Receive(&value, sizeof(int));

	//값 대화상자에 출력
	AfxGetMainWnd()->SetDlgItemInt(IDC_VALUE_EDIT, value);


	CSocket::OnReceive(nErrorCode);
}
