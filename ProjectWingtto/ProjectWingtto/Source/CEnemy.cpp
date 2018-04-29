#include "../pch.h"
#include "../Include/CEnemy.h"
#include "../Include/Physics.h"
#include "../Include/Sprite.h"


CEnemy::CEnemy(Types::POINT point, Types::SIZE size)
	:MoveObject(Types::OT_ENUMY, point, size), m_pPhysics(nullptr)
{
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Init()


{	//SetPosition(0, 0);
	//SetSize(100, 100);
	m_ObjectState = Types::OS_IDLE;
	m_fHealth = 1000.f;
	m_bIsDead = false;

	//if (m_pSprite == nullptr)
	//	m_pSprite = new Sprite;

	//if (!m_pSprite->Init(hDC, TEXT("D:/SoucrceTree Repository/ProjectWingtto/ProjectWingtto/Resource/Test.bmp")))
	//	return false;
  
	m_pPhysics = new Physics;
	m_pPhysics->Init(this);


	HWND hWnd = FindWindow(TEXT("MyWindow"), TEXT("MyWindowCaption"));
	GetClientRect(hWnd, &m_WndSize);
	return true;
}

void CEnemy::Update(float deltaTime)
{
	if (m_Position.y > 300)
		m_Direction = Types::DIR_UP;
	else if (m_Position.y < 1)
		m_Direction = Types::DIR_DOWN;


	m_pPhysics->Update(deltaTime);
	

}

void CEnemy::Render(float deltaTime, const HDC & hDC)
{

	Rectangle(hDC, m_Position.x, m_Position.y, m_Position.x + 100, m_Position.y + 100);

}
