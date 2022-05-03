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


void MyUser::OnReceive(int nErrorCode)
{
	char str[1024];
	Receive(str, 1024);
	wchar_t unicode[1024];
	int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	MultiByteToWideChar(CP_UTF8, 0, str, -1, unicode, len);
	
	AfxGetMainWnd()->SetDlgItemText(IDC_SEND_EDIT, unicode);
	Send(unicode, len);

	//TCHAR szTemp[1024];
	//memset(szTemp, 0x00, sizeof(szTemp));
	////TCHAR에 CString받을 수 있음
	//Receive(szTemp, 1024);
	//AfxGetMainWnd()->SetDlgItemText(IDC_SEND_EDIT, szTemp);
	//Send(szTemp, 1024);
	CSocket::OnReceive(nErrorCode);
}
