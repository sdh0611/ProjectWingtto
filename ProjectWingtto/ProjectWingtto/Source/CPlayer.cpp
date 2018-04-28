#include "../pch.h"
#include "../Include/CPlayer.h"
#include "../Include/Sprite.h"
#include "../Include/Physics.h"
#include "../Include/InputComponent.h"



CPlayer::CPlayer(Types::POINT point, Types::SIZE size)
	:MoveObject(Types::OT_PLAYER, point, size), m_pPhysics(nullptr)
{


}


//CPlayer::CPlayer(float health, Types::ObjectState state)
//	:MoveObject(Types::OT_PLAYER), m_bIsDead(false), m_fHealth(health)
//{
//
//
//}


CPlayer::~CPlayer()
{
	Object::~Object();

}

//Player 클래스 초기화
//상위 클래스에서 HDC에 대한 값을 넘겨받아야함.
//bool CPlayer::Init(const HDC& hDC) {
//
//	if(m_pSprite == nullptr)
//		m_pSprite = new Sprite;
//	
//	if (!m_pSprite->Init(hDC, TEXT("D:/SoucrceTree Repository/ProjectWingtto/ProjectWingtto/Resource/Test.bmp")))
//		return false;
//	
//
//	return true;
//}


bool CPlayer::Init() {

	//SetPosition(0, 0);
	//SetSize(100, 100);
	m_ObjectState = Types::OS_IDLE;
	m_fHealth = 1000.f;
	m_bIsDead = false;

	//if (m_pSprite == nullptr)
	//	m_pSprite = new Sprite;

	//if (!m_pSprite->Init(hDC, TEXT("D:/SoucrceTree Repository/ProjectWingtto/ProjectWingtto/Resource/Test.bmp")))
	//	return false;


	m_pInput = std::unique_ptr<InputComponent>(new InputComponent);
	m_pInput->Init();

	m_pPhysics = std::unique_ptr<Physics>(new Physics);
	m_pPhysics->Init();


	HWND hWnd = FindWindow(TEXT("MyWindow"), TEXT("MyWindowCaption"));
	GetClientRect(hWnd, &m_WndSize);

	return true;
}



void CPlayer::Update(float deltaTime) {

	m_pInput->Update(*this);
	m_pPhysics->Update(*this, deltaTime);
	//Move(deltaTime);
	

}


void CPlayer::Render(float deltaTime, const HDC& hDC) {

	//Object::Render(hDC);
	Rectangle(hDC, m_Position.x, m_Position.y, m_Position.x+100, m_Position.y+100);


}


void CPlayer::Move(float deltaTime) {

	/*if (KEY_DOWN(VK_UP)) {
		if(m_Position.y > 0)
			m_Position.y -= m_fSpeed * deltaTime;

	}
	else if (KEY_DOWN(VK_DOWN)) {
		if (m_Position.y < m_WndSize.bottom)
			m_Position.y += m_fSpeed * deltaTime;
		

	}
	else if (KEY_DOWN(VK_LEFT)) {
		if (m_Position.x > 0)
			m_Position.x -= m_fSpeed * deltaTime;


	}
	else if (KEY_DOWN(VK_RIGHT)) {
		if (m_Position.x < m_WndSize.right)
			m_Position.x += m_fSpeed * deltaTime;


	}
	if (KEY_DOWN(VK_MENU)) {

		

	}
*/



}

//bool CPlayer::DectectCollsion()
//{
//
//
//	return true;
//}
