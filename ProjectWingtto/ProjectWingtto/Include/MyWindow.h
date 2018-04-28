#pragma once

#include "../pch.h"


//class GameDirector;

class MyWindow : public Singleton<MyWindow> {

	DECLARE_SINGLETON(MyWindow)

public:
	bool Init(HINSTANCE hInst, UINT width = 800, UINT height = 640);
	//������ ǥ�� ���θ� �����ϴ� �޼ҵ�.
	inline void IsShowWindow(bool bIsShow){  ShowWindow(m_hWnd, bIsShow ? SW_SHOW : SW_HIDE); }
	//���� Run �޼ҵ�
	UINT MessageLoop();
	//inline HINSTANCE GetHinstance() { return m_hInstance; }
	
public:
	//MyWindow();
	//////MyWindow(HINSTANCE nhInstance);
	//~MyWindow() { };


private:
	//WNDCLASS�� �����ϰ� ����ϴ� �޼ҵ�.
	//�����ε��� �������� �����Ѵ�. -> ���� �߰�����
	bool InitWndClass();
	bool InitWndClass(std::basic_string<TCHAR> className);
	//���� ������ ����
	bool MakeWindow();
	//Game�� ���� ����
	void GameLogic();
	//WNDCLASS�� Defalut Callback Procedure
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	//LRESULT CALLBACK MsgHandle(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	class Timer*						m_pTimer;


private:
	UINT								m_iWndWidth;
	UINT								m_iWndHeight;
	WNDCLASS						m_WndClass;				//WNDCLASS ���� ����
	HINSTANCE						m_hInstance;			//hInstance�� ����
	HWND							m_hWnd;					//���� �������� �ڵ鰪 ����
	HDC								m_hDC;
	MSG								m_Msg;				//�޽��� ������ ���� MSG �ν��Ͻ�

private:
	float								m_fDeltaTime;


	//SubSystem Class��
	//��� �ʿ��������
	//GameDirector					*m_pGameDirector;	//Game�� ��ü���� ��� ����ϴ� �ν��Ͻ�.
	
};