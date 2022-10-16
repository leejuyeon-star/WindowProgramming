// MyServer.cpp: 구현 파일
//

#include "pch.h"
#include "ValueServer.h"
#include "MyServer.h"


// MyServer

MyServer::MyServer()
{
}

MyServer::~MyServer()
{
}


// MyServer 멤버 함수

//클라이언트가 접속 시도시 호출됨
void MyServer::OnAccept(int nErrorCode)
{
	//해당 클라이언트와만 연결할 소켓 생성
	Accept(m_user);

	CSocket::OnAccept(nErrorCode);
}
