//	이미지 정보를 담고 상위계층 클래스에서 온 메시지에 따라
//	이미지 렌더링을 실시하는 컴포넌트.

#pragma once

#include "../pch.h"


class Sprite {
public:
	Sprite();
	Sprite(HWND& nhWnd);
	~Sprite();


public:
	bool Draw(HDC hDC, float nx, float ny);
	bool Init(HDC hDC, const std::basic_string<TCHAR>& path);


private:	



private:
	//파일 경로 저장
	std::basic_string<TCHAR>		m_strSpritePath;
	//이미지를 그릴 윈도우의 핸들 저장->이거 필요없을듯
	HWND							m_hWnd;
	//HDC								m_hDC;
	HDC								m_hMemDc;
	//출력할 이미지의 비트맵 정보를 담아놓는 핸들변수
	HBITMAP							m_hBitmap;
	//SelectObject함수의 반환값을 저장해 놓은 핸들변수
	HBITMAP							m_hOldBitmap;
	//Bitmap 이미지 저장용 구조체
	BITMAP							m_BitInfo;

};

