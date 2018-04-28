#include "../pch.h"
#include "../Include/Sprite.h"
//#include "../Include/MyWindow.h"


Sprite::Sprite()
{

}

Sprite::Sprite(HWND& nhWnd)
	:m_hWnd(nhWnd){

	//m_hDc = GetDC(m_hWnd);

}

Sprite::~Sprite() {

	SelectObject(m_hMemDc, m_hOldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDc);

}

bool Sprite::Draw(HDC hDC, float nx, float ny) {

	BitBlt(m_hMemDc, 0, 0, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_hMemDc, 0, 0, SRCCOPY);
	BitBlt(hDC, nx, ny, m_BitInfo.bmWidth, m_BitInfo.bmHeight, m_hMemDc, 0, 0, SRCCOPY);
	//SelectObject(m_hDC, m_hOldBitmap);
	//DeleteObject(mBitmap);
	
	return true;
}

bool Sprite::Init(HDC hDC, const std::basic_string<TCHAR>& path) {
	
	//TCHAR path[] = TEXT("../Resource/Test.jpg");
	
	m_hMemDc = CreateCompatibleDC(hDC);
	if (!m_hMemDc) {
		DWORD error = GetLastError();
		MessageBox(NULL, TEXT("m_hMemDc 초기화 실패"), TEXT("Init Fail"), MB_ICONERROR | MB_OK);
		return false;
	}
	//int cx, int cy 인자에 0을 넣으면 이미지의 크기를 그대로 가져옴
	m_hBitmap = (HBITMAP)LoadImage(NULL, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (m_hBitmap == NULL) {
		DWORD error = GetLastError();
		MessageBox(NULL, TEXT("이미지 로드 실패"), TEXT("Image Not Exist"), MB_ICONERROR | MB_OK);
		return false;
	}

	//mBitmap정보를 mMemDc에 저장하고 원래 있던 정보는 mOldBitmap에 저장.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDc, m_hBitmap);
	
	//Bitmap 이미지 정보 저장
	GetObject(m_hBitmap, sizeof(m_BitInfo), &m_BitInfo);


	return true;
}