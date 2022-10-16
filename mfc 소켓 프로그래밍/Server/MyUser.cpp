// MyUser.cpp: 구현 파일
//

#include "pch.h"
#include "ValueServer.h"
#include "MyUser.h"


// MyUser

MyUser::MyUser()
{
}

MyUser::~MyUser()
{
}


// MyUser 멤버 함수


//클라이언트에게 수신시 호출
void MyUser::OnReceive(int nErrorCode)
{
	//받은 값을 int형(4byte) 크기로 받아 value에 받는다.
	int value;
	Receive(&value, sizeof(int));

	//값 대화상자에 출력
	AfxGetMainWnd()->SetDlgItemInt(IDC_VALUE_EDIT, value);
	CSocket::OnReceive(nErrorCode);

	//클라이언트에게 확인 답장
	value = 1;
	Send(&value, sizeof(int));
}


//연결된 소켓이 닫히면(클라이언트가 종료하면) 호출됨
void MyUser::OnClose(int nErrorCode)
{
	ShutDown(2);	//데이터 전송/수신하고 있는데 접속 끊는 함수 
	Close();
	CSocket::OnClose(nErrorCode);
}
