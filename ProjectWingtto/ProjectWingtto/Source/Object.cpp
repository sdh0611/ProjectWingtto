#include "../pch.h"
#include "../Include/Object.h"
#include "../Include/Sprite.h"
#include "../Include/ColliderBox.h"


Object::Object(Types::ObjectType type, Types::POINT point, Types::SIZE size)
	:m_pSprite(nullptr), m_pCollider(nullptr), m_ObjectType(type), 
	m_ObjectState(Types::OS_IDLE), m_Position(point), m_iSize(size)
{
	
}

Object::~Object() {
		
	SAFE_DELETE(m_pSprite)
	SAFE_DELETE(m_pCollider)

}


//bool Object::Init() {
//
//	//m_pSprite = new Sprite;
//	//if (!m_pSprite->Init())
//	//	return false;
//
//	return true;
//}



void Object::Render(float deltaTime, const HDC& hDC) {

	if (m_pSprite == nullptr) {
		return;
	}

	m_pSprite->Draw(hDC, m_Position.x, m_Position.y);


}
