#pragma once

#include "../pch.h"


//class GameDirector;

class MyWindow : public Singleton<MyWindow> {

	DECLARE_SINGLETON(MyWindow)

public:
	bool Init(HINSTANCE hInst, UINT width = 800, UINT height = 640);
	//윈도우 표시 여부를 설정하는 메소드.
	inline void IsShowWindow(bool bIsShow){  ShowWindow(m_hWnd, bIsShow ? SW_SHOW : SW_HIDE); }
	//메인 Run 메소드
	UINT MessageLoop();
	//inline HINSTANCE GetHinstance() { return m_hInstance; }
	
public:
	//MyWindow();
	//////MyWindow(HINSTANCE nhInstance);
	//~MyWindow() { };


private:
	//WNDCLASS를 정의하고 등록하는 메소드.
	//오버로딩된 버전들을 제공한다. -> 추후 추가예정
	bool InitWndClass();
	bool InitWndClass(std::basic_string<TCHAR> className);
	//메인 윈도우 생성
	bool MakeWindow();
	//Game의 메인 로직
	void GameLogic();
	//WNDCLASS의 Defalut Callback Procedure
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	//LRESULT CALLBACK MsgHandle(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	class Timer*						m_pTimer;


private:
	UINT								m_iWndWidth;
	UINT								m_iWndHeight;
	WNDCLASS						m_WndClass;				//WNDCLASS 정보 저장
	HINSTANCE						m_hInstance;			//hInstance값 저장
	HWND							m_hWnd;					//메인 윈도우의 핸들값 저장
	HDC								m_hDC;
	MSG								m_Msg;				//메시지 루프를 위한 MSG 인스턴스

private:
	float								m_fDeltaTime;


	//SubSystem Class들
	//얘는 필요없을지도
	//GameDirector					*m_pGameDirector;	//Game의 전체적인 제어를 담당하는 인스턴스.
	
};