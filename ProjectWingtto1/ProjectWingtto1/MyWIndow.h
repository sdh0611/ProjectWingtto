#pragma once

#include "Pch.h"

class MyWindow {
public:
	MyWindow(HINSTANCE hInstance, HWND hWnd = nullptr);
	~MyWindow();


public:
	//bool InitWndClass(int cbClsExtra = 0, int cbWndExtra = 0, std::basic_string<TCHAR> className = "MyWindow",
	//	std::basic_string<TCHAR> menuName = nullptr, UINT classStyle = CS_VREDRAW | CS_HREDRAW);
	bool InitWndClass();
	bool MakeWindow(int dwStyle = WS_OVERLAPPEDWINDOW, int nx = CW_USEDEFAULT, int ny = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT,
		HWND nhWndParent = nullptr, HMENU nhmenu = NULL);
	bool MakeWindow(HINSTANCE nhInstance, int dwStyle = WS_OVERLAPPEDWINDOW, int nx = CW_USEDEFAULT, int ny = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT,
		HWND nhWndParent = nullptr, HMENU nhmenu = NULL);
	UINT Run();
	void IsShowWindow(bool bIsShow = true);
;

private:
	UINT MessageLoop();
	UINT GameMessageLoop();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	WNDCLASS wndClass;
	HWND hWnd;
	HINSTANCE hInstance;

};