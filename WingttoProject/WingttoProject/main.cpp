#include "Pch.h"
#include "MyWIndow.h"


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpszCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hPreInstance);
	UNREFERENCED_PARAMETER(lpszCmdLine);

	MyWindow wnd(hInstance);

	if (!wnd.InitWndClass())
		return -1;

	if(!wnd.MakeWindow())
		return -1;

	return wnd.Run();

}