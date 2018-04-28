#include "../pch.h"
#include "../Include/MyWindow.h"
#include "../Include/SceneManager.h"
#include "../Include/TImer.h"


MyWindow::MyWindow()
	: m_hWnd(nullptr) {

	MessageBox(NULL, TEXT("생성자실행"), TEXT("Info"), MB_ICONINFORMATION);
	ZeroMemory(&m_WndClass, sizeof(m_WndClass));
	ZeroMemory(&m_Msg, sizeof(m_Msg));	

}

MyWindow::~MyWindow(){ 

	MessageBox(NULL, TEXT("소멸자실행"), TEXT("Info"), MB_ICONINFORMATION);
	SceneManager::Destroy();
	SAFE_DELETE(m_pTimer)
	ReleaseDC(m_hWnd, m_hDC);

}

bool MyWindow::Init(HINSTANCE hInst, UINT width, UINT height) {

	m_hInstance = hInst;

	m_iWndWidth = width;
	m_iWndHeight = height;

	if (!InitWndClass())
		return false;
 
	m_hDC = GetDC(m_hWnd);

	//SceneManager 초기화
	//SceneManager->Init()에서 하위계층 클래스들의 초기화도 진행
	//일단 시작씬은 TITLE은 구현 안했으므로 GAME으로 초기화
	//MessageBox(NULL, TEXT("SceneManager Init진입"), TEXT("Info"), MB_ICONINFORMATION);

	if (!SceneManager::GetInstance()->Init(Types::ST_GAME, m_hDC))
		return false;
	//MessageBox(NULL, TEXT("SceneManager Init실행"), TEXT("Info"), MB_ICONINFORMATION);

	m_pTimer = new Timer;
	if (!m_pTimer->Init())
		return false;

	return true;
}

bool MyWindow::InitWndClass() {

	m_WndClass.hInstance = this->m_hInstance;

	m_WndClass.cbClsExtra = 0;
	m_WndClass.cbWndExtra = 0;
	m_WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_WndClass.hCursor = LoadCursor(m_WndClass.hInstance, IDC_ARROW);
	m_WndClass.hIcon = LoadIcon(m_WndClass.hInstance, IDI_APPLICATION);
	m_WndClass.lpfnWndProc = WndProc;
	m_WndClass.lpszClassName = TEXT("MyWindow");
	m_WndClass.lpszMenuName = NULL;
	m_WndClass.style = CS_HREDRAW | CS_VREDRAW;

	if (RegisterClass(&m_WndClass) == 0)
		return false;

	if (!MakeWindow())
		return false;

	return true;

}


bool MyWindow::InitWndClass(std::basic_string<TCHAR> className) {

	m_WndClass.hInstance = this->m_hInstance;

	m_WndClass.cbClsExtra = 0;
	m_WndClass.cbWndExtra = 0;
	m_WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_WndClass.hCursor = LoadCursor(m_WndClass.hInstance, IDC_ARROW);
	m_WndClass.hIcon = LoadIcon(m_WndClass.hInstance, IDI_APPLICATION);
	m_WndClass.lpfnWndProc = WndProc;
	m_WndClass.lpszClassName = className.c_str();
	m_WndClass.lpszMenuName = NULL;
	m_WndClass.style = CS_HREDRAW | CS_VREDRAW;

	if (RegisterClass(&m_WndClass) == 0)
		return false;

	if (!MakeWindow())
		return false;

	return true;

}

bool MyWindow::MakeWindow() {

	this->m_hWnd = CreateWindow(TEXT("MyWindow"), TEXT("MyWindowCaption"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, m_iWndWidth, m_iWndHeight, HWND_DESKTOP, NULL, m_hInstance, NULL);

	if (NULL == m_hWnd) {
		DWORD error = GetLastError();
		MessageBox(NULL, TEXT("CreateWindow Fail.."), TEXT("Error"), MB_ICONWARNING | MB_OK);
		return false;
	}

	IsShowWindow(true);

	return true;

}


UINT MyWindow::MessageLoop() {
		
	while (m_Msg.message != WM_QUIT) {
		//SceneManager::GetInstance()->Render(m_hDC);
		if (PeekMessage(&m_Msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_Msg);
			DispatchMessage(&m_Msg);
		}
		else {
			GameLogic();

		}
		
		
		


	}

	MessageBox(NULL, TEXT("루프 탈출"), TEXT("Info"), MB_ICONINFORMATION);

	return (UINT)m_Msg.wParam;
}

void MyWindow::GameLogic()
{
	m_pTimer->Update();
	m_fDeltaTime = m_pTimer->GetDeltaTIme();
	SceneManager::GetInstance()->Update(m_fDeltaTime);
	SceneManager::GetInstance()->Render(m_fDeltaTime, m_hDC);
	

}

LRESULT CALLBACK MyWindow::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//MyWindow* myWindow = MyWindow::GetInstance();


	switch (iMsg) {
	case WM_DESTROY:
		MessageBox(NULL, TEXT("윈도우 종료"), TEXT("Info"), MB_ICONINFORMATION);
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		HDC hdc;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;
	}

	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

//LRESULT CALLBACK MyWindow::MsgHandle(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
//
//
//
//
//}