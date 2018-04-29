//Note(18.04.14) Singleton�� ������ ���� �ٽ� �����غ����ҵ�.
//���� Singleton�� �ᵵ ������ü�� �ϳ���� ������ ����..
// ->  Singleton Class ��� ��ü�� �����ڸ� private���� �������ϴµ�
//		�̰� �ϴϱ� �� ���ٸ��Ѵٰ� �ϴϱ� ����ϳ�
// ->	Friend������ ������ϴ°ǰ�	-> �ϴ� ��ũ�η� friend�����߰�(18.04.14)

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
	MessageBox(NULL, TEXT("Main ����"), TEXT("Info"), MB_ICONINFORMATION);

	MyWindow::Destroy();

	return retValue;

}