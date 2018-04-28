//	�̹��� ������ ��� �������� Ŭ�������� �� �޽����� ����
//	�̹��� �������� �ǽ��ϴ� ������Ʈ.

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
	//���� ��� ����
	std::basic_string<TCHAR>		m_strSpritePath;
	//�̹����� �׸� �������� �ڵ� ����->�̰� �ʿ������
	HWND							m_hWnd;
	//HDC								m_hDC;
	HDC								m_hMemDc;
	//����� �̹����� ��Ʈ�� ������ ��Ƴ��� �ڵ麯��
	HBITMAP							m_hBitmap;
	//SelectObject�Լ��� ��ȯ���� ������ ���� �ڵ麯��
	HBITMAP							m_hOldBitmap;
	//Bitmap �̹��� ����� ����ü
	BITMAP							m_BitInfo;

};

