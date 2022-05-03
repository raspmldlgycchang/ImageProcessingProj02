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


void MyClient::OnReceive(int nErrorCode)
{

	char str[1024];
	Receive(str, 1024);

	CSocket::OnReceive(nErrorCode);
}
