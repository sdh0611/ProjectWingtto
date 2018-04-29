//Note(18.04.14) Singleton의 구현에 대해 다시 생각해봐야할듯.
//현재 Singleton을 써도 생성객체가 하나라는 보장을 못함..
// ->  Singleton Class 상속 객체의 생성자를 private으로 돌려야하는데
//		이걸 하니까 또 접근못한다고 하니까 답답하네
// ->	Friend선언을 해줘야하는건가	-> 일단 매크로로 friend선언추가(18.04.14)

#include "pch.h"
#include "./Include/MyWindow.h"


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpszCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hPreInstance);
	UNREFERENCED_PARAMETER(lpszCmdLine);


	if (!MyWindow::GetInstance()->Init(hInstance)) {
		MessageBox(NULL, TEXT("WNDCLASS Init Failed"), TEXT("Error"), MB_ICONERROR | MB_OK);
		return 0;
	}

	UINT retValue =  MyWindow::GetInstance()->MessageLoop();
	MessageBox(NULL, TEXT("Main 종료"), TEXT("Info"), MB_ICONINFORMATION);

	MyWindow::Destroy();

	return retValue;

}