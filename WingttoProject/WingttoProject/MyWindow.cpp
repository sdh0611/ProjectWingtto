#include "Pch.h"
#include "MyWIndow.h"

MyWindow::MyWindow(HINSTANCE nHInstance, HWND nHWnd)
: hInstance(nHInstance), hWnd(nHWnd){


}

MyWindow::~MyWindow() {

}

//bool MyWindow::InitWndClass(int cbClsExtra, int cbWndExtra, std::basic_string<TCHAR> className, 
//	std::basic_string<TCHAR> menuName, UINT classStyle) {
//
//	wndClass.hInstance = hInstance;
//
//	wndClass.cbClsExtra = 0;
//	wndClass.cbWndExtra = 0;
//	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
//	wndClass.lpfnWndProc = WndProc;
//	wndClass.lpszClassName = className.c_str();
//	wndClass.lpszMenuName = NULL;
//	wndClass.style = classStyle;
//
//	if (RegisterClass(&wndClass)) 
//		return true;
//	
//	return false;
//}

bool MyWindow::InitWndClass() {

	wndClass.hInstance = hInstance;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = TEXT("test");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	if (RegisterClass(&wndClass))
		return true;

	return false;
}

bool MyWindow::MakeWindow(int dwStyle, int nx, int ny, int nWidth, int nHeight, HWND nhWndParent, HMENU nhmenu) {

	this->hWnd = CreateWindow(wndClass.lpszClassName, TEXT("MyWindow"), WS_OVERLAPPEDWINDOW, nx, ny, nWidth, nHeight, nhWndParent, nhmenu, hInstance, NULL);

	if (NULL == hWnd)
		return false;

	return true;

}

bool MyWindow::MakeWindow(HINSTANCE nhInstance, int dwStyle, int nx, int ny, int nWidth, int nHeight, HWND nhWndParent, HMENU nhmenu) {

	this->hWnd = CreateWindow(wndClass.lpszClassName, TEXT("MyWindow"), WS_OVERLAPPEDWINDOW, nx, ny, nWidth, nHeight, nhWndParent, nhmenu, nhInstance, NULL);

	if (NULL == hWnd)
		return false;

	return true;

}

UINT MyWindow::Run() {	

	IsShowWindow();

	return GameMessageLoop();
}

void MyWindow::IsShowWindow(bool bIsShow) {

	ShowWindow(hWnd, (bIsShow ? SW_SHOW : SW_HIDE));

}

UINT MyWindow::MessageLoop() {

	MSG msg;

	while (GetMessage(&msg, hWnd, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (UINT)msg.wParam;
}

UINT MyWindow::GameMessageLoop() {

	MSG msg;

	while (true) {
		//hWnd값이 nullptr이면 현재 스레드의 전체 윈도우에서의 메시지를 받아옴.
		if (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (true) {
			//TODO : Idle Time에 해야 할 작업 명시

		}
	}


	return (UINT)msg.wParam;
}

LRESULT CALLBACK MyWindow::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	switch (iMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
	
}